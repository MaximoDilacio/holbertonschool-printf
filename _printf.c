#include "main.h"

int _printf(const char *formato, ...)
{
    va_list argumentos;
    int caracteres = 0;

    va_start(argumentos, formato);
    while (*formato)
    {
        if (*formato == '%')
        {
            formato++;
            manejar_formato(*formato, argumentos);
        }
        else
        {
            _putchar(*formato);
        }
        formato++;
        caracteres++;
    }
    va_end(argumentos);
    return (caracteres);
}
