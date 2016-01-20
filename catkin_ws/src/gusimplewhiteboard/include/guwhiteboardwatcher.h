/*
 *  guwhiteboardwatcher.h
 *
 *  Created by Carl Lusty in 2013.
 *  Copyright (c) 2013 Carl Lusty
 *  All rights reserved.
 */

#ifndef GENERIC_WB_WATCHER_H
#define GENERIC_WB_WATCHER_H

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunused-value"

#include "gusimplewhiteboard.h"
#include "WBFunctor.h"
#include <iostream> //cerr
#include <cstdio> //stderr etc..
#include <list> //local sub std::list

#ifdef bool
#undef bool
#endif

#ifdef true
#undef true
#undef false
#endif

#include <dispatch/dispatch.h>

#define DISPATCH_QUEUE_NAME_WB "guWhiteboard"

#ifndef DISPATCH_QUEUE_SERIAL
#define DISPATCH_QUEUE_SERIAL NULL
#endif

#define SUBSCRIBE(wb, t, c, f) ((wb)->subscribe(t ## _WBFunctor<c>::bind(this, &f, k##t ## _v)))

extern gu_simple_whiteboard_descriptor *local_whiteboard_descriptor;

static void subscription_callback(gu_simple_whiteboard_descriptor *wbd);

/**
 * @brief An internal stuct for passing callback information to dispatch queues
 */
struct callback_helper //struct passed to do_callback
{
        gu_simple_whiteboard *wb;	///< wb pointer
        WBFunctorBase *f;		///< callback functor pointer
        int offs;			///< type offset in shared memory, aka type enum value
        uint16_t t_overwrite;		///< the type offset / enum value to 'fake' see comment for 'use_type_overwrite'
        bool use_type_overwrite; 	///< use the type overwrite of WBFunctor (used by the simpleposter to 'fake' messages without a huge amount of generated code)
        uint8_t gen_to_use; 		///< the message generation slot that contains the data for this callback 

	/** Constructor */
        callback_helper(gu_simple_whiteboard *w, int o, WBFunctorBase *d, uint16_t t, bool use_t, uint8_t gen): wb(w), f(d), offs(o), t_overwrite(t), use_type_overwrite(use_t), gen_to_use(gen) {}
};

static void do_callback(void *m) //makes the callback call, via GCD queue
{
        callback_helper *h = static_cast<callback_helper *>(m);
        
        if(h->use_type_overwrite)
                h->f->call(static_cast<guWhiteboard::WBTypes>(h->t_overwrite), &h->wb->messages[h->offs][h->gen_to_use]);
        else
                h->f->call(&h->wb->messages[h->offs][h->gen_to_use]);
        delete h;
}

/**
* @brief This class provides a subscription implementation for the 'simple' whiteboard, aka the 'typed' whiteboard.
*
* This class allows you to 'subscribe' to changes on the Whiteboard. Specifically call you can call the subscribe method, with the desired 'type' and a callback pointer. This class will monitor any subscribed 'types' and call the callback functions when the data related to those 'types' is updated. To be clear, callbacks will be issued if the data is updated on the Whiteboard, even if it is the same data. The act of the data being posted to the Whiteboard is what triggers callbacks. This is designed for event-triggered systems and different data fetching methods should be used for time-triggered systems.
*
* Examples
* --------
*
* ###A SUBSCRIBE macro is defined for convenience
*
*     wb = new whiteboard_watcher(); //create the watcher object
*     //wb = whiteboard_watcher
*     //Say = the WB type to subscribe to
*     //GUNaoSpeech = the class the callback belongs to
*     //GUNaoSpeech::whiteboard_callback = the callback function
*     SUBSCRIBE(wb, Say, GUNaoSpeech, GUNaoSpeech::whiteboard_callback);
*
* ###The long form of the subscribe looks like this:
*
*     wb = new whiteboard_watcher(); //create the watcher object
*     ((wb)->subscribe(Say_WBFunctor<GUNaoSpeech>::bind(this, &GUNaoSpeech::whiteboard_callback, kSay_v)));
*
 */
class whiteboard_watcher
{
        gu_simple_whiteboard_descriptor         *_wbd;
        std::list<WBFunctorBase *>              _sub;
        dispatch_group_t                        callback_group;                                 // wait for all callbacks to have finished
        dispatch_queue_t                        callback_queue;                                 // subscription callback queue
        u_int16_t                               local_event_counters[GSW_TOTAL_MESSAGE_TYPES];  // local event counter for all types, used by the global subscription
        
public:
	/**
	 * @brief Constructor, sets up the dispatch queues for handling callbacks
	 * @param wbd You can pass a specific pointer to a whiteboard object if you wish. By default a pointer to the default whiteboard is used.
	 */
        whiteboard_watcher(gu_simple_whiteboard_descriptor *wbd = NULL) //Constructor
        {
                _wbd = wbd;
                if(!_wbd)
                {
			_wbd = get_local_singleton_whiteboard();
                }
                
                
                if (!(callback_group = dispatch_group_create()))
                {
                        std::cerr << "Unable to create dispatch group" << std::endl;
                        throw "Whiteboard cannot create callback queue";
                }
                if (!(callback_queue = dispatch_queue_create(DISPATCH_QUEUE_NAME_WB, DISPATCH_QUEUE_SERIAL)))
                {
                        std::cerr << "Unable to create dispatch queue" << std::endl;
                        throw "Whiteboard cannot create dispatch queue";
                }
                
                _wbd->context = this;
                _wbd->callback = subscription_callback;
        }

