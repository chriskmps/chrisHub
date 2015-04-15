
/* intList.h
Header file for intList.c
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
The preconditions for the access functions are that they all take in a type IntList as their argument
in the case of intCons, it also takes in a type int as its argument
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

