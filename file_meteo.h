// Ejemplo: http://docs.moodle.org/22/en/Converting_files_to_UTF-8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int guarda(char const *content) // Nos guarda los datos pasados a la funcion en un fichero llamado tiempo.xml
{
	FILE* f;

	f = fopen("tiempo.xml","w"); // Abre el archivo con permisos de escritura (w = write)
	if (f == NULL) // Si no se abre el fichero:
	{
		printf("Error al abrir el fichero");
	}
	else // Si se abrió correctamente escribimos el texto en el fichero
	{
		fprintf(f, "%s", content);
	}
	fflush(f);
	fclose(f);

	// Encode To UTF-8
	char *encoder = "/bin/sh -c ./convert.sh"; // Comando para abrir el archivo shell
	system(encoder); // Ejecuta el archivo shell convert.sh (Necesita permisos de ejecucion)
}