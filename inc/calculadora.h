
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

// Primero declaro un objeto llamado calculadora --> La calculadora sera un objeto
typedef struct calculator_s * calculator_t;

// Ahora declaro la interface de las funciones -> Recibiran dos enteros y devolveran 1 solo
typedef int (*operation_func_t)(int, int);
// Es una funcion callback --> puntero a funcion
// representa la tabla dinamica donde se encontraran las funciones a realizar

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

// Una funcion para crear la calculadora en el programa principal
calculator_t Calculator_Create(void);

// Declaro una funcion que agregue la operacion utilizar segun el operador
bool Calculator_Add_Operation(calculator_t calculator, char op, operation_func_t Function);
// recibe la calculadora creada, la cadena con la operacion, y el puntero a la funcion de Callback

// declaro una funcion que sume

int Add_Operation(int a, int b);

// Declaro una funcion que reste

int Substract_Operation(int a, int b);

// Declaro una funcion que realice la operacion deseada
int Calcule_Calculator(calculator_t calculator, const char expression[]);
// recibe el objeto y la cadena con la operacion
// producto
int Dot_Operation(int a, int b);
// division
int Division_Operation(int a, int b);
/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULADORA_H_ */
