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

#ifndef _OIT_GPIO_H_
#define _OIT_GPIO_H_

//! \file oit-gpio.h 
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


//!
//!
//! \defgroup _OIT_GPIO_H_
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

//! \brief Enumeration to define the general purpose I/O (GPIO) numbers
//!
typedef enum
{
  GPIO_Number_0=0,    //!< Denotes GPIO number 0
  GPIO_Number_1,      //!< Denotes GPIO number 1
  GPIO_Number_2,      //!< Denotes GPIO number 2
  GPIO_Number_3,      //!< Denotes GPIO number 3
  GPIO_Number_4,      //!< Denotes GPIO number 4
  GPIO_Number_5,      //!< Denotes GPIO number 5
  GPIO_Number_6,      //!< Denotes GPIO number 6
  GPIO_Number_7,      //!< Denotes GPIO number 7
  GPIO_Number_8,      //!< Denotes GPIO number 8
  GPIO_Number_9,      //!< Denotes GPIO number 9
  GPIO_Number_10,     //!< Denotes GPIO number 10
  GPIO_Number_11,     //!< Denotes GPIO number 11
  GPIO_Number_12,     //!< Denotes GPIO number 12
  GPIO_Number_13,     //!< Denotes GPIO number 13
  GPIO_Number_14,     //!< Denotes GPIO number 14
  GPIO_Number_15,     //!< Denotes GPIO number 15
  GPIO_Number_16,     //!< Denotes GPIO number 16
  GPIO_Number_17,     //!< Denotes GPIO number 17
  GPIO_Number_18,     //!< Denotes GPIO number 18
  GPIO_Number_19,     //!< Denotes GPIO number 19
  GPIO_Number_20,     //!< Denotes GPIO number 20
  GPIO_Number_21,     //!< Denotes GPIO number 21
  GPIO_Number_22,     //!< Denotes GPIO number 22
  GPIO_Number_23,     //!< Denotes GPIO number 23
  GPIO_Number_24,     //!< Denotes GPIO number 24
  GPIO_Number_25,     //!< Denotes GPIO number 25
  GPIO_Number_26,     //!< Denotes GPIO number 26
  GPIO_Number_27,     //!< Denotes GPIO number 27
  GPIO_Number_28,     //!< Denotes GPIO number 28
  GPIO_Number_29,     //!< Denotes GPIO number 29
  GPIO_Number_30,     //!< Denotes GPIO number 30
  GPIO_Number_31,     //!< Denotes GPIO number 31
  GPIO_Number_32,     //!< Denotes GPIO number 32
  GPIO_Number_33,     //!< Denotes GPIO number 33
  GPIO_Number_34,     //!< Denotes GPIO number 34
  GPIO_Number_35,     //!< Denotes GPIO number 35
  GPIO_Number_36,     //!< Denotes GPIO number 36
  GPIO_Number_37,     //!< Denotes GPIO number 37
  GPIO_Number_38,     //!< Denotes GPIO number 38
  GPIO_Number_39,     //!< Denotes GPIO number 39
  GPIO_Number_40,     //!< Denotes GPIO number 40
  GPIO_Number_41,     //!< Denotes GPIO number 41
  GPIO_Number_42,     //!< Denotes GPIO number 42
  GPIO_Number_43,     //!< Denotes GPIO number 43
  GPIO_Number_44,     //!< Denotes GPIO number 44
  GPIO_Number_50=50,  //!< Denotes GPIO number 50
  GPIO_Number_51,     //!< Denotes GPIO number 51
  GPIO_Number_52,     //!< Denotes GPIO number 52
  GPIO_Number_53,     //!< Denotes GPIO number 53
  GPIO_Number_54,     //!< Denotes GPIO number 54
  GPIO_Number_55,     //!< Denotes GPIO number 55
  GPIO_Number_56,     //!< Denotes GPIO number 56
  GPIO_Number_57,     //!< Denotes GPIO number 57
  GPIO_Number_58,     //!< Denotes GPIO number 58
  GPIO_Number_59,     //!< Denotes GPIO number 59
  GPIO_Number_60,     //!< Denotes GPIO number 60
  GPIO_Number_61,     //!< Denotes GPIO number 61
  GPIO_Number_62,     //!< Denotes GPIO number 62
  GPIO_Number_63,     //!< Denotes GPIO number 63
  GPIO_Number_64,     //!< Denotes GPIO number 64
  GPIO_Number_65,     //!< Denotes GPIO number 65
  GPIO_Number_66,     //!< Denotes GPIO number 66
  GPIO_Number_67,     //!< Denotes GPIO number 67
  GPIO_Number_68,     //!< Denotes GPIO number 68
  GPIO_numGpios
} GPIO_Number_e;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes





static inline void GPIO_toggle(GPIO_Number_e gpioNumber)
{
	EALLOW;
	if(gpioNumber < GPIO_Number_32){
		GpioDataRegs.GPATOGGLE.all = (uint32_t)1 << gpioNumber;
	} else if(gpioNumber < GPIO_Number_64) {
		GpioDataRegs.GPBTOGGLE.all =(uint32_t)1 << (gpioNumber - GPIO_Number_32);
	} else {
		GpioDataRegs.GPCTOGGLE.all =(uint32_t)1 << (gpioNumber - GPIO_Number_64);
	}
	EDIS;
}



static inline void GPIO_setHigh(uint16_t gpioNumber)
{

	EALLOW;

	if(gpioNumber < GPIO_Number_32){
		GpioDataRegs.GPASET.all = (uint32_t)1 << gpioNumber;
	} else if(gpioNumber < GPIO_Number_64) {
		GpioDataRegs.GPBSET.all =(uint32_t)1 << (gpioNumber - GPIO_Number_32);
	} else {
		GpioDataRegs.GPCSET.all =(uint32_t)1 << (gpioNumber - GPIO_Number_64);
	}

	EDIS;

	return;
} // end of GPIO_setHigh() function


static inline void GPIO_setLow(uint16_t gpioNumber)
{
	EALLOW;

	if(gpioNumber < GPIO_Number_32){
		GpioDataRegs.GPACLEAR.all = (uint32_t)1 << gpioNumber;
	} else if(gpioNumber < GPIO_Number_64) {
		GpioDataRegs.GPBCLEAR.all =(uint32_t)1 << (gpioNumber - GPIO_Number_32);
	} else {
		GpioDataRegs.GPCCLEAR.all =(uint32_t)1 << (gpioNumber - GPIO_Number_64);
	}

	EDIS;
	return;
} // end of GPIO_setLow() function





#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _OIT_GPIO_H_ definition
