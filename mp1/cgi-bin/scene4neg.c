#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
//SQL 


	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body>");
	printf("	<script type=\"text/javascript\">window.location.replace(\"scene5.cgi\");</script>");
	printf("</body></html>");
	return 0;
}
