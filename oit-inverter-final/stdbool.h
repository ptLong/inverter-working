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

#ifndef _OIT_TYPES_H_
#define _OIT_TYPES_H_

//! \file oit-types.h
//!
//! \brief  
//! 
//! \created on: May 12, 2015
//! \    author: LP
//!
//! (C) Copyright 2015, Oregon Tech.


// **************************************************************************
// the includes

// system
#include "stdbool.h"  // needed for bool type, true/false
#include "string.h"   // needed for size_t typedef
#include "stdint.h"   // needed for C99 data types


//!
//!
//! \defgroup _OIT_TYPES_H_
//!
//@{


#ifdef __cplusplus
extern "C" {
#endif

// **************************************************************************
// the defines

//! \brief Defines high
//!
#define   HIGH          1


//! \brief Defines low
//!
#define   LOW          0


//! \brief Defines off
//!
#define   OFF           0


//! \brief Defines ok
//!
#define   OK            0


//! \brief Defines on
//!
#define   ON            1


//! \brief Defines generic error
//!
#define   ERROR         1


// **************************************************************************
// the typedefs


//! \brief Defines the portable data type for a status result
//!
typedef unsigned int    status;


//! \brief Defines the portable data type for 32 bit, signed floating-point data
//!
typedef float           float_t;


//! \brief Defines the portable data type for 64 bit, signed floating-point data
//!
typedef long double     double_t;


//! \brief Define the complex data type for at least 8 bit signed real and imaginary components
//!
typedef struct _cplx_int_least8_t
{
  int_least8_t  imag;
  int_least8_t  real;
} cplx_int_least8_t;


//! \brief Define the complex data type for at least 8 bit unsigned real and imaginary components
//!
typedef struct _cplx_uint_least8_t
{
  uint_least8_t  imag;
  uint_least8_t  real;
} cplx_uint_least8_t;


//! \brief Define the complex data type for at least 16 bit signed real and imaginary components
//!
typedef struct _cplx_least16_t
{
  int_least16_t  imag;
  int_least16_t  real;
} cplx_int_least16_t;


//! \brief Define the complex data type for at least 16 bit unsigned real and imaginary components
//!
typedef struct _cplx_uleast16_t
{
  uint_least16_t  imag;
  uint_least16_t  real;
} cplx_uint_least16_t;


//! \brief Define the complex data type for at least 32 bit signed real and imaginary components
//!
typedef struct _cplx_int_least32_t_
{
  int_least32_t  imag;
  int_least32_t  real;
} cplx_int_least32_t;


//! \brief Define the complex data type for at least 32 bit unsigned real and imaginary components
//!
typedef struct _cplx_uint_least32_t_
{
  uint_least32_t  imag;
  uint_least32_t  real;
} cplx_uint_least32_t;


//! \brief Define the complex data type for 16 bit signed real and imaginary components
//!
typedef struct _cplx_int16_t_
{
  int16_t  imag;
  int16_t  real;
} cplx_int16_t;


//! \brief Define the complex data type for 16 bit unsigned real and imaginary components
//!
typedef struct _cplx_uint16_t_
{
  uint16_t  imag;
  uint16_t  real;
} cplx_uint16_t;


//! \brief Define the complex data type for 32 bit signed real and imaginary components
//!
typedef struct _cplx_int32_t
{
  int32_t  imag;
  int32_t  real;
} cplx_int32_t;


//! \brief Define the complex data type for 32 bit unsigned real and imaginary components
//!
typedef struct _cplx_uint32_t
{
  uint32_t  imag;
  uint32_t  real;
} cplx_uint32_t;

//---------------------------------------------------------------------------
// The following data types are included for compatibility with legacy code,
// they are not recommended for use in new software.  Please use the C99
// types included above
//
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned int    	Uint16;
typedef unsigned long   	Uint32;
typedef unsigned long long	Uint64;
typedef float           	float32;
typedef long double     	float64;
#endif

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _OIT_TYPES_H_ definition