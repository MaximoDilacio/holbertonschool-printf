#include "main.h"
#include <stdarg.h>

int _printf(const char *formato, ...)
{
    va_list argumentos;
    int caracteres = 0, impresos = 0;

    va_start(argumentos, formato);
    while (*formato)
    {
        if (*formato == '%')
        {
            formato++;
            impresos = manejar_formato(*formato, argumentos);
            caracteres += impresos;
        }
        else
        {
            _putchar(*formato);
            caracteres++;
        }
        formato++;
    }
    va_end(argumentos);
    return caracteres;
}

