#ifndef Angle_DEFINED
#define Angle_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <gu_util.h>
#include "gusimplewhiteboard.h"
#include "wb_angle.h"

namespace guWhiteboard {

  /** Angle Class */
  class Angle: public wb_angle {

    public:
      Angle() : wb_angle() {}
      Angle(const std::string &name) : wb_angle(std::string(name)) {}

// Primitive/Native/Implicit/Mandatory functions are defined in the wb_ class.
// This includes:
//    ALL the necessary constructors (Default, Copy, Assign, String)
//    "to_string()"   (which gives a comma/parenthesis/bracket separated string)
//    "from_string()" (performs the actual initialisation of the object from a string.  It is the companion of "to_string()")
//    "description()" (human readable version of to_string)
//
//
//  Methods that make this class distinctive from the base class are to be defined here.
//  For example: unit scaling, conversions between units of measure, and other convenience methods.
//
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

  };
};
#endif // Angle_DEFINED
