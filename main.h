#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

/* Encabezado de las funciones usadas */
int _printf(const char *format, ...);
int manejar_formato(char formato, va_list argumentos);
int imprimir_numero(int n);
int imprimir_hexadecimal(unsigned int n, int mayusculas);
int imprimir_string(char *s);
int imprimir_direccion(void *ptr);
int _putchar(char c);

#endif
