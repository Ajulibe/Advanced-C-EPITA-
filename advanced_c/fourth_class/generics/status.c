/********************************************************************
 *
 * $Id: status.c 1989 2015-10-16 18:19:52Z phil $
 *
 ********************************************************************/
/**
 * Minimal system for error handling.
 *
 * Each value of the "status" enum is associated with an error message.
 * Every function (but some of those returning pointers) should return a
 * status. In the case of non-void functions, the former return value has 
 * to be placed in the parameter list (by address)
 *
 ********************************************************************/

#include "status.h"

/** default error message for unknown errors */
static char* unknownError = "Unknown error";

/** defined error messages */
static char* msg[] = {
  "",
  "File open failed",
  "Access refused",
  "File close failed",
  "Memory allocation failed",
  "Wrong date",
  "Full structure",
  "Empty structure",
  "Value not found",
  "Value already exists",
  "index out of bounds",
  "unable to perform operation",
  "unknown error"
};

/** get message associated with the given status value (O(1)).
 * @param s the status value
 * @return the associated message
 */
char* message(status s) {
  return (s<0 || s >= ERRUNKNOWN) ? msg[ERRUNKNOWN] : msg[s];
}

/**
when a variable is defined as static it
will only be seen in the compilation unit hwhere it is defined
*/
