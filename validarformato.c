#include "main.h"
#include <stdarg.h>

/**
 * manejar_formato - Maneja los diferentes formatos de impresión en _printf
 * @formato: Caracter que indica el tipo de dato a imprimir
 * @argumentos: Lista de argumentos que contiene el valor a imprimir
 *
 * Return: Número de caracteres impresos
 */
int manejar_formato(char formato, va_list argumentos)
{
	int count = 0;

	switch (formato)
	{
	case 'd':
	case 'i':
		count += imprimir_numero(va_arg(argumentos, int));
		break;
	case 'x':
		count += imprimir_hexadecimal(va_arg(argumentos, unsigned int), 0);
		break;
	case 'X':
		count += imprimir_hexadecimal(va_arg(argumentos, unsigned int), 1);
		break;
	case 's':
		count += imprimir_string(va_arg(argumentos, char *));
		break;
	case 'c':
		count += _putchar((char)va_arg(argumentos, int));
		break;
	case 'p':
		count += imprimir_direccion(va_arg(argumentos, void *));
		break;
	case '%':
		count += _putchar('%');
		break;
	default:
		count += _putchar('%');
		count += _putchar(formato);
	}

	return (count);
}
