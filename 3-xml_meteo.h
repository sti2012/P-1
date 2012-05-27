
/**
 * print_element_names:
 * @a_node: the initial xml node to consider.
 *
 * Prints the names of the all the xml elements
 * that are siblings or children of a given xml node.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

typedef struct tiempo{
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

static void
printTiempo(tiempoPtr ret) {
	if (ret == NULL) return;
	printf("------ Tiempo\n");
	if (ret->ciudad) printf("	ciudad: %s\n", ret->ciudad);
	printf("test 213\n");
/*	if (cur->email) printf("	email: %s\n", cur->email);
	if (cur->company) printf("	company: %s\n", cur->company);
	if (cur->organisation) printf("	organisation: %s\n", cur->organisation);
	if (cur->smail) printf("	smail: %s\n", cur->smail);
	if (cur->webPage) printf("	Web: %s\n", cur->webPage);
	if (cur->phone) printf("	phone: %s\n", cur->phone);*/
	printf("------\n");
}


static tiempoPtr
parseTiempo(char *docname, xmlNode * a_node)
{
	xmlNode *cur_node = NULL;
	xmlDocPtr doc;
	tiempoPtr ret;// = NULL; // null(?)
	doc = xmlParseFile(docname);
// cur = xmlDocGetRootElement(doc);
	ret = (tiempoPtr) malloc(sizeof(tiempo));
	memset(ret, 0, sizeof(tiempo));

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			// printf("node type: Element, name: %s\n", cur_node->name);
			printf("node type: Element, name: %s\n", cur_node->name);

			if (!xmlStrcmp(cur_node->name, (const xmlChar *)"city"))
			{	
				printf("test\n");
				// parseContent("ciudad", cur_node->xmlChildrenNode);
			//	ret->ciudad = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
				ret->ciudad = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
				printf("test 123\n");
			//	char *test = ret->ciudad;
			//	test = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
			//	printf("Encontrado city: %s\n", test);
			//	sprintf(test,"Encontrado city: %s\n", ret->ciudad);
			//	printTiempo(cur_node->children);
				printTiempo(ret->ciudad);
			//	printf("%s\n", test);
				// printf("Encontrado city: %s\n", xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1));
				// printf("%s\n", xmlNodeListGetString(doc1, cur_node->xmlChildrenNode, 1));
			}
		parseTiempo(docname, cur_node->children);
		}
	}
}


/*
			ret->ciudad = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
			// printf("Encontrado city: %s\n", cur_node->xmlChildrenNode);
			printf("Encontrado city: %s\n", ret->nombre);
*/
/*
	root_element = xmlDocGetRootElement(doc);

	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	doc = xmlReadFile(docname, NULL, 0);

	parseTiempo(root_element);
*/
//}



/*
static tiempoPtr
parseTiempo(xmlNode * a_node)
{
	xmlNode *cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			// printf("node type: Element, name: %s\n", cur_node->name);
			printf("node type: Element, name: %s\n", cur_node->name);

			// char *test = xmlNodeListGetString(doc2, cur_node->xmlChildrenNode, 1);
			// printf("%s\n", test);
			if (!xmlStrcmp(cur_node->name, (const xmlChar *)"city"))
			{	
				parseContent("ciudad", cur_node->xmlChildrenNode);
				// char *test = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
				// ret->ciudad = xmlNodeListGetString(doc1, cur->xmlChildrenNode, 1);
				// printf("Encontrado city: %s\n", cur_node->xmlChildrenNode);
		//		printf("Encontrado city: %s\n", xmlNodeListGetString(cur_node, cur_node->xmlChildrenNode, 1));
				// printf("%s\n", xmlNodeListGetString(doc1, cur_node->xmlChildrenNode, 1));
			}
		}
		parseTiempo(cur_node->children);
	}
}

*/


int parsea(char *docname)
{
	tiempoPtr cur;
	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	/*parse the file and get the DOM */
	doc = xmlReadFile(docname, NULL, 0);

	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);
	cur = parseTiempo(docname, root_element);
	//xmlFreeDoc(doc);
	//xmlCleanupParser();
}