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

//! \file main.c 
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
#include "system-init.h"
#include "ti-sfo-v8.h"
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

void main()
{
	System_init();

	while(1)
	{

		PWM_update_scale_factor_optimizer();
	}

}




__interrupt void cpu_timer2_isr(void)
{
	GPIO_setHigh(GPIO_LED_WHITE);
	GPIO_setLow(GPIO_LED_BLUE);

	static uint16_t line_freq_cnt = 0;

	if(line_freq_cnt++ == 166){
		line_freq_cnt = 0;

		EPwm1Regs.TBCTL.bit.SWFSYNC = 1;                // Synchronize high resolution phase to start HR period
		EPwm4Regs.TBCTL.bit.SWFSYNC = 1;                // Synchronize high resolution phase to start HR period
	}

	if(line_freq_cnt < 83){
//		EPwm4Regs.CMPA.all = 0;


		EPwm1Regs.CMPA.bit.CMPA = ( 0.1 *EPwm1Regs.TBPRD );


	}else{
		EPwm4Regs.CMPA.all = (uint32_t)0xffff << 16;

		EPwm1Regs.CMPA.bit.CMPA = ( 0.9 *EPwm1Regs.TBPRD );
	}

	EPwm2Regs.TBPHS.bit.TBPHS = 0.3333333 * EPwm2Regs.TBPRD;
	EPwm3Regs.TBPHS.bit.TBPHS = 0.6666666 * EPwm3Regs.TBPRD;



//   if(CpuTimer2.InterruptCount == 99999){
//	   CpuTimer2.InterruptCount = 0;
//	   GPIO_toggle(LED2);
//   }else{
//	   CpuTimer2.InterruptCount++;
//   }


	//read_adc_data();
	//control_output_voltage();


//	if(gLEDcnt++ > (uint_least32_t)MAIN_ISR_FREQ_KHZ*1000/LED_BLINK_FREQ_HZ)
//	{
//		//GPIO_toggle(LED1);
//		gLEDcnt=0;
//	}


	GPIO_setLow(GPIO_LED_WHITE);
	GPIO_setHigh(GPIO_LED_BLUE);
   // The CPU acknowledges the interrupt.
}


__interrupt void adcd_ppb_isr(void)
{
	EALLOW;
	EPwm1Regs.TZFRC.bit.OST = 1; //force PWM off
	EPwm2Regs.TZFRC.bit.OST = 1;
	EPwm3Regs.TZFRC.bit.OST = 1;
	EDIS;
	//warning, you are outside of PPB limits
	if(AdcdRegs.ADCEVTSTAT.bit.PPB1TRIPHI)
	{
		//voltage exceeded high limit
		asm("   ESTOP0");

		//clear the trip flag and continue
		AdcdRegs.ADCEVTCLR.bit.PPB1TRIPHI = 1;
	}
	if(AdcdRegs.ADCEVTSTAT.bit.PPB1TRIPLO)
	{
		//voltage exceeded low limit
		asm("   ESTOP0");

		//clear the trip flag and continue
		AdcdRegs.ADCEVTCLR.bit.PPB1TRIPLO = 1;
	}

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
}

__interrupt void adcb_ppb_isr(void)
{
	EALLOW;
	EPwm1Regs.TZFRC.bit.OST = 1; //force PWM off
	EPwm2Regs.TZFRC.bit.OST = 1;
	EPwm3Regs.TZFRC.bit.OST = 1;
	EDIS;
	//warning, you are outside of PPB limits
	if(AdcbRegs.ADCEVTSTAT.bit.PPB1TRIPHI)
	{
		//voltage exceeded high limit
		asm("   ESTOP0");

		//clear the trip flag and continue
		AdcbRegs.ADCEVTCLR.bit.PPB1TRIPHI = 1;
	}
	if(AdcbRegs.ADCEVTSTAT.bit.PPB1TRIPLO)
	{
		//voltage exceeded low limit
		asm("   ESTOP0");

		//clear the trip flag and continue
		AdcbRegs.ADCEVTCLR.bit.PPB1TRIPLO = 1;
	}

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;
}


