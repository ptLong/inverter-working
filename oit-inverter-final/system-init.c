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
//! \file system-init.c 
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
#include "user.h"
#include "ti-sfo-v8.h"
#include "main.h"
#include "oit-gpio.h"

// **************************************************************************
// the defines

// **************************************************************************
// the typedefs

// **************************************************************************
// the globals

// **************************************************************************
// the local function prototypes
void PIE_to_default_settings(void);
void TIMERS_to_default_settings(void);
void PWM_all_to_default_settings();
void GPIO_to_default_settings(void);
void Enable_clock_for_default_peripherals(void);


// **************************************************************************
// the functions

void System_init()
{
	DisableDog();
#ifdef _FLASH
	// Copy time critical code and Flash setup code to RAM
	// This includes the following functions:  InitFlash();
	// The  RamfuncsLoadStart, RamfuncsLoadSize, and RamfuncsRunStart
	// symbols are created by the linker. Refer to the device .cmd file.
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

	// Call Flash Initialization to setup flash waitstates
	// This function must reside in RAM
	InitFlash();
#endif

#ifdef CPU1
	EALLOW;

	//enable pull-ups on unbonded IOs as soon as possible to reduce power consumption.
	GPIO_EnableUnbondedIOPullups();

	CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

	//check if device is trimmed
	if(*((Uint16 *)0x5D1B6) == 0x0000){
		//device is not trimmed, apply static calibration values
		AnalogSubsysRegs.ANAREFTRIMA.all = 31709;
		AnalogSubsysRegs.ANAREFTRIMB.all = 31709;
		AnalogSubsysRegs.ANAREFTRIMC.all = 31709;
		AnalogSubsysRegs.ANAREFTRIMD.all = 31709;
	}

	CpuSysRegs.PCLKCR13.bit.ADC_A = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 0;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 0;

	EDIS;

	// Initialize the PLL control: PLLCR and CLKINDIV
	// F28_PLLCR and F28_CLKINDIV are defined in F2837xD_Examples.h
	// Note: The internal oscillator CANNOT be used as the PLL source if the
	// PLLSYSCLK is configured to frequencies above 194 MHz.
	InitSysPll(XTAL_OSC,IMULT_20,FMULT_1,PLLCLK_BY_2);		//PLLSYSCLK = 20MHz(XTAL_OSC) * 20 (IMULT) * 1 (FMULT) /  2 (PLLCLK_BY_2)

#endif

	Enable_clock_for_default_peripherals();

	GPIO_to_default_settings();

	//ADC_to_default_settings();

	PIE_to_default_settings();

	//CLA_to_default_settings();

	PWM_all_to_default_settings();

	TIMERS_to_default_settings();

	//CTRL_init();


}




void PIE_to_default_settings(void)
{
	DINT;

	// Initialize the PIE control registers to their default state.
	// The default state is all PIE interrupts disabled and flags
	// are cleared.
	InitPieCtrl();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;

	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	// This will populate the entire table, even if the interrupt
	// is not used in this example.  This is useful for debug purposes.
	// The shell ISR routines are found in F2837xD_DefaultIsr.c.
	// This function is found in F2837xD_PieVect.c.
	InitPieVectTable();


	EALLOW;  // This is needed to write to EALLOW protected registers
	//PieVectTable.TIMER0_INT = &cpu_timer0_isr;
	//PieVectTable.TIMER1_INT = &cpu_timer1_isr;
	PieVectTable.TIMER2_INT = &cpu_timer2_isr;
	PieVectTable.ADCD_EVT_INT = &adcd_ppb_isr;
	PieVectTable.ADCB_EVT_INT = &adcb_ppb_isr;
	//PieVectTable.ADCA1_INT = &main_isr;

	//Enable ADC1 interrupt at the group and subgroup levels
	//PieCtrlRegs.PIEIER1.bit.INTx1 = 1;
	//IER |= M_INT1; //Enable group 1 interrupts



	// Configure the vectors for the end-of-task interrupt for all
	// 8 tasks
	//	PieVectTable.CLA1_1_INT   = &cla1Isr1;
	//	PieVectTable.CLA1_2_INT   = &cla1Isr2;
	//	PieVectTable.CLA1_3_INT   = &cla1Isr3;
	//	PieVectTable.CLA1_4_INT   = &cla1Isr4;
	//	PieVectTable.CLA1_5_INT   = &cla1Isr5;
	//	PieVectTable.CLA1_6_INT   = &cla1Isr6;
	//PieVectTable.CLA1_7_INT   = &cla1Isr7;
	//PieVectTable.CLA1_8_INT   = &cla1Isr8;

	// Enable CLA interrupts 7&8 at the group and subgroup levels
	//PieCtrlRegs.PIEIER11.all  = BIT6|BIT7;
	//IER |= (M_INT11 );

	IER |= M_INT10; //Enable group 10 interrupts (ADC trip)
	//enable PIE interrupt
	PieCtrlRegs.PIEIER10.bit.INTx13 = 1;
	PieCtrlRegs.PIEIER10.bit.INTx5 = 1;


	EDIS;    // This is needed to disable write to EALLOW protected registers

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM

}



