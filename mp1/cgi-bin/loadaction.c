#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Length of Query String
#define QS_LEN 65536

int main(int argc, char *argv[], char *env[])
{
	int health, money, hp, sr, trr, i, num_fields;
	char *query;

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
	query = calloc(QS_LEN,1);
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
int a;
char *b;
b = calloc(QS_LEN, 1);
	sscanf(act, "%i-%s", &a, b);

char str[15];
sprintf(str, "%d", a);


	MYSQL_RES *result = 0;
	MYSQL_ROW row = 0;
	MYSQL *con = mysql_init(NULL);
	mysql_real_connect(con, "localhost", "root", "root", "mp", 0, NULL, 0);

	mysql_query(con, "DELETE FROM savetemp");
	
	strcpy(query, "SELECT * FROM save WHERE id=");
	strcat(query, str);
	mysql_query(con, query);
	result = mysql_store_result(con);
	row = mysql_fetch_row(result);

	strcpy(query, "INSERT INTO savetemp VALUES(");
	strcat(query, "11,\"");
	strcat(query, row[1]);
	strcat(query, "\",");
	strcat(query, row[2]);
	strcat(query, ",");	
	strcat(query, row[3]);
	strcat(query, ",");
	strcat(query, row[4]);
	strcat(query, ",");
	strcat(query, row[5]);
	strcat(query, ",");
	strcat(query, row[6]);
	strcat(query, ",\"");
	strcat(query, row[7]);
	strcat(query, "\",");
	strcat(query, str);
	strcat(query, ")");
	
	
	mysql_query(con, query);
	mysql_free_result(result);
	mysql_close(con);
	





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
	printf("	<body onload=\"post(\'%s\', {\'%s\': \'11\'})\">", b,b);
	printf("%s %s %s<br>%s", str,b, cur_scene, query);
//	printf("<form action=\"%s\" method=\"POST\">",b);
//	printf("<input type=submit name=\"%s\" value=\"%i\">", b,a);
//	printf("</form>");
	printf("	</body></html>");
return 0;
}
