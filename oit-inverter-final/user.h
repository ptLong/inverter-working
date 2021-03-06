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

#ifndef _USER_H_
#define _USER_H_

//! \file user.h 
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.


// **************************************************************************
// the includes



//!
//!
//! \defgroup _USER_H_
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// **************************************************************************
// the defines

//! \brief Define the minimum pulse width for high and low mosfet
//!
#define USER_PWM_MIN_PULSE_WIDTH_HIGHFET_NS	(38)
#define USER_PWM_MIN_PULSE_WIDTH_LOWFET_NS	(28)

//! \brief Define LED GPIO
//!
#define GPIO_LED_BLUE	(GPIO_Number_13)
#define GPIO_LED_WHITE	(GPIO_Number_14)

//! \brief Define Low frequency mosfets GPIO
//!
#define GPIO_LOWFREQMOSFET_HIGH	(GPIO_Number_6)
#define GPIO_LOWFREQMOSFET_LOW	(GPIO_Number_7)

//! \brief Define CPU frequency and main interrupt service routine frequency
//!
#define CPU_FREQ_MHZ		(200)
#define MAIN_ISR_FREQ_KHZ	(10)

// **************************************************************************
// the typedefs

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _USER_H_ definition
