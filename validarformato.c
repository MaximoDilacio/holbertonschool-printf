#include "main.h"
#include <stdarg.h>

int manejar_formato(char formato, va_list argumentos)
{
    int caracteres = 0;

    switch (formato)
    {
    case 'd':
    case 'i':
        caracteres = imprimir_numero(va_arg(argumentos, int));
        break;
    case 'x':
        caracteres = imprimir_hexadecimal(va_arg(argumentos, unsigned int), 0);
        break;
    case 'X':
        caracteres = imprimir_hexadecimal(va_arg(argumentos, unsigned int), 1);
        break;
    case 's':
        caracteres = imprimir_string(va_arg(argumentos, char *));
        break;
    case 'c':
        _putchar((char)va_arg(argumentos, int));
        caracteres = 1;
        break;
    case 'p':
        caracteres = imprimir_direccion(va_arg(argumentos, void *));
        break;
    case '%':
        _putchar('%');
        caracteres = 1;
        break;
    default:
        _putchar('%');
        _putchar(formato);
        caracteres = 2;
    }
    return caracteres;
}

