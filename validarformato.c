#include "main.h"

void manejar_formato(char formato, va_list argumentos)
{
    switch (formato)
    {
    case 'd':
    case 'i':
        imprimir_numero(va_arg(argumentos, int));
        break;
    case 'x':
        imprimir_hexadecimal(va_arg(argumentos, unsigned int), 0);
        break;
    case 'X':
        imprimir_hexadecimal(va_arg(argumentos, unsigned int), 1);
        break;
    case 's':
        imprimir_string(va_arg(argumentos, char *));
        break;
    case 'c':
        _putchar((char)va_arg(argumentos, int));
        break;
    case 'p':
        imprimir_direccion(va_arg(argumentos, void *));
        break;
    case '%':
        _putchar('%');
        break;
    default:
        _putchar('%');
        _putchar(formato);
    }
}
