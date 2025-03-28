#include "main.h"
#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

void imprimir_string(const char *string)
{
    while (*string)
    {
        _putchar(*string);
        string++;
    }
}

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
        _putchar(buffer[indice]);
    }
}

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
        _putchar(buffer[indice]);
    }
}

void imprimir_direccion(void *puntero)
{
    uintptr_t direccion = (uintptr_t)puntero;
    imprimir_string("0x");
    imprimir_hexadecimal(direccion, 0);
}

