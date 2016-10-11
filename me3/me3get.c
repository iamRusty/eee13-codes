#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *data;
	printf("Content-type:text/html\n\n");
	
	printf("<html><head><title>ME3 - GET Parsing</title></head><body>");
	data = getenv("QUERY_STRING");
	if (data)
	{
		printf("%s", data);
	}
	printf("<br><a href=/me3/me3.html>Back</a>");
	printf("</body></html>");
}
