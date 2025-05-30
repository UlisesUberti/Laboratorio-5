
/*********************************************************************************************************************
Copyright (c) 2025, Uberti,Ulises Leandro <ubertileandro0@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/** @file calculadora.h
 ** @brief Codigo fuente de calculadora.h
 @author Uberti, Ulises Leandro
 **/

/* === Headers files inclusions ==================================================================================== */
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/**
 * @brief objeto calculadora
 *
 */
typedef struct calculator_s * calculator_t;

/**
 * @brief Puntero a funcion (Funcion de Callback)
 *
 */
typedef int (*operation_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Funcion para crear la estructura del objeto calculadora
 *
 * @return calculator_t
 */
calculator_t Calculator_Create(void);

/**
 * @brief Funcion para agregar operaciones en la calculadora
 *
 * @param calculator puntero a objeto calculadora
 * @param op operando
 * @param Function Funcion a realizar (Suma, Resta, Division, ...)
 * @return true Si la agrego
 * @return false Si no la agrego
 */
bool Calculator_Add_Operation(calculator_t calculator, char op, operation_func_t Function);

/**
 * @brief Funcion que permite que la calculadora entregue un valor acorde a la operacion
 *
 * @param calculator puntero a objeto calculadora
 * @param expression cadena ingresada (int-char-int)
 * @return int retorna el resultado de la operacion
 */
int Calcule_Calculator(calculator_t calculator, const char expression[]);

/**
 * @brief Operacion Suma
 *
 * @param a Entero a
 * @param b Entero b
 * @return int Entero suma de a y b
 */
int Add_Operation(int a, int b);

/**
 * @brief Operacion resta
 *
 * @param a
 * @param b
 * @return int
 */
int Substract_Operation(int a, int b);

/**
 * @brief Operacion producto
 *
 * @param a
 * @param b
 * @return int
 */
int Dot_Operation(int a, int b);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULADORA_H_ */
