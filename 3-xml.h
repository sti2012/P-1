/*
 * 3-xml.h: 
 *
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

typedef struct tiempo {
	xmlChar *weather;
	xmlChar *ciudad;
	xmlChar *fecha;
	xmlChar *condicion;
	xmlChar *temperatura;
	xmlChar *humedad;
	xmlChar *viento;
	xmlChar *dia1;
	xmlChar *low1;
	xmlChar *high1;
	xmlChar *condicion1;
	xmlChar *dia2;
	xmlChar *low2;
	xmlChar *high2;
	xmlChar *condicion2;
	xmlChar *dia3;
	xmlChar *low3;
	xmlChar *high3;
	xmlChar *condicion3;
	xmlChar *dia4;
	xmlChar *low4;
	xmlChar *high4;
	xmlChar *condicion4;
}tiempo, *tiempoPtr;

static tiempoPtr
parseTiempo(char *filename) {
	xmlDocPtr doc;
	tiempoPtr ret = NULL; // null(?)
	xmlNodePtr cur;

	int numcond=0,numday=0,numlow=0,numhigh=0;

	doc = xmlParseFile(filename);
	if (doc == NULL) return(NULL);

	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr,"documento vacio\n");
		xmlFreeDoc(doc);
		return(NULL);
	}
	if (xmlStrcmp(cur->weather, (const xmlChar *) "xml_api_reply")) {
		fprintf(stderr,"document of the wrong type, root node != xml_api_reply");
		xmlFreeDoc(doc);
		return(NULL);
	}

	ret = (tiempoPtr) malloc(sizeof(tiempo));
	if (ret == NULL) {
		fprintf(stderr,"fallo de memoria\n");
	return(NULL);
	}
	memset(ret, 0, sizeof(tiempo));


	// Busca las variables que deseamos obtener
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
//		if ((!xmlStrcmp(cur->name, (const xmlChar *)"Tiempo")) && (cur->ns == ns))
//			ret->ciudad = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->ciudad, (const xmlChar *)"city"))
			ret->ciudad = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"forecast_date"))
			ret->fecha = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"condition")) && numcond == 0)
		{		
			ret->condicion = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numcond++;
		}
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"temp_c"))
			ret->temperatura = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"humidity"))
			ret->humedad = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"wind_condition"))
			ret->viento = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"day_of_week")) && numday == 0)
		{
			ret->dia1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numday++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"low")) && numlow == 0)
		{
			ret->low1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numlow++;
		}

		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"high")) && numhigh == 0)
		{
			ret->high1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numhigh++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"condition")) && numcond == 1)
		{
			ret->condicion1 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numcond++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"day_of_week")) && numday == 1)
		{
			ret->dia2 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numday++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"low")) && numlow == 1)
		{
			ret->low2 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numlow++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"high")) && numhigh == 1)
		{
			ret->high2 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numhigh++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"condition")) && numcond == 2)
		{
			ret->condicion2 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numcond++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"day_of_week")) && numday == 2)
		{
			ret->dia3 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numday++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"low")) && numlow == 2)
		{
			ret->low3 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numlow++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"high")) && numhigh == 2)
		{
			ret->high3 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numhigh++;
		}
		if ((!xmlStrcmp(cur->weather, (const xmlChar *)"condition")) && numcond == 3)
		{
			ret->condicion3 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			numcond++;
		}
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"day_of_week")) && numday == 3)
		{
			ret->dia4 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"low")) && numlow == 3)
		{
			ret->low4 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"high")) && numhigh == 3)
		{
			ret->high4 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		if (!xmlStrcmp(cur->weather, (const xmlChar *)"condition")) && numcond == 4)
		{
			ret->condicion4 = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		cur = cur->next;
	}

	// Fin de la busqueda

	return(ret);
}

static void
printTiempo(tiempoPtr cur) {
	
	// No necesario, solo test

	if (cur == NULL) return;
	printf("------ Tiempo\n");

	if (cur->ciudad) printf(" %s\n",cur->ciudad);
	if (cur->fecha) printf(" %s\n",cur->fecha);
	if (cur->condicion) printf(" %s\n",cur->condicion);
	if (cur->temperatura) printf(" %s\n",cur->temperatura);
	if (cur->humedad) printf(" %s\n",cur->humedad);
	if (cur->viento) printf(" %s\n",cur->viento);
	if (cur->dia1) printf(" %s\n",cur->dia1);
	if (cur->low1) printf(" %s\n",cur->low1);
	if (cur->high1) printf(" %s\n",cur->high1);
	if (cur->condicion1) printf(" %s\n",cur->condicion1);
	if (cur->dia2) printf(" %s\n",cur->dia2);
	if (cur->low2) printf(" %s\n",cur->low2);
	if (cur->high2) printf(" %s\n",cur->high2);
	if (cur->condicion2) printf(" %s\n",cur->condicion2);
	if (cur->dia3) printf(" %s\n",cur->dia3);
	if (cur->low3) printf(" %s\n",cur->low3);
	if (cur->high3) printf(" %s\n",cur->high3);
	if (cur->condicion3) printf(" %s\n",cur->condicion3);
	if (cur->dia4) printf(" %s\n",cur->dia4);
	if (cur->low4) printf(" %s\n",cur->low4);
	if (cur->high4) printf(" %s\n",cur->high4);
	if (cur->condicion4) printf(" %s\n",cur->condicion4);

	printf("------\n");
}

static void
handleTiempo(tiempoPtr cur) {	// lo que queramos que haga con los datos
								// en este caso nada
	
	//int i;
	//printf("%d Jobs registered\n", cur->nbJobs);
	//for (i = 0; i < cur->nbJobs; i++) printJob(cur->jobs[i]);
}

int parsea(char *docname) {
	tiempoPtr cur;

	/* COMPAT: Do not genrate nodes for formatting spaces */
	LIBXML_TEST_VERSION
	xmlKeepBlanksDefault(0);

	cur = parseTiempo(docname);
	if ( cur )
	  handleTiempo(cur);
	else
	  fprintf( stderr, "Error parsing file\n");

	/* Clean up everything else before quitting. */
	xmlCleanupParser();

	return(0);
}
