#include <stdio.h>

void replaza(char *str)
{
	while(*str) { // Mientras que haya letras
		if(*str== ' ') // Si hay un espacio:
		{
			*str = '-'; // Se cambia a guion
		}
		else  // Si no:
			; // No hacemos nada
		str++; // Siguiente letra
	}
}