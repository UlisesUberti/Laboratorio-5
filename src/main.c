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

/** @file main.c
 * @brief Código fuente de main.c
 * @author Uberti, Ulises Leandro
 * */

/* === Headers files inclusions ==================================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calculadora.h"
/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/**
 * @brief Funcion cociente
 *
 * @param a
 * @param b
 * @return int cociente entre dos enteros
 */
int Division_Operation(int a, int b);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

// Agrego una nueva operacion en la calculadora
int Division_Operation(int a, int b) {
    return a / b;
}

int main(void) {
    // declaro una variable en la cual se almacenara el resultado
    int result;
    printf("INICIA EL MAIN \n");
    calculator_t calculadora = Calculator_Create();

    // Con la funcion de agregar las operaciones le digo cuales agregar, en este caso suma resta y multiplicacion
    printf(" AGREGA LA PRIMERA OPERACION EN EL MAIN \n");
    Calculator_Add_Operation(calculadora, '-', Substract_Operation);
    printf(" CALCULAMOS EL PRIMER VALOR EN EL MAIN\n");
    result = Calcule_Calculator(calculadora, "22-22");
    printf("El resultado de la resta es: %d \n", result);

    Calculator_Add_Operation(calculadora, '+', Add_Operation);
    result = Calcule_Calculator(calculadora, "3+3");
    printf("El resultado de la suma es: %d \n", result);

    Calculator_Add_Operation(calculadora, '+', Add_Operation);
    result = Calcule_Calculator(calculadora, "22+22");
    printf("El resultado de la suma es: %d \n", result);

    Calculator_Add_Operation(calculadora, 'x', Dot_Operation);
    result = Calcule_Calculator(calculadora, "22x22");
    printf("El resultado del producto es: %d \n", result);

    Calculator_Add_Operation(calculadora, '/', Division_Operation);
    result = Calcule_Calculator(calculadora, "22/22 ");
    printf("El resultado de la division es: %d \n", result);

    return 0;
}

/* === Public function implementation ============================================================================== */

/* === End of documentation ======================================================================================== */
