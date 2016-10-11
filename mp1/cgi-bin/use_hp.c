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
	query = calloc(QS_LEN, 1);
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

	MYSQL_RES *result = 0;
	MYSQL_ROW row = 0;
	MYSQL *con = mysql_init(NULL);
	mysql_real_connect(con, "localhost", "root", "root", "mp", 0, NULL, 0);

	if (atoi(act)>10)
	{
		strcpy(query, "SELECT hp,item1 FROM savetemp WHERE id=");
		strcat(query, act);
	}
	else
	{
		strcpy(query, "SELECT hp,item1 FROM save WHERE id=");
		strcat(query, act);
	}
	mysql_query(con, query);

	result = mysql_store_result(con);
	row = mysql_fetch_row(result);


	int toprint=0;
	int pots = atoi(row[1]);
	char health_up[2], hp_down[2];
	if (pots<=0)
		toprint=1;
	else
	{

		sprintf(health_up, "%d", atoi(row[0])+1);
		sprintf(hp_down, "%d", atoi(row[1])-1);
		if (atoi(act)>10)
		{
			strcpy(query, "UPDATE savetemp SET hp=");
			strcat(query, health_up);
			strcat(query, ",item1=");
			strcat(query, hp_down);
		}
		else
		{
			strcpy(query, "UPDATE save SET hp=");
			strcat(query, health_up);
			strcat(query, ",item1=");
			strcat(query, hp_down);
		}
	}
	mysql_query(con, query);
	mysql_free_result(result);
	mysql_close(con);
	

	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body>");
	printf("%s %s", act, cur_scene);
	if (toprint)
		printf("	<script type=\"text/javascript\">alert(\"You don\'t have enough Health Potion\")</script>");
	else
		printf("	<script type=\"text/javascript\">alert(\"Sucess! +1 Health\")</script>");
	printf(" 	<script type=\"text/javascript\">post(\'%s\', {\'%s\': %s});</script>", cur_scene, cur_scene, act);
	printf("</body></html>");
}
