#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list argumentos;
    int impresos = 0;

    if (!format)
        return (-1);

    va_start(argumentos, format);

    while (*format)
    {
        if (*format == '%')  
        {
            format++;  
            if (*format == '\0')
                return (-1);

            impresos += manejar_formato(*format, argumentos);
        }
        else
        {
            _putchar(*format);
            impresos++;
        }
        format++;
    }

    va_end(argumentos);
    return impresos;
}
