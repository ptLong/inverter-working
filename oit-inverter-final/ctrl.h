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

#ifndef _CTRL_H_
#define _CTRL_H_

//! \file ctrl.h 
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.


// **************************************************************************
// the includes

#include "oit-types.h"
#include "ctrl_obj.h"

//!
//!
//! \defgroup _CTRL_H_
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

//! \brief     Initializes the controller
//! \param[in] pMemory   A pointer to the memory for the controller object
//! \param[in] numBytes  The number of bytes allocated for the controller object, bytes
//! \return    The controller (CTRL) object handle
CTRL_Handle CTRL_init(void *pMemory,const size_t numBytes);

//! \brief      Sets the controller parameters
//! \details    This function allows for updates in scale factors during real-time
//!             operation of the controller.
//! \param[in]  handle       The controller (CTRL) handle
void CTRL_setDefaultParams(CTRL_Handle handle);


//! \brief
//! \param[in]  handle  The controller (CTRL) handle
inline void CTRL_setNextSinCycleState(CTRL_Handle handle, const CTRL_SinCycleState_e state)
{
	CTRL_Obj *obj = (CTRL_Obj *)handle;
	
	obj->nextSinCycleState = state;
}


//! \brief
//! \param[in]  handle  The controller (CTRL) handle
inline CTRL_SinCycleState_e CTRL_getNextSinCycleState(CTRL_Handle handle)
{
	CTRL_Obj *obj = (CTRL_Obj *)handle;

	return (obj->nextSinCycleState);
}

//! \brief
//! \param[in]  handle  The controller (CTRL) handle
inline void CTRL_setCurrentSinCycleState(CTRL_Handle handle, const CTRL_SinCycleState_e state)
{
	CTRL_Obj *obj = (CTRL_Obj *)handle;
	
	obj->sinCycleState = state;
}


//! \brief
//! \param[in]  handle  The controller (CTRL) handle
inline CTRL_SinCycleState_e CTRL_getCurrentSinCycleState(CTRL_Handle handle)
{
	CTRL_Obj *obj = (CTRL_Obj *)handle;

	return (obj->sinCycleState);
}



//! \brief
//! \param[in]  handle  The controller (CTRL) handle
inline void CTRL_doChangeSinCycleState(CTRL_Handle handle, const CTRL_SinCycleState_e state)
{
	//TODO: assert current sincycle state != next sin cycle state
	CTRL_Obj *obj = (CTRL_Obj *)handle;

	if(state == CTRL_SinCycleState_Negative){
//		GPIO_setLow(obj->lowFreq_mosfet_low);
//		//delay for 500ns
//		GPIO_setHigh(obj->lowFreq_mosfet_high);
		EPwm4Regs.CMPA.bit.CMPA = 0xffff;
	}else if(state == CTRL_SinCycleState_Positive){
//		GPIO_setLow(obj->lowFreq_mosfet_high);
//		//delay for 500ns
//		GPIO_setHigh(obj->lowFreq_mosfet_low);
		EPwm4Regs.CMPA.all = 0;

	}
	
	obj->sinCycleState = state;
}



#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _CTRL_H_ definition
