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

/** @file calculadora.c
 * @brief Código fuente de calculadora.c
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

// dentro de calculadora tengo un objeto que son las operaciones
typedef struct operation_s * operation_t;

// los atributos de la operacion estan dados por
struct operation_s {
    char op;
    operation_func_t function; // puntero a funcion
    operation_t next;          // es una forma de saber cual es la proxima operacion (lista enlazada)
};

// defino la estructura del objeto calculadora, privada en el archivo c
// en el .h solo la declare

struct calculator_s {
    operation_t operation;
    int result;
};
// la calculadora es abstracta, no realiza ninguna operacion

/* === Private function declarations =============================================================================== */

// funcion que busca la operacion retorna el puntero a la operacion o NULL en caso de no encontrar
static operation_t Find_Operation(calculator_t calculadora, char op);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

// defino la funcion que crea la calculadora
calculator_t Calculator_Create() {
    calculator_t calculadora = malloc(sizeof(struct calculator_s));
    if (calculadora != NULL) {
        /* Si hay espacio para crear la calculadora en memoria*/
        // ubico el puntero de la operacion en NULL por que recien la creo
        calculadora->operation = NULL;
        return calculadora;
    }
    return calculadora;
}

// Defino una funcion para buscar la operacion
static operation_t Find_Operation(calculator_t calculadora, char op) {
    operation_t op_current = calculadora->operation; // le asigno la operacion que tiene el objeto calculadora
    while (op_current != NULL) {
        /* code */
        if (op_current->op == op) {
            /* code */
            return op_current;
        }
        op_current->next = op_current; // en la estructura de operacion el campo de la lista enlazada apunta
        // a la operacion encontrada
    }
    return NULL;
}

bool Calculator_Add_Operation(calculator_t calculator, char op, operation_func_t Function) {
    // vefico que los punteros a la calculadora y a la operacion no sean nulos
    // bool value = true;
    if (calculator == NULL || Function == NULL || Find_Operation(calculator, op)) {
        /* code */
        return false;
        // le asigno espacio en memoria a la estrucutra de la operacion
    }
    operation_t operation = malloc(sizeof(struct operation_s));
    if (operation != NULL) { // si el puntero de la estrucutura es distinto de NULL enotonces
        // en la estructura modifico el valor de los campos con lo que se paso en la funcion
        operation->function = Function;          // funcion de callback
        operation->op = op;                      // el operador es el que se agrega si es que no esta ya
        operation->next = calculator->operation; // la operacion siguiente es la que se añade
        calculator->operation = operation;
        return true;
    }
}

// defino la funcion que realiza el calculo
int Calcule_Calculator(calculator_t calculator, const char expression[]) {
    if (calculator == NULL) {
        return -1;
    }

    int a = 0, b = 0;
    char operator = 0;
    int result;
    /* code */
    int value = sscanf(expression, "%d%c%d", &a, &operator, &b);
    if (value < 3) {
        return -1;
    }
    operation_t op_found = Find_Operation(calculator, operator);
    if (op_found != NULL && op_found->function != NULL) {
        /* code */
        result = calculator->operation->function(a, b);
        calculator->result = result;
        return result;
    }
    return -1;
}

int Add_Operation(int a, int b) {
    return a + b;
}

int Substract_Operation(int a, int b) {
    return a - b;
}

int Dot_Operation(int a, int b) {
    return a * b;
}

int Division_Operation(int a, int b) {
    return a / b;
}

/* === Public function implementation ============================================================================== */

/* === End of documentation ======================================================================================== */
