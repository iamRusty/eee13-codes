#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Length of Query String
#define QS_LEN 65536

int main(int argc, char *argv[], char *env[])
{
//------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------
	char *post_size;
	int size_ctr,size_ctr2;	

	char *data;
	char *token;

	char *key, *value, *act, *cur_scene;

    char *plus;
    int count;   
	int count_dia = 0;

// Allocation of memory	
	post_size = calloc(QS_LEN, 1);

	data = calloc(QS_LEN, 1);
	token = calloc(QS_LEN, 1);

	key = calloc(QS_LEN, 1);
	value = calloc(QS_LEN, 1);
	act = calloc(QS_LEN,1);
	cur_scene = calloc(QS_LEN,1);
	plus = calloc(QS_LEN, 1);


//POST to GET
	post_size = getenv("CONTENT_LENGTH");

	size_ctr = 0;
	if (post_size)
		size_ctr = atoi(post_size);

	size_ctr2 = 0;
	while (size_ctr--) 
	{
		data[size_ctr2] = fgetc(stdin);
		size_ctr2++;
	}
int count2 =  0;
//Parsing of GET		

	token = strtok (data,"&");
	while (token != NULL) 
	{
		sscanf(token, "%[^=]=%65536s", key, value); //Stores values before '=' in key and values after '=' in value
//Correction of + to space
        strcpy(plus,value);
        count = 0;
        while (plus[count] != '\0' ) 
		{
			if (plus[count]=='+') 
				plus[count]=' ';
			count++;
		}
      
		strcpy(value,plus);
		strcpy(cur_scene, key);
		strcpy(act,value);
        //strcpy(value, "\0");
		count2++;
		token = strtok (NULL, "&");
	}
if (strcmp(act, "New")==0)
	strcpy(act,"Scene1");
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//stylesheet file should be placed on localhost html directory (eg. /var/www/html)		printf("	");
//--------------------------------------ALL----------------------------------------

	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body>");
//	printf("act:%s <br>cur_scene:%s %i", act, key, count2);

//	if (strcmp(act,"Dead") == 0) 
//	{
		printf("<script type=\"text/javascript\">setTimeout(function(){window.location.replace(\"credits.cgi\");}, 5000);</script>");
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("					<form action=\"../index.html\" method=\"POST\">");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("					</form>");
		printf("					<form action=\"load.cgi\" method=\"POST\">");
		printf("						<dd> <input type=\"submit\" name=\"dead.cgi\" style=\"padding: 10px 72px;\" value=\"Load\"> </dd>");
		printf("					</form>");
		printf("					<form action=\"credits.cgi\" method-POST\">");
		printf("						<dd> <input type=\"submit\" name=\"dead.cgi\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("					</form>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> 0 </td> </tr> </dd>");
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");
//	}
//	{
		printf("		<div class=\"main-container\">");
		printf("			<div class=\"main\">");
		printf("				<div class=\"main-challenge\">");
		printf("	<img src=\"../assets/you_are_dead.jpg\" height=\"488\" width=\"1060\" ></img>");
		printf("				</div>");
		printf("				<div class=\"main-choices\">");
		printf("				</div>");
		printf("			</div>");
		printf("		</div>");
//	}


return 0;
}
