#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *env[])
{
	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body bgcolor=red>");
	printf("	<script type=\"text/javascript\">setTimeout(function(){window.location.replace(\"scene4.cgi\");}, 5000);</script>");
	printf("</body></html>");
	return 0;
}
