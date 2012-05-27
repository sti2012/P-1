#include <stdio.h>
#include <string.h>

int guarda(char const *content)
{
	FILE* f;

	f = fopen("tiempo.xml","w");
	if (f == NULL)
	{
		printf("Error al abrir el fichero");
	}
	else
	{	// Si se abrió correctamente escribimos el texto en el fichero
		fprintf(f, "%s", content);
	}
	fflush(f);
	fclose(f);

			printf("Test file\n%s\n", content);

}