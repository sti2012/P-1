#include <libxml/parser.h>
#include <libxml/xpath.h>

char *ciudad;
char *fecha;
char *condicion;
char *temperatura;
char *humedad;
char *viento;
char *dia1;
char *low1;
char *high1;
char *condicion1;
char *dia2;
char *low2;
char *high2;
char *condicion2;
char *dia3;
char *low3;
char *high3;
char *condicion3;
char *dia4;
char *low4;
char *high4;
char *condicion4;

xmlDocPtr
getdoc (char *docname) {
	xmlDocPtr doc;
	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully.\n");
		return NULL;
	}

	return doc;
}

xmlXPathObjectPtr
getnodeset (xmlDocPtr doc, xmlChar *xpath){
	
	xmlXPathContextPtr context;
	xmlXPathObjectPtr result;

	context = xmlXPathNewContext(doc);
	if (context == NULL) {
		printf("Error in xmlXPathNewContext\n");
		return NULL;
	}
	result = xmlXPathEvalExpression(xpath, context);
	xmlXPathFreeContext(context);
	if (result == NULL) {
		printf("Error in xmlXPathEvalExpression\n");
		return NULL;
	}
	if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
		xmlXPathFreeObject(result);
                printf("No result\n");
		return NULL;
	}
	return result;
}

int parsea(char *docname) {

	xmlDocPtr doc;
	xmlNodeSetPtr nodeset;
	xmlXPathObjectPtr result;
	int i;

	doc = getdoc(docname);

	result = getnodeset (doc, "/xml_api_reply/weather/forecast_information/city/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			ciudad = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("ciudad: %s\n", ciudad);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "/xml_api_reply/weather/forecast_information/forecast_date/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			fecha = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("fecha: %s\n", fecha);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "/xml_api_reply/weather/current_conditions/condition/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			condicion = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("condicion: %s\n", condicion);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "/xml_api_reply/weather/current_conditions/temp_c/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			temperatura = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("temperatura: %s\n", temperatura);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "/xml_api_reply/weather/current_conditions/humidity/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			humedad = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("humedad: %s\n", humedad);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "/xml_api_reply/weather/current_conditions/wind_condition/@data");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			viento = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("viento: %s\n", viento);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/day_of_week/@data)[1]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			dia1 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("dia1: %s\n", dia1);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/low/@data)[1]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			low1 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("low1: %s\n", low1);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/high/@data)[1]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			high1 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("high1: %s\n", high1);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/condition/@data)[1]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			condicion1 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("condicion1: %s\n", condicion1);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/day_of_week/@data)[2]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			dia2 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("dia2: %s\n", dia2);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/low/@data)[2]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			low2 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("low2: %s\n", low2);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/high/@data)[2]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			high2= xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("high2: %s\n", high2);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/condition/@data)[2]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			condicion2 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("condicion2: %s\n", condicion2);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/day_of_week/@data)[3]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			dia3 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("dia3: %s\n", dia3);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/low/@data)[3]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			low3 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("low3: %s\n", low3);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/high/@data)[3]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			high3 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("high3: %s\n", high3);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/condition/@data)[3]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			condicion3 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("condicion3: %s\n", condicion3);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/day_of_week/@data)[4]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			dia4 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("dia4: %s\n", dia4);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/low/@data)[4]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			low4 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("low4: %s\n", low4);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/high/@data)[4]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			high4 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("high4: %s\n", high4);
		}
		xmlXPathFreeObject (result);
	}

	result = getnodeset (doc, "(/xml_api_reply/weather/forecast_conditions/condition/@data)[4]");
	if (result) {
		nodeset = result->nodesetval;
		for (i=0; i < nodeset->nodeNr; i++) {
			condicion4 = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenNode, 1);
		printf("condicion4: %s\n", condicion4);
		}
		xmlXPathFreeObject (result);
	}

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return (1);
}