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
//! \file ti-sfo-v8.c 
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.

// **************************************************************************
// the includes
#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "ti-sfo-v8.h"


// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

// **************************************************************************
// the globals

//=============
// The following declarations are required in order to use the SFO
// library functions:
//
int MEP_ScaleFactor; // Global variable used by the SFO library
                     // Result can be used for all HRPWM channels
                     // This variable is also copied to HRMSTEP
                     // register by SFO() function.

// Array of pointers to EPwm register structures:
// *ePWM[0] is defined as dummy value not used in the example
volatile struct EPWM_REGS *ePWM[PWM_CH] =
             {  &EPwm1Regs, &EPwm1Regs, &EPwm2Regs, &EPwm3Regs, &EPwm4Regs, &EPwm5Regs, &EPwm6Regs, &EPwm7Regs, &EPwm8Regs};
//===========

// **************************************************************************
// the local function prototypes
void PWM_scale_factor_optimizer_error();

// **************************************************************************
// the functions

void PWM_init_scale_factor_optimizer()
{
	int sfo_status = SFO_INCOMPLETE;
	// Calling SFO() updates the HRMSTEP register with calibrated MEP_ScaleFactor.
	// HRMSTEP must be populated with a scale factor value prior to enabling
	// high resolution period control.

	while (sfo_status == SFO_INCOMPLETE){  // Call until complete
		sfo_status = SFO();
		if (sfo_status == SFO_ERROR) {
			PWM_scale_factor_optimizer_error();    // SFO function returns 2 if an error occurs & # of MEP steps/coarse step
		}              // exceeds maximum of 255.
	}
}

void PWM_update_scale_factor_optimizer()
{
	// Call the scale factor optimizer lib function SFO()
	// periodically to track for any change due to temp/voltage.
	// This function generates MEP_ScaleFactor by running the
	// MEP calibration module in the HRPWM logic. This scale
	// factor can be used for all HRPWM channels. The SFO()
	// function also updates the HRMSTEP register with the
	// scale factor value.

	uint16_t status = SFO(); // in background, MEP calibration module continuously updates MEP_ScaleFactor
	if (status == SFO_ERROR) {
		PWM_scale_factor_optimizer_error();   // SFO function returns 2 if an error occurs & # of MEP steps/coarse step
	}              // exceeds maximum of 255.
}

void PWM_scale_factor_optimizer_error()
{
	__asm(" ESTOP0");         // Stop here and handle error
}
