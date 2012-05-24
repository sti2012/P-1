#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

static void parseDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);

	/*
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	*/

	cur = xmlDocGetRootElement(doc);

	/*
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "xml_api_reply")) {
		fprintf(stderr,"document of the wrong type, root node != xml_api_reply");
		xmlFreeDoc(doc);
		return;
	}
	*/

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"weather"))){
			parsea (doc, cur);
		} 
		cur = cur->next;
	}
	
	xmlFreeDoc(doc);
	return;
}