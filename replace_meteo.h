#include <stdio.h>

void replaza(char *str)
{
	while(*str) {
		if(*str== ' ') 
		{
			*str = '-';
		}
		else 
			;
		str++;
	}
}