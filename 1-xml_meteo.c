#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parseStory (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"city"))) {
		    key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
		    printf("keyword: %s\n", key);
		    xmlFree(key);
 	    }
	cur = cur->next;
	}
    return;
}

static void parseDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	
	cur = xmlDocGetRootElement(doc);
	
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
	
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"weather"))){
			parseStory (doc, cur);
		}
		 
	cur = cur->next;
	}
	
	xmlFreeDoc(doc);
	return;
}

int main(int argc, char **argv) {

	char *docname;
		
	if (argc <= 1) {
		printf("Usage: %s docname\n", argv[0]);
		return(0);
	}

	docname = argv[1];
	parseDoc (docname);

	return (1);
}


/*


for (i=0; i < nodeset->nodeNr; i++) {
	keyword = xmlNodeListGetString(doc, nodeset->nodeTab[i]->xmlChildrenN
	printf("keyword: %s\n", keyword);
	xmlFree(keyword);
}









*/