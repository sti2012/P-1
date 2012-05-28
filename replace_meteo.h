#include <stdio.h>

void replaza(char *str)
{
	while(*str) {
		if(*str== ' ') 
		{
//			printf("%c", '-');
//			printf("%c", 'U+2013');
//			printf("%c", 'U+002D');
//			printf("%s", '%20');
//			printf("%c", '-');
			*str = '-';
		}
		else 
			;
//			printf("%c", *str);
		str++;
	}
}