	/**
	 * @brief Destructor, release whiteboard objects and dispatch queues.
	 */
	~whiteboard_watcher()
	{
		_wbd->exit_monitor = true;
	        _wbd->callback = NULL;                  // avoid starvation
       		dispatch_group_wait(callback_group, DISPATCH_TIME_FOREVER);

      		if (_wbd) gsw_free_whiteboard(_wbd);
#if !defined(__clang__)
#ifndef __has_feature
#define __has_feature(x)	0
#endif
#endif
#if !__has_feature(objc_arc)
        	dispatch_release(callback_queue);
       	 	dispatch_release(callback_group);
#endif
	}
        
	/**
	 * @brief Allows you to subscribe to a specific whiteboard type and get callbacks when that type is updated. You will still get a callback if the type is updated and the data didn't change.
	 * @param func the callback container object. I suggest using the macro SUBSCRIBE (see example at the top of this file)
	 */
        void subscribe(WBFunctorBase *func)
        {
                if(!func->is_simple_wb_version())
                {
                        fprintf(stderr, "whiteboard_watcher: Only use WB_BIND for the original Whiteboard class, for the simplewhiteboard watcher please use WB_TYPE_BIND(type const enum, function pointer). This is not optional, exiting...\n");
                        exit(1);
                }
                
                gsw_procure(_wbd->sem, GSW_SEM_CALLBACK);
        
                func->set_event_count(_wbd->wb->event_counters[func->type()]);
                _sub.push_back(func); //Kept locally for actually making the callbacks
                
                if (func->type() == guWhiteboard::kwb_reserved_SubscribeToAllTypes_v)
                {
                        for (int i = 0; i < GSW_TOTAL_MESSAGE_TYPES; i++) //get current event counts for all types
                        {
                                if(_wbd->wb->event_counters[i] > 0)
                                        local_event_counters[i] = _wbd->wb->event_counters[i]; //Already set to zeros in wb constructor memset
                        }
                }
                
                gsw_vacate(_wbd->sem, GSW_SEM_CALLBACK);
                
                gsw_add_wbd_signal_handler(_wbd);
                gsw_add_process(_wbd, getpid());
        }

	/**
	 * @brief Stop getting callbacks for a particular whiteboard type
	 * @param t the type to unsubscribe from
	 */
        void unsubscribe(guWhiteboard::WBTypes t)
        {
                gsw_procure(_wbd->sem, GSW_SEM_CALLBACK);
                
                for (std::list<WBFunctorBase *>::iterator i = _sub.begin(); i != _sub.end(); i++)
                {
                        WBFunctorBase *f = *i;
                        guWhiteboard::WBTypes offs = f->type();
                        if (offs == t)
                        {
                                _sub.erase(i);
                                break;
                        }
                }
                if (!_sub.size()) gsw_remove_process(_wbd, getpid());
                
                gsw_vacate(_wbd->sem, GSW_SEM_CALLBACK);
        }

	/**
	 * @brief Internal function, this is what gets triggered by the underlying whiteboard, it then checks its list of subscribed types and issues callback functions to subscribed modules.
	 */
        void receive_callback()
        {
                static int lastmsg;
                gu_simple_whiteboard *wb = _wbd->wb;
                gsw_procure(_wbd->sem, GSW_SEM_CALLBACK);
                for (std::list<WBFunctorBase *>::iterator i = _sub.begin(); i != _sub.end(); i++)
                {
                        WBFunctorBase *f = *i;
                        int offs = static_cast<int>(f->type());
                        uint16_t event_count = f->get_event_count();
                        
                        /*
                         * offs == -1 means all types "*", otherwise only check
                         * new postings for a specific message type
                         */
                        if (f->type() == guWhiteboard::kwb_reserved_SubscribeToAllTypes_v)
                                for (int e = 0; e < GSW_TOTAL_MESSAGE_TYPES; e++)      // check all message type event counters
                                {
                                        if (local_event_counters[e] != wb->event_counters[e]) //check for new event using event counters
                                        {
                                                if(local_event_counters[e]+1 != wb->event_counters[e])
                                                {
                                                        fputc('*', stderr);
                                                        if (lastmsg != e)
                                                                fprintf(stderr, " @%d\n", e);
                                                        lastmsg = e;
                                                }
                                                local_event_counters[e] = wb->event_counters[e];
                                                uint16_t t_overwrite = uint16_t(e);
                                                callback_helper *h = new callback_helper(wb, e, f, t_overwrite, true, wb->indexes[e]);
                                                dispatch_group_async_f(callback_group, callback_queue, h, do_callback);
                                        }
                                }
                        else
                                if (event_count != wb->event_counters[offs]) //check for new event using event counters
                                {
                                        if(event_count+1 != wb->event_counters[offs])
                                        {
                                                fputc('*', stderr);
                                                if (lastmsg != offs)
                                                        fprintf(stderr, " @%d\n", offs);
                                                lastmsg = offs;
                                        }
                                        f->set_event_count(wb->event_counters[offs]);
                                        callback_helper *h = new callback_helper(wb, offs, f, 0, false, wb->indexes[offs]);
                                        dispatch_group_async_f(callback_group, callback_queue, h, do_callback);
                                }
                }
                gsw_vacate(_wbd->sem, GSW_SEM_CALLBACK);
        }
};

/**
 * @brief Internal function, the callback 'trigger' from the underlying whiteboard. Simply gets the current watcher, casts it correctly and calls a similar internal function which gets us back into the whiteboard_watcher class scope.
 * @param wbd The underlying whiteboard pointer
 */
static void subscription_callback(gu_simple_whiteboard_descriptor *wbd) //called by simplewhiteboard whenever the global event count increases
{
        whiteboard_watcher *self = static_cast<whiteboard_watcher *>(wbd->context);
        if (self) self->receive_callback();
}


#endif //GENERIC_WB_WATCHER_H
