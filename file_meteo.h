// http://docs.moodle.org/22/en/Converting_files_to_UTF-8

#include <stdio.h>
#include <stdlib.h>
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

	// Encode To UTF-8
	char *encoder = "/bin/sh -c ./convert.sh";
	system(encoder);

	//		printf("Test file\n%s\n", content);

}