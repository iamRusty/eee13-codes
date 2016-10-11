#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Length of Query String
#define QS_LEN 65536

int main(int argc, char *argv[], char *env[])
{
//MYSQL shizzle

	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body><script type=\"text/javascript\">window.location.replace(\"scene7.cgi\");</script>");
	printf("</body></html>");
	return 0;
}
