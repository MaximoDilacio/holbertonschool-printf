#include "main.h"
#include <stdarg.h>

/**
 * _printf - Función que imita el comportamiento de printf
 * @format: Cadena de formato con caracteres e identificadores de formato
 *
 * Return: Número total de caracteres impresos o -1 en caso de error
 */
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
	return (impresos);
}
