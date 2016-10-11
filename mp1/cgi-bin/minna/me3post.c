#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size=0;
	char *data = 0;
	printf("Content-type:text/html\n\n");
	printf("<html><head><title>ME3 - POST Parsing</title></head><body>");

	data = getenv("CONTENT_LENGTH");
	if (data)
		size = atoi(data);
	while (size--)
		printf("%c", fgetc(stdin));

	printf("<br><a href=/~rusty/me3post.html>Back</a>");
	printf("<body></html>");
	return 0;
}