void TIMERS_to_default_settings(void)
{
	InitCpuTimers();

	// Configure CPU-Timer 0, 1, and 2 to interrupt every second:
	// 200MHz CPU Freq, 1 second Period (in uSeconds)
	//ConfigCpuTimer(&CpuTimer0, 200, 1000000);
	//ConfigCpuTimer(&CpuTimer1, CPU_FREQ_MHZ, 999999); //1s
	ConfigCpuTimer(&CpuTimer2, CPU_FREQ_MHZ, (float)1000/MAIN_ISR_FREQ_KHZ); // 10us ~ 100khz

	// To ensure precise timing, use write-only instructions to write to the entire register. Therefore, if any
	// of the configuration bits are changed in ConfigCpuTimer and InitCpuTimers (in F2837xD_cputimervars.h), the
	// below settings must also be updated.
	//CpuTimer0Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
	//CpuTimer1Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
	CpuTimer2Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0

	// Step 5. User specific code, enable interrupts:

	// Enable CPU int1 which is connected to CPU-Timer 0, CPU int13
	// which is connected to CPU-Timer 1, and CPU int 14, which is connected
	// to CPU-Timer 2:
	//IER |= M_INT1;
	//IER |= M_INT13;
	IER |= M_INT14;

	// Enable TINT0 in the PIE: Group 1 interrupt 7
	//PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
}



void PWM_config_default(volatile struct EPWM_REGS *obj, uint16_t period)
{
	obj->TBCTL.bit.PRDLD = TB_SHADOW;      // set Immediate load
	obj->TBPRD = period-1;                 // PWM frequency = 1 / period
	obj->CMPA.bit.CMPA = period / 2;       // set duty 50% initially
	obj->CMPA.bit.CMPAHR = (1 << 8);       // initialize HRPWM extension
	obj->CMPB.bit.CMPB = period / 2;       // set duty 50% initially
	obj->CMPB.all |= (1 << 8);             // initialize HRPWM extension
	obj->TBPHS.all = 0;						// Phase is 0
	obj->TBCTR = 0;							// Clear counter

	obj->TBCTL.bit.CTRMODE = TB_COUNT_UP;
	obj->TBCTL.bit.PHSEN = TB_ENABLE;
	obj->TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;  // Sync output select
	obj->TBCTL.bit.HSPCLKDIV = TB_DIV1;
	obj->TBCTL.bit.CLKDIV = TB_DIV1;
	obj->TBCTL.bit.FREE_SOFT = 11;			// 1x do not stop when emulation

	obj->CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	obj->CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	obj->CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	obj->CMPCTL.bit.SHDWBMODE = CC_SHADOW;

	obj->AQCTLA.bit.ZRO = AQ_SET;               // PWM toggle high/low
	obj->AQCTLA.bit.CAU = AQ_CLEAR;
//	obj->AQCTLB.bit.ZRO = AQ_SET;
//	obj->AQCTLB.bit.CBU = AQ_CLEAR;

	obj->DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	obj->DBCTL.bit.POLSEL = DB_ACTV_HIC;
	obj->DBCTL.bit.IN_MODE = DBA_ALL;
	obj->DBCTL.bit.HALFCYCLE = 1;   // half cycle clocking
	obj->DBRED = 9;
	obj->DBFED = 9;

	EALLOW;
	obj->HRCNFG.all = 0x0;
	obj->HRCNFG.bit.EDGMODE = HR_BEP;          // MEP control on both edge
	obj->HRCNFG.bit.CTLMODE = HR_CMP;
	obj->HRCNFG.bit.HRLOAD  = HR_CTR_ZERO;
	obj->HRCNFG.bit.EDGMODEB = HR_BEP;          // MEP control on both edge
	obj->HRCNFG.bit.CTLMODEB = HR_CMP;
	obj->HRCNFG.bit.HRLOADB  = HR_CTR_ZERO;
	obj->HRCNFG.bit.AUTOCONV = 1;              // Enable auto-conversion logic

	obj->HRCNFG2.bit.EDGMODEDB = 0x3;		// MEP control of both edge

//##############
	// Chip bug: Must turn off HR period control or HR will not work.
//	obj->HRPCTL.bit.HRPE = 1;                  // Turn on high-resolution period control.
//
	//CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;           // Enable TBCLK within the EPWM
	obj->TBCTL.bit.SWFSYNC = 1;                // Synchronize high resolution phase to start HR period
	EDIS;
}

