/*
*****************************************************************
                          COPYRIGHT NOTIFICATION
*****************************************************************

THE FOLLOWING IS A NOTICE OF COPYRIGHT, AVAILABILITY OF THE CODE,
AND DISCLAIMER WHICH MUST BE INCLUDED IN THE PROLOGUE OF THE CODE
AND IN ALL SOURCE LISTINGS OF THE CODE.

(C)  COPYRIGHT 1993 UNIVERSITY OF CHICAGO

Argonne National Laboratory (ANL), with facilities in the States of
Illinois and Idaho, is owned by the United States Government, and
operated by the University of Chicago under provision of a contract
with the Department of Energy.

Portions of this material resulted from work developed under a U.S.
Government contract and are subject to the following license:  For
a period of five years from March 30, 1993, the Government is
granted for itself and others acting on its behalf a paid-up,
nonexclusive, irrevocable worldwide license in this computer
software to reproduce, prepare derivative works, and perform
publicly and display publicly.  With the approval of DOE, this
period may be renewed for two additional five year periods.
Following the expiration of this period or periods, the Government
is granted for itself and others acting on its behalf, a paid-up,
nonexclusive, irrevocable worldwide license in this computer
software to reproduce, prepare derivative works, distribute copies
to the public, perform publicly and display publicly, and to permit
others to do so.

*****************************************************************
                                DISCLAIMER
*****************************************************************

NEITHER THE UNITED STATES GOVERNMENT NOR ANY AGENCY THEREOF, NOR
THE UNIVERSITY OF CHICAGO, NOR ANY OF THEIR EMPLOYEES OR OFFICERS,
MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL
LIABILITY OR RESPONSIBILITY FOR THE ACCURACY, COMPLETENESS, OR
USEFULNESS OF ANY INFORMATION, APPARATUS, PRODUCT, OR PROCESS
DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT INFRINGE PRIVATELY
OWNED RIGHTS.

*****************************************************************
LICENSING INQUIRIES MAY BE DIRECTED TO THE INDUSTRIAL TECHNOLOGY
DEVELOPMENT CENTER AT ARGONNE NATIONAL LABORATORY (708-252-2000).
*/
/*****************************************************************************
 *
 *     Original Author : Mark Andersion
 *     Current Author  : Frederick Vong
 *
 * Modification Log:
 * -----------------
 * .01  03-01-95        vong    2.0.0 release
 *
 *****************************************************************************
*/

/****************************************************************************
 ***                             parse.h                                  ***
 ****************************************************************************/

#ifndef __PARSE_H__
#define __PARSE_H__

/*
 * types for parsing
 */
typedef enum 
   { T_WORD, T_EQUAL, T_QUOTE, T_LEFT_BRACE, T_RIGHT_BRACE, T_EOF} TOKEN;


/*
 * position element at tail of display list or composite list...
 *   (referenced in parse*.c files)
 */

#define POSITION_ELEMENT_ON_LIST() \
  if (dlComposite != (DlComposite *)NULL) {				\
   dlElement->prev = (DlElement *)(dlComposite->dlElementListTail);	\
   if ( ((DlElement *)dlComposite->dlElementListHead)->next == NULL) {	\
     ((DlElement *)dlComposite->dlElementListHead)->next = dlElement;	\
     dlComposite->dlElementListTail = (XtPointer)dlElement;		\
   } else {								\
     ((DlElement *)dlComposite->dlElementListTail)->next = dlElement;	\
   }									\
   dlComposite->dlElementListTail = (XtPointer)dlElement;		\
  } else {								\
   dlElement->prev = displayInfo->dlElementListTail;			\
   ((DlElement *)displayInfo->dlElementListTail)->next = dlElement;	\
   displayInfo->dlElementListTail = dlElement;				\
  }


#endif  /* __PARSE_H__ */
