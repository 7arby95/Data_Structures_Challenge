/*
 * std_types.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Youssef Harby
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef unsigned char     	uint8_t;          /*           0 .. 255             */
typedef char           		sint8_t;          /*        -128 .. +127            */
typedef unsigned short     	uint16_t;         /*           0 .. 65535           */
typedef short          		sint16_t;         /*      -32768 .. +32767          */
typedef unsigned long      	uint32_t;         /*           0 .. 4294967295      */
typedef long           		sint32_t;         /* -2147483648 .. +2147483647     */
typedef unsigned long long	uint64_t;         /*       0..18446744073709551615  */
typedef long long			sint64_t;
typedef float				float32_t;
typedef double             	float64_t;

#endif /* STD_TYPES_H_ */