void PWM_all_to_default_settings()
{
	uint16_t period = 678;

	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
	EDIS;
	PWM_init_scale_factor_optimizer();

	PWM_config_default(&EPwm1Regs, period);
	PWM_config_default(&EPwm2Regs, period);
	PWM_config_default(&EPwm3Regs, period);

	// link compare and timebase of pwm2 and pwm3 to pwm1
	// writing to CMPA and TBPRD of pwm1 will update pwm2,pwm3
	EPwm2Regs.EPWMXLINK.bit.CMPALINK = 0;
	EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 0;
	EPwm2Regs.EPWMXLINK.bit.GLDCTL2LINK = 0;

	EPwm3Regs.EPWMXLINK.bit.CMPALINK = 0;
	EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 0;
	EPwm3Regs.EPWMXLINK.bit.GLDCTL2LINK = 0;


	PWM_config_default(&EPwm4Regs, 678);
	EPwm4Regs.CMPA.all = 0;


	// configure phase sync between modules
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	// account for 2 clocks cycle delay for syncOut from EPWM1
	EPwm2Regs.TBPHS.bit.TBPHS = 2;
	EPwm3Regs.TBPHS.bit.TBPHS = 2;
	EPwm4Regs.TBPHS.bit.TBPHS = 8;

	PWM_config_default(&EPwm6Regs, period);
	//PWM_set_frequency_KHz(PWM_Channel_6, 20);

	PWM_config_default(&EPwm7Regs, period);
	PWM_config_default(&EPwm8Regs, period);

	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
	EDIS;
}

void GPIO_to_default_settings(void)
{
	// Default Ti's GPIO init
	//Sets all pins to be muxed to GPIO in input mode with pull-ups enabled.
	//Also resets CPU control to CPU1 and disables open drain and polarity
	//inversion and sets the qualification to synchronous. Also unlocks all GPIOs
	//Only one CPU should call this function.
	InitGpio();

	// this application specific GPIO configuation
	EALLOW;

	// 3 channels interleaved High Frequency PWM
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B

	GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
	GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B


	// Low frequency Mosfets
	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;    // Disable pull-up on GPIO6 (EPWM4A)
	GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;    // Disable pull-up on GPIO7 (EPWM4B)
//	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
//	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
	GPIO_SetupPinMux(GPIO_LOWFREQMOSFET_HIGH, GPIO_MUX_CPU1, 0);
	GPIO_SetupPinOptions(GPIO_LOWFREQMOSFET_HIGH, GPIO_OUTPUT, GPIO_PUSHPULL);
	GPIO_SetupPinMux(GPIO_LOWFREQMOSFET_LOW, GPIO_MUX_CPU1, 0);
	GPIO_SetupPinOptions(GPIO_LOWFREQMOSFET_LOW, GPIO_OUTPUT, GPIO_PUSHPULL);


	// PWM6A GPIO10 for controling load test
	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // Disable pull-up on GPIO10 (EPWM6A)
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A

	// PWM7B (LED), 8A (LED), 8B for other purposes
//	GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;    // Disable pull-up on GPIO13 (EPWM7B)
//	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;   // Configure GPIO13 as EPWM7B
//
//	GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1;    // Disable pull-up on GPIO14 (EPWM8A)
//	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;   // Configure GPIO14 as EPWM8A

	GPIO_SetupPinMux(GPIO_LED_BLUE, GPIO_MUX_CPU1, 0);
	GPIO_SetupPinOptions(GPIO_LED_BLUE, GPIO_OUTPUT, GPIO_PUSHPULL);

	GPIO_SetupPinMux(GPIO_LED_WHITE, GPIO_MUX_CPU1, 0);
	GPIO_SetupPinOptions(GPIO_LED_WHITE, GPIO_OUTPUT, GPIO_PUSHPULL);



	GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1;    // Disable pull-up on GPIO15 (EPWM8B)
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;   // Configure GPIO15 as EPWM8B

	EDIS;
}


