/***************************************************************************
JSPICE3 adaptation of Spice3f2 - Copyright (c) Stephen R. Whiteley 1992
Copyright 1990 Regents of the University of California.  All rights reserved.
Authors: 1985 Hong June Park, Thomas L. Quarles
         1993 Stephen R. Whiteley
****************************************************************************/

#include "spice.h"
#include <stdio.h>
#include <math.h>
#include "bsim2def.h"
#include "sperror.h"
#include "cktext.h"


int
B2trunc(inModel,ckt,timeStep)
    GENmodel *inModel;
    register CKTcircuit *ckt;
    double *timeStep;

{
    register B2model *model = (B2model*)inModel;
    register B2instance *here;
#ifdef STEPDEBUG
    double debugtemp;
#endif /* STEPDEBUG */

    for( ; model != NULL; model = model->B2nextModel) {
        for(here=model->B2instances;here!=NULL;here = here->B2nextInstance){
#ifdef STEPDEBUG
            debugtemp = *timeStep;
#endif /* STEPDEBUG */
            CKTterr(here->B2qb,ckt,timeStep);
            CKTterr(here->B2qg,ckt,timeStep);
            CKTterr(here->B2qd,ckt,timeStep);
#ifdef STEPDEBUG
            if(debugtemp != *timeStep) {
                printf("device %s reduces step from %g to %g\n",
                        here->B2name,debugtemp,*timeStep);
            }
#endif /* STEPDEBUG */
        }
    }
    return(OK);
}


