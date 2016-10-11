#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char *data;
	char *name[50], value1[50], *contain;
	float ave;
	int count = 0, count2=0;
	int subj1, subj2, subj3, subj4, min, max;
	int len = 0;
	int howmanycheckboxes;
	printf("Content-type:text/html\n\n");

	printf("<html><head><title>ME4 - GET</title></head><body>");
	data = getenv("QUERY_STRING");


	char delimiter = '&';
	contain = strtok(data, &delimiter);
	name[0] = contain;

	while (contain != NULL)
	{
		contain = strtok(NULL, &delimiter);
		name[count+1] = contain;
		count++;
	}

	if (count<6)
	{
			printf("Invalid input. One or more of the input was left blank<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
	}
	for (count2 = 0; count2<5; count2++)
	{
		if (strlen(name[count2])==5)
		{
			printf("Invalid input. One or more of the input was left blank<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
		}
	}

	sscanf(name[0], "name=%s", value1);

	len = strlen(value1);
	
	int countlen;
	for (countlen=0; countlen<len; countlen++)
	{
		if (value1[countlen]=='+')
			value1[countlen] = ' ';
	}

	char value2[20];
	sscanf(name[1], "sub1=%s", value2);
	len = strlen(value2);
	
	for (countlen = 0; countlen < len; countlen++)
	{
		if (isdigit(value2[countlen])==0)
		{
			printf("Invalid integer input (Subject1).<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
		}		
	}
	
	subj1 = atoi(value2);

	sscanf(name[2], "sub2=%s", value2);
	len = strlen(value2);

	for (countlen = 0; countlen < len; countlen++)
	{
		if (isdigit(value2[countlen])==0)
		{
			printf("Invalid integer input (Subject2).<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
		}
	}

	subj2 = atoi(value2);

	sscanf(name[3], "sub3=%s", value2);
	len = strlen(value2);

	for (countlen = 0; countlen < len; countlen++)
	{
		if (isdigit(value2[countlen])==0)
		{
			printf("Invalid integer input (Subject3).<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
		}
	}

	subj3 = atoi(value2);

	sscanf(name[4], "sub4=%s", value2);
	len = strlen(value2);

	for (countlen = 0; countlen < len; countlen++)
	{
		if (isdigit(value2[countlen])==0)
		{
			printf("Invalid integer input (Subject4).<br>");
			printf("<br><a href=/me4check.html>Back</a>");
			return 0;
		}
	}

	subj4 = atoi(value2);




	//output
	printf("Hello %s!<br><br>", value1);
	printf("Grade 1: %d<br>", subj1);
	printf("Grade 2: %d<br>", subj2);
	printf("Grade 3: %d<br>", subj3);
	printf("Grade 4: %d<br>", subj4);

	for (howmanycheckboxes=0; howmanycheckboxes<(count-5); howmanycheckboxes++)
	{
	sscanf(name[howmanycheckboxes+5], "oper=%s", value2);
	if ((strcmp(value2, "ave"))==0)
	{
		ave = (float) (subj1 + subj2 + subj3 + subj4)/4;
		printf("The average is %f.<br>", ave);
	}

	else if ((strcmp(value2, "min"))==0)
	{
		min = subj1;
		if (subj2<min)
			min = subj2;
		if (subj3<min)
			min=subj3;
		if (subj4<min)
			min=subj3;
		printf("The minimum is %i.<br>", min);
	}

	else
	{
		max = subj1;
		if (subj2>max)
			max = subj2;
		if (subj3>max)
			max=subj3;
		if (subj4>max)
			max=subj3;
		printf("The maximum is %d.<br>", max);
	}
	}
	printf("<br><a href=/me4check.html>Back</a>");
	printf("</body></html>");

	return 0;
}
