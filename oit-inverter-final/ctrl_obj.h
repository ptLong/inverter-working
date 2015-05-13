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

#ifndef _CTRL_OBJ_H_
#define _CTRL_OBJ_H_

//! \file ctrl_obj.h 
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.


// **************************************************************************
// the includes

#include "oit-gpio.h"

//!
//!
//! \defgroup _CTRL_OBJ_H_
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// **************************************************************************
// the defines

//! \brief Defines the major release number
//!
#define CTRL_MAJOR_RELEASE_NUMBER       (0)


//! \brief Defines the major release number
//!
#define CTRL_MINOR_RELEASE_NUMBER       (7)


//! \brief Defines the number of controllers
//!
#define CTRL_NUM_CONTROLLERS            (1)


// **************************************************************************
// the typedefs

//! \brief Defines the controller (CTRL) version number
//!
typedef struct _CTRL_Version_
{
	uint16_t rsvd;            //!< reserved value
	uint16_t targetProc;      //!< the target processor
	uint16_t major;           //!< the major release number
	uint16_t minor;           //!< the minor release number
} CTRL_Version;

//! \brief Enumeration for the controller states
//!
typedef enum {
	CTRL_State_Error=0,           //!< the controller error state
	CTRL_State_Idle,              //!< the controller idle state
	CTRL_State_OffLine,           //!< the controller offline state
	CTRL_State_OnLine,            //!< the controller online state
	CTRL_numStates                //!< the number of controller states
} CTRL_State_e;

//! \brief Enumeration for the error codes
//!
typedef enum
{
	CTRL_ErrorCode_NoError=0,        //!< no error error code
	CTRL_ErrorCode_OverCurrent,      //!< over current error code
	CTRL_ErrorCode_OverVoltage,      //!< over voltage error code
	CTRL_numErrorCodes               //!< the number of controller error codes
} CTRL_ErrorCode_e;


//! \brief Enumeration for the e
//!
typedef enum
{
	CTRL_SinCycleState_Positive=0,        //!< positive sin cycle state
	CTRL_SinCycleState_Negative,          //!< negative sin cyle state
	CTRL_numSinCycleStates                 //!< the number of state
} CTRL_SinCycleState_e;

//! \brief Defines the controller (CTRL) object
//!
typedef struct _CTRL_Obj_
{
	CTRL_Version       version;                      //!< the controller version

	CTRL_State_e       state;                        //!< the current state of the controller

	CTRL_State_e       prevState;                    //!< the previous state of the controller

	CTRL_ErrorCode_e   errorCode;                    //!< the error code for the controller


	CTRL_SinCycleState_e	sinCycleState;

	CTRL_SinCycleState_e	nextSinCycleState;


//	GPIO_Number_e      lowFreq_mosfet_low;
//
//	GPIO_Number_e      lowFreq_mosfet_high;


//	PI_Handle          piHandle_Id;                  //!< the handle for the Id PI controller
//	PI_Obj             pi_Id;                        //!< the Id PI controller object
//
//	PI_Handle          piHandle_Iq;                  //!< the handle for the Iq PI controller
//	PI_Obj             pi_Iq;                        //!< the Iq PI controller object
//
//	PI_Handle          piHandle_spd;                 //!< the handle for the speed PI controller
//	PI_Obj             pi_spd;                       //!< the speed PI controller object
//
//	MOTOR_Params       motorParams;                  //!< the motor parameters
//
//	int_least32_t      waitTimes[CTRL_numStates];    //!< an array of wait times for each state, isr clock counts
//
//	int_least32_t      counter_state;                //!< the state counter
//
//	int_least16_t      numIsrTicksPerCtrlTick;       //!< Defines the number of isr clock ticks per controller clock tick
//
//	int_least16_t      numCtrlTicksPerCurrentTick;   //!< Defines the number of controller clock ticks per current controller clock tick
//
//	int_least16_t      numCtrlTicksPerSpeedTick;     //!< Defines the number of controller clock ticks per speed controller clock tick
//
//	uint_least32_t     ctrlFreq_Hz;                  //!< Defines the controller frequency, Hz
//
//	float_t            ctrlPeriod_sec;               //!< Defines the controller period, sec
//	float_t            currentCtrlPeriod_sec;        //!< the period at which the current controller runs, sec
//	float_t            speedCtrlPeriod_sec;          //!< the period at which the speed controller runs, sec
//
//	MATH_vec2          Idq_A;                        //!< the Idq values, A
//
//	MATH_vec2          Idq_ref_A;                    //!< the Idq reference values, A
//
//	MATH_vec2          Idq_offset_A;                 //!< the Idq offset values, A
//
//	MATH_vec2          Vdq_V;                        //!< the Vdq values, V
//
//	MATH_vec2          Vdq_offset_V;                 //!< the Vdq offset values, V
//
//	float_t            Vd_sf;                        //!< the Vd scale factor
//
//	float_t            maxVsMag_V;                   //!< the maximum stator voltage magnitude value, V
//
//	float_t            Kp_Id_VpA;                    //!< the desired Kp_Id value, V/A
//	float_t            Kp_Iq_VpA;                    //!< the desired Kp_Iq value, V/A
//	float_t            Kp_spd_ApHz;                  //!< the desired Kp_spd value, A/Hz
//
//	float_t            Ki_Id;                        //!< the desired Ki_Id value, unitless
//	float_t            Ki_Iq;                        //!< the desired Ki_Iq value, unitless
//	float_t            Ki_spd_ApHz;                  //!< the desired Ki_spd value, A/Hz
//
//	float_t            Ui_Id_V;                      //!< the start integrator value for the Id controller, V
//	float_t            Ui_Iq_V;                      //!< the start integrator value for the Iq controller, V
//	float_t            Ui_spd_A;                     //!< the start integrator value for the speed controller, A
//
//	float_t            BWc_rps;                      //!< the bandwidth of the current controllers, rad/sec
//	float_t            BWdelta;                      //!< the bandwidth scaling to maximize phase margin
//	float_t            Kctrl_Wb_p_kgm2;              //!< the controller constant, Wb/(kg*m^2)
//
//	float_t            speed_ref_Hz;                 //!< the reference speed value, Hz
//
//	float_t            speed_fb_Hz;                  //!< the feedback speed value, Hz
//
//	float_t            speed_out_A;                  //!< the output value from the speed controller, A
//	float_t            speed_outMax_A;               //!< the maximum output value for the speed controller, A
//
//	int_least16_t      counter_isr;                  //!< the isr counter
//	int_least16_t      counter_current;              //!< the isr counter
//	int_least16_t      counter_speed;                //!< the speed counter
//
//	bool               flag_enable;                  //!< a flag to enable the controller
//	bool               flag_enableCurrentCtrl;       //!< a flag to enable the current controllers
//	bool               flag_enableSpeedCtrl;         //!< a flag to enable the speed controller
//
//	bool               flag_updateKi_spd;            //!< a flag to update Ki_spd
//	bool               flag_updateKi_Id;             //!< a flag to update Ki_Id
//	bool               flag_updateKi_Iq;             //!< a flag to update Ki_Iq
//
//	bool               flag_resetInt_spd;            //!< a flag to reset the speed integrator
//	bool               flag_resetInt_Id;             //!< a flag to reset the Id integrator
//	bool               flag_resetInt_Iq;             //!< a flag to reset the Iq integrator
//
//	bool               flag_useZeroIq_ref;           //!< a flag to force a Iq = 0 reference value
} CTRL_Obj;


//! \brief Defines the CTRL handle
//!
typedef struct _CTRL_Obj_ *CTRL_Handle;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _CTRL_OBJ_H_ definition
