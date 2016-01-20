/* MiPAL 2010
Author: Tyrone Trevorrow, Carl Lusty, and Rene Hexel
Purpose: Provides a more generic mechanism for function callbacks.
		 Feel free to extend this to support any function's parameter lists.
 Change Log:
        21/1/2013 - Extended to add simple wb compatability, Carl.
*/
#ifndef WBFUNCTOR_H
#define WBFUNCTOR_H

#ifdef bool
#undef bool
#endif

#ifdef true
#undef true
#undef false
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wpadded"

#include <string>

#include "WBMsg.h"
#include "guwhiteboardtypelist_generated.h" //for type enum
#include "gusimplewhiteboard.h" //for gu_simple_message

#define WB_BIND( f ) createWBFunctor(this, &f)
#define WB_TYPE_BIND( t, f ) createWBFunctor(this, &f, t)

/**
 * @brief Base class for WBFunctor 
 *
 * This class provides outlines the interface for WBFunctor. It is designed to assist with managing callbacks
*/     
class WBFunctorBase
{
public:
	/**
 	* Call method for the OLD whiteboard callbacks that used WBMsg - Deprecated
	* @param s type string value
	* @param m WBMsg data value
	*/
	virtual void call(std::string s, WBMsg* m) = 0;                         //old wbmsg format for callbacks

	/**
 	* Call method for the 'simple' whiteboard aka 'typed whiteboard' callbacks that passes data around in a union
	* @param m data value
	*/
	virtual void call(gu_simple_message* m) = 0;                            //new simple_message callbacks

	/**
 	* Call method for the 'simple' whiteboard aka 'typed whiteboard' callbacks that passes data around in a union. This version allows a 'type' overwrite. This is mostly used by the 'whiteboard poster' to impersonate other message types.
	* @param t whiteboard 'type' 
	* @param m data value
	*/
	virtual void call(guWhiteboard::WBTypes t, gu_simple_message* m) = 0;   //new simple_message callbacks (with type overwrite for subscribe to all special type)

	/** getter for the WB type */
        virtual guWhiteboard::WBTypes type() = 0;

	/** getter for the WB event counter */
        virtual uint16_t get_event_count() = 0;

	/** 
	* setter for the WB event counter 
	* @param e new event counter value
	*/
        virtual void set_event_count(uint16_t e) = 0;

	/** is this being used by the 'simple whiteboard' or the OLD whiteboard (which is now Deprecated) */
        virtual bool is_simple_wb_version() = 0;

	/** destructor */
	virtual ~WBFunctorBase(){}
};

/**
 * @brief WBFunctor callback manager class 
 *
 * This class allows you to pass a function pointer for callbacks
*/
template <typename C>
class WBFunctor: public WBFunctorBase
{
public:
	/**
 	* WBFunctor Constructor
	*/
	WBFunctor(C* obj, void (C::*pFunc) (std::string, WBMsg*)):
		fObject(obj), fFunction(pFunc), simple_wb_version(false) { }

	/**
 	* WBFunctor Constructor
	*/
	WBFunctor(C* obj, void (C::*pFunc) (guWhiteboard::WBTypes, gu_simple_message*), guWhiteboard::WBTypes t):
                fObject(obj), s_fFunction(pFunc), type_enum(t), event_count(0), simple_wb_version(true) { }

	/**
 	* Call method for the OLD whiteboard callbacks that used WBMsg - Deprecated
	* @param s type string value
	* @param m WBMsg data value
	*/
	void call(std::string s, WBMsg* m)
	{
		(fObject->*fFunction)(s,m);
	}

	/**
 	* Call method for the 'simple' whiteboard aka 'typed whiteboard' callbacks that passes data around in a union
	* @param m data value
	*/
	void call(gu_simple_message* m)
	{
		(fObject->*s_fFunction)(type_enum, m);
	}

	/**
 	* Call method for the 'simple' whiteboard aka 'typed whiteboard' callbacks that passes data around in a union. This version allows a 'type' overwrite. This is mostly used by the 'whiteboard poster' to impersonate other message types.
	* @param t whiteboard 'type' 
	* @param m data value
	*/
	void call(guWhiteboard::WBTypes t, gu_simple_message* m)
	{
		(fObject->*s_fFunction)(t, m);
	}

	/** getter for the WB type */
	guWhiteboard::WBTypes type() { return type_enum; }

	/** getter for the WB event counter */
	uint16_t get_event_count() { return event_count; }

	/** 
	* setter for the WB event counter 
	* @param e new event counter value
	*/
	void set_event_count(uint16_t e) { event_count = e; }

	/** is this being used by the 'simple whiteboard' or the OLD whiteboard (which is now Deprecated) */
	bool is_simple_wb_version() { return simple_wb_version; }

	/** function prototype for the new 'simple whiteboard' callbacks */
	typedef void (C::*s_func) (guWhiteboard::WBTypes, gu_simple_message*); //simple wb implementation

	/** getter */
	s_func get_s_func_ptr() { return s_fFunction; }

protected:
	C* fObject; ///< ptr to call containing the callback method
	typedef void (C::*func) (std::string, WBMsg*); ///< OLD function prototype (which is now Deprecated)
	func fFunction; ///< OLD function object
	s_func s_fFunction; ///< 'simple' function object
	guWhiteboard::WBTypes type_enum; ///< 'simple' whiteboard types
	uint16_t event_count; ///< the event counter
	bool simple_wb_version; ///< flag, is this a 'simple' whiteboard usage of WBFunctor
};

template <typename C>
WBFunctorBase* createWBFunctor(C *obj, void (C::*f) (std::string, WBMsg*))
{
	return new WBFunctor<C>(obj, f);
}
template <typename C>
WBFunctorBase* createWBFunctor(C *obj, void (C::*f) (guWhiteboard::WBTypes, gu_simple_message*), guWhiteboard::WBTypes t)
{
	return new WBFunctor<C>(obj, f, t);
}

#pragma clang diagnostic pop

#include "WBFunctor_types_generated.h"

#endif
