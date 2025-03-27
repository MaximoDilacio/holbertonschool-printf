#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

/**
 * imprimir_cadena - Imprime una cadena de caracteres.
 * @cadena: Puntero a la cadena a imprimir.
 */
void imprimir_cadena(const char *cadena)
{
	while (*cadena)
	{
		write(1, cadena, 1);
		cadena++;
	}
}

/**
 * imprimir_numero - Imprime un número entero.
 * @numero: Número a imprimir.
 */
void imprimir_numero(int numero)
{
	char buffer[12];
	int indice = 0;
	int es_negativo = 0;

	if (numero < 0)
	{
		es_negativo = 1;
		numero = -numero;
	}
	do {
		buffer[indice++] = (numero % 10) + '0';
		numero /= 10;
	} while (numero > 0);
	if (es_negativo)
	{
		buffer[indice++] = '-';
	}
	while (indice--)
	{
		write(1, &buffer[indice], 1);
	}
}

/**
 * imprimir_unsigned - Imprime un número sin signo.
 * @numero: Número sin signo a imprimir.
 */
void imprimir_unsigned(unsigned int numero)
{
	char buffer[12];
	int indice = 0;

	do {
		buffer[indice++] = (numero % 10) + '0';
		numero /= 10;
	} while (numero > 0);
	while (indice--)
	{
		write(1, &buffer[indice], 1);
	}
}

/**
 * imprimir_octal - Imprime un número en formato octal.
 * @numero: Número sin signo a imprimir en octal.
 */
void imprimir_octal(unsigned int numero)
{
	char buffer[12];
	int indice = 0;

	do {
		buffer[indice++] = (numero % 8) + '0';
		numero /= 8;
	} while (numero > 0);
	while (indice--)
	{
		write(1, &buffer[indice], 1);
	}
}

/**
 * imprimir_hexadecimal - Imprime un número en hexadecimal.
 * @numero: Número sin signo a imprimir en hexadecimal.
 * @mayuscula: Si es 1, usa mayúsculas; si es 0, usa minúsculas.
 */
void imprimir_hexadecimal(unsigned int numero, int mayuscula)
{
	char buffer[12];
	int indice = 0;
	char base = mayuscula ? 'A' : 'a';

	do {
		int digito = numero % 16;

		if (digito < 10)
			buffer[indice++] = digito + '0';
		else
			buffer[indice++] = digito - 10 + base;
		numero /= 16;
	} while (numero > 0);
	while (indice--)
	{
		write(1, &buffer[indice], 1);
	}
}

/**
 * imprimir_direccion - Imprime una dirección de memoria en formato hexadecima.
 * @puntero: Direccion de memoria a imprimi
 */
void imprimir_direccion(void *puntero)
{
	uintptr_t direccion = (uintptr_t)puntero;

	write(1, "0x", 2);
	imprimir_hexadecimal(direccion, 0);
}

/**
 * _printf - Funcion personalizada similar a printf
 * @formato: Cadena de formato con especificadores
 * @...: Argumentos variables
 *
 * Return: Numero de caracteres impreso
 */
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
			switch (*formato)
			{
			case 'd':
			case 'i':
				imprimir_numero(va_arg(argumentos, int));
				break;
			case 'u':
				imprimir_unsigned(va_arg(argumentos, unsigned int));
				break;
			case 'o':
				imprimir_octal(va_arg(argumentos, unsigned int));
				break;
			case 'x':
				imprimir_hexadecimal(va_arg(argumentos, unsigned int), 0);
				break;
			case 'X':
				imprimir_hexadecimal(va_arg(argumentos, unsigned int), 1);
				break;
			case 's':
				imprimir_cadena(va_arg(argumentos, char *));
				break;
			case 'c':
			{
				char caracter = (char)va_arg(argumentos, int);

				write(1, &caracter, 1);
				break;
			}
			case 'p':
				imprimir_direccion(va_arg(argumentos, void *));
				break;
			case '%':
				write(1, "%", 1);
				break;
			default:
				write(1, "%", 1);
				write(1, formato, 1);
			}
		}
		else
		{
			write(1, formato, 1);
		}
		formato++;
		caracteres++;
	}
	va_end(argumentos);
	return (caracteres);
}