void Enable_clock_for_default_peripherals(void)
{
	EALLOW;

	//CpuSysRegs.PCLKCR0.bit.CLA1 = 0;
	//CpuSysRegs.PCLKCR0.bit.DMA = 1;
	//CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
	//CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
	CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
	CpuSysRegs.PCLKCR0.bit.HRPWM = 1;
	//CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;

	//CpuSysRegs.PCLKCR1.bit.EMIF1 = 1;
	//CpuSysRegs.PCLKCR1.bit.EMIF2 = 1;

	CpuSysRegs.PCLKCR2.bit.EPWM1 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM2 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM3 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM4 = 1;
	//CpuSysRegs.PCLKCR2.bit.EPWM5 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM6 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM7 = 1;
	CpuSysRegs.PCLKCR2.bit.EPWM8 = 1;
	//CpuSysRegs.PCLKCR2.bit.EPWM9 = 1;
	//CpuSysRegs.PCLKCR2.bit.EPWM10 = 1;
	//CpuSysRegs.PCLKCR2.bit.EPWM11 = 1;
	//CpuSysRegs.PCLKCR2.bit.EPWM12 = 1;

	//CpuSysRegs.PCLKCR3.bit.ECAP1 = 1;
	//CpuSysRegs.PCLKCR3.bit.ECAP2 = 1;
	//CpuSysRegs.PCLKCR3.bit.ECAP3 = 1;
	//CpuSysRegs.PCLKCR3.bit.ECAP4 = 1;
	//CpuSysRegs.PCLKCR3.bit.ECAP5 = 1;
	//CpuSysRegs.PCLKCR3.bit.ECAP6 = 1;

	//CpuSysRegs.PCLKCR4.bit.EQEP1 = 1;
	//CpuSysRegs.PCLKCR4.bit.EQEP2 = 1;
	//CpuSysRegs.PCLKCR4.bit.EQEP3 = 1;

	//CpuSysRegs.PCLKCR6.bit.SD1 = 1;
	//CpuSysRegs.PCLKCR6.bit.SD2 = 1;

	//CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
	//CpuSysRegs.PCLKCR7.bit.SCI_B = 1;
	//CpuSysRegs.PCLKCR7.bit.SCI_C = 1;
	//CpuSysRegs.PCLKCR7.bit.SCI_D = 1;

	//CpuSysRegs.PCLKCR8.bit.SPI_A = 1;
	//CpuSysRegs.PCLKCR8.bit.SPI_B = 1;
	//CpuSysRegs.PCLKCR8.bit.SPI_C = 1;

	//CpuSysRegs.PCLKCR9.bit.I2C_A = 1;
	//CpuSysRegs.PCLKCR9.bit.I2C_B = 1;

	//CpuSysRegs.PCLKCR10.bit.CAN_A = 1;
	//CpuSysRegs.PCLKCR10.bit.CAN_B = 1;

	//CpuSysRegs.PCLKCR11.bit.McBSP_A = 1;
	//CpuSysRegs.PCLKCR11.bit.McBSP_B = 1;
	//CpuSysRegs.PCLKCR11.bit.USB_A = 1;

	//CpuSysRegs.PCLKCR12.bit.uPP_A = 1;

	CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
	CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

	//CpuSysRegs.PCLKCR14.bit.CMPSS1 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS2 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS3 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS4 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS5 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS6 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS7 = 1;
	//CpuSysRegs.PCLKCR14.bit.CMPSS8 = 1;

	//CpuSysRegs.PCLKCR16.bit.DAC_A = 1;
	//CpuSysRegs.PCLKCR16.bit.DAC_B = 1;
	//CpuSysRegs.PCLKCR16.bit.DAC_C = 1;

	EDIS;
}
