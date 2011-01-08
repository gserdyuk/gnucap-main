/***************************************************************************
JSPICE3 adaptation of Spice3f2 - Copyright (c) Stephen R. Whiteley 1992
Copyright 1990 Regents of the University of California.  All rights reserved.
Authors: 1990 Jaijeet S. Roychowdhury
         1993 Stephen R. Whiteley
****************************************************************************/

/*
 * This routine sets model parameters for
 * LTRA lines in the circuit.
 */

#include "spice.h"
#include <stdio.h>
#include <math.h>
#include "ltradefs.h"
#include "const.h"
#include "sperror.h"
#include "util.h"


int
LTRAmParam(param,value,inModel)

int param;
IFvalue *value;
GENmodel *inModel;
{
    LTRAmodel *mods = (LTRAmodel*)inModel;

    switch (param) {

        case LTRA_MOD_LTRA:
            break;
        case LTRA_MOD_R:
            mods->LTRAresist = value->rValue;
            mods->LTRAresistGiven = TRUE;
            break;
        case LTRA_MOD_L:
            mods->LTRAinduct = value->rValue;
            mods->LTRAinductGiven = TRUE;
            break;
        case LTRA_MOD_G:
            mods->LTRAconduct = value->rValue;
            mods->LTRAconductGiven = TRUE;
            break;
        case LTRA_MOD_C:
            mods->LTRAcapac = value->rValue;
            mods->LTRAcapacGiven = TRUE;
            break;
        case LTRA_MOD_LEN:
            mods->LTRAlength = value->rValue;
            mods->LTRAlengthGiven = TRUE;
            break;
        case LTRA_MOD_RELTOL:
            mods->LTRAreltol = value->rValue;
            mods->LTRAreltolGiven = TRUE;
            break;
        case LTRA_MOD_ABSTOL:
            mods->LTRAabstol = value->rValue;
            mods->LTRAabstolGiven = TRUE;
            break;
        case LTRA_MOD_NOCONTROL:
            mods->LTRAlteConType = LTRA_MOD_NOCONTROL;
            break;
        case LTRA_MOD_HALFCONTROL:
            mods->LTRAlteConType = LTRA_MOD_HALFCONTROL;
            break;
        case LTRA_MOD_FULLCONTROL:
            mods->LTRAlteConType = LTRA_MOD_FULLCONTROL;
            break;
        case LTRA_MOD_STEPLIMIT:
            mods->LTRAstepLimit = LTRA_MOD_STEPLIMIT;
            break;
        case LTRA_MOD_NOSTEPLIMIT:
            mods->LTRAstepLimit = LTRA_MOD_NOSTEPLIMIT;
            break;
        case LTRA_MOD_LININTERP:
            mods->LTRAhowToInterp = LTRA_MOD_LININTERP;
            break;
        case LTRA_MOD_QUADINTERP:
            mods->LTRAhowToInterp = LTRA_MOD_QUADINTERP;
            break;
        case LTRA_MOD_MIXEDINTERP:
            mods->LTRAhowToInterp = LTRA_MOD_MIXEDINTERP;
            break;
        case LTRA_MOD_TRUNCNR:
            mods->LTRAtruncNR = TRUE;
            break;
        case LTRA_MOD_TRUNCDONTCUT:
            mods->LTRAtruncDontCut = TRUE;
            break;
        case LTRA_MOD_STLINEREL:
            mods->LTRAstLineReltol = value->rValue;
            break;
        case LTRA_MOD_STLINEABS:
            mods->LTRAstLineAbstol = value->rValue;
            break;
        /*
        case LTRA_MOD_CHOPREL:
            mods->LTRAchopReltol = value->rValue;
            break;
        case LTRA_MOD_CHOPABS:
            mods->LTRAchopAbstol = value->rValue;
            break;
        */
        default:
            return (E_BADPARM);
    }
    return (OK);
}
