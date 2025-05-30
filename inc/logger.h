
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

#ifndef LOGGER_H_
#define LOGGER_H_

/** @file logger.h
 ** @brief Codigo fuente de logger.h
 @author Uberti, Ulises Leandro
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

//Primero declaro el puntero a la estructura con los atributos del objeto (en este caso el registro)
typedef struct log_stream_s * log_stream_t; // es una clase (donde el logger cargara los avisos)

// declaro el objeto 
typedef struct logger_s * logger_t; // es una clase 

// declaro una variable que sera un puntero a funcion para abrir un flujo de datos en un archivo
typedef log_stream_t (*log_stream_open_t)(char[]); //log_stream_open_t es un puntero a una funcion de que devuelve un puntero
// y recibe un dato tipo char 

// otra funcion para escribir 
typedef void (*log_stream_write_t)(log_stream_t, char[]); 
// retorna nada y recibe un puntero y la cadena 

// ahora defino una estrutura que sera la interface donde los campos seran las funciones callback 
 typedef struct log_stream_interface 
 {
    log_stream_open_t LogStreamOpen;
    log_stream_write_t LogStreamWrite;
 }const * log_stream_interface_t;
 
/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

// en el enunciado habia una funcion create y una register entonces las dclaramos 

logger_t logger_create(log_stream_interface_t interface);

void logger_register(logger_t logger, char message[]); 

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LOGGER_H_ */
