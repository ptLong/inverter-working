/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Oregon Tech
 * Some rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Oregon Tech nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT-- */
//! \file ctrl.c 
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.

// **************************************************************************
// the includes

#include "ctrl.h"
#include "user.h"
#include "oit-gpio.h"


// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

// **************************************************************************
// the globals

// **************************************************************************
// the local function prototypes

// **************************************************************************
// the functions

CTRL_Handle CTRL_init(void *pMemory,const size_t numBytes)
{
	CTRL_Handle handle;
	//CTRL_Obj *obj;


	if(numBytes < sizeof(CTRL_Obj))
		return((CTRL_Handle)NULL);


	// assign the handle
	handle = (CTRL_Handle)pMemory;


//	// set the version
//	CTRL_setVersion(handle,CTRL_TargetProc_2806x,
//			CTRL_MAJOR_RELEASE_NUMBER,CTRL_MINOR_RELEASE_NUMBER);


	// assign the object
	//obj = (CTRL_Obj *)handle;


//	// initialize the Id PI controller module
//	obj->piHandle_Id = PI_init(&obj->pi_Id,sizeof(obj->pi_Id));
//
//
//	// initialize the Iq PI controller module
//	obj->piHandle_Iq = PI_init(&obj->pi_Iq,sizeof(obj->pi_Iq));
//
//
//	// initialize the speed PI controller module
//	obj->piHandle_spd = PI_init(&obj->pi_spd,sizeof(obj->pi_spd));

	return(handle);
} // end of CTRL_init() function

void CTRL_setDefaultParams(CTRL_Handle handle)
{
	CTRL_Obj *obj = (CTRL_Obj *)handle;

//	obj->lowFreq_mosfet_high = GPIO_LOWFREQMOSFET_HIGH;
//	obj->lowFreq_mosfet_low  = GPIO_LOWFREQMOSFET_LOW;

	
	obj->sinCycleState     = CTRL_SinCycleState_Positive;

}



