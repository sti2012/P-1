
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

static tiempoPtr
parseTiempo(xmlNode * a_node)
{
	xmlNode *cur_node = NULL;

//	xmlDocPtr doc1;
	tiempoPtr ret = NULL; // null(?)
	///////////////////////////////////////// xmlNodePtr cur;

	// int numcond=0, numday=0, numlow=0, numhigh=0;

// doc1 = xmlParseFile("tiempo.xml");
	// if (doc1 == NULL) return(NULL);

	////////////////////////////////////////// cur = xmlDocGetRootElement(doc1);

	/*
	if (cur == NULL) {
		fprintf(stderr,"Error: Documento vacio\n");
		xmlFreeDoc(doc1);
		return(NULL);
	}
	if (xmlStrcmp(cur->name, (const xmlChar *) "xml_api_reply")) {
		fprintf(stderr,"Document of the wrong type, root node != xml_api_reply");
		xmlFreeDoc(doc1);
		return(NULL);
	}
	*/

	ret = (tiempoPtr) malloc(sizeof(tiempo));

	/*
	if (ret == NULL) {
		fprintf(stderr,"Fallo de memoria\n");
	return(NULL);
	}
	*/

	memset(ret, 0, sizeof(tiempo));

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			// printf("node type: Element, name: %s\n", cur_node->name);
			printf("node type: Element, name: %s\n", cur_node->name);

			// char *test = xmlNodeListGetString(doc2, cur_node->xmlChildrenNode, 1);
			// printf("%s\n", test);
			if (!xmlStrcmp(cur_node->name, (const xmlChar *)"city"))
			{	
				parseContent(cur_node->xmlChildrenNode);
				// char *test = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
				// ret->ciudad = xmlNodeListGetString(doc1, cur->xmlChildrenNode, 1);
				// printf("Encontrado city: %s\n", cur_node->xmlChildrenNode);
				printf("Encontrado city: %s\n", xmlNodeListGetString(cur_node, cur_node->xmlChildrenNode, 1));
				// printf("%s\n", xmlNodeListGetString(doc1, cur_node->xmlChildrenNode, 1));
			}
		}
		parseTiempo(cur_node->children);
	}
}
/*

if (ctxt->node == NULL)
 	    value = NULL;
 		else
 	    value = xmlNodeGetContent(node); 

*/

int parsea(char *docname)
{

	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;

	/*parse the file and get the DOM */
	doc = xmlReadFile(docname, NULL, 0);

	if (doc == NULL)
	{
		printf("error: could not parse file %s\n",docname);
	}

	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);

	parseTiempo(root_element);

	/*free the document */
	xmlFreeDoc(doc);


/*


	printf("Test parsea\n%s\n", docname);
									
	cur = parseTiempo(docname);		

*/


	xmlCleanupParser();
}