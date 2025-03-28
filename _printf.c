#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list argumentos;
    int count = 0;

    if (!format)
        return (-1);

    va_start(argumentos, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            count += manejar_formato(*format, argumentos);
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(argumentos);
    return count;
}
