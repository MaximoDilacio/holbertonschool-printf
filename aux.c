#include "main.h"
#include <unistd.h>
#include <stdint.h>

/**
 * _putchar - Escribe un solo carácter en la salida estándar
 * @c: Carácter a escribir
 *
 * Return: El número de caracteres escritos (siempre 1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * imprimir_string - Imprime una cadena de caracteres
 * @string: Cadena de caracteres a imprimir
 *
 * Return: El número de caracteres impresos
 */
int imprimir_string(char *string)
{
	int count = 0;

	if (!string)
		string = "(null)"; /* Manejo de puntero nulo */

	while (*string)
	{
		_putchar(*string);
		string++;
		count++;
	}

	return (count);
}

/**
 * imprimir_numero - Imprime un número entero
 * @n: Número entero a imprimir
 *
 * Return: El número de caracteres impresos
 */
int imprimir_numero(int n)
{
	int caracteres = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		caracteres++;
	}

	if (n / 10)
		caracteres += imprimir_numero(n / 10);

	_putchar(n % 10 + '0');
	caracteres++;

	return (caracteres);
}

/**
 * imprimir_hexadecimal - Convierte un número a hexadecimal e imprime
 * @numero: El número entero sin signo a convertir
 * @mayuscula: Define si la salida es en mayúsculas (1) o minúsculas (0)
 *
 * Return: El número de caracteres impresos
 */
int imprimir_hexadecimal(unsigned int numero, int mayuscula)
{
	int count = 0;
	char buffer[16];
	int i = 0;
	char *hex = mayuscula ? "0123456789ABCDEF" : "0123456789abcdef";

	if (numero == 0)
	{
		_putchar('0');
		return (1);
	}

	while (numero > 0)
	{
		buffer[i++] = hex[numero % 16];
		numero /= 16;
	}

	while (i--)
	{
		_putchar(buffer[i]);
		count++;
	}

	return (count);
}

/**
 * imprimir_direccion - Convierte una dirección de memoria a formato hexadecimal
 * y la imprime
 * @puntero: La dirección de memoria a imprimir
 *
 * Return: El número de caracteres impresos
 */
int imprimir_direccion(void *puntero)
{
	unsigned long int addr = (unsigned long int)puntero;
	int count = 0;

	if (!puntero)
	{
		return (imprimir_string("(nil)"));
	}

	count += imprimir_string("0x");
	count += imprimir_hexadecimal(addr, 0);

	return (count);
}

