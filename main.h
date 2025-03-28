#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

/* Encabezado de las funciones usadas */
int _printf(const char *formato, ...);
void imprimir_string(const char *string);
void imprimir_numero(int numero);
void imprimir_hexadecimal(unsigned int numero, int mayuscula);
void imprimir_direccion(void *puntero);
int _putchar(char c);
void manejar_formato(char formato, va_list argumentos);

#endif

