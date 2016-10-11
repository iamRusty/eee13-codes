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
	printf("act:%s <br>cur_scene:%s %i", act, cur_scene, count2);

		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");
		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");
		printf("				<form action=\"credits.cgi\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("				</form>");
		printf("				<dd>");
		if (strcmp(cur_scene, "index.html")==0)
			printf("			<form action=\"../index.html\" method=POST>");
		else
			printf("			<form action=\"%s\" method=POST>", cur_scene);
		printf("					<input type=\"submit\" style=\"padding: 10px 65px;\" value=\"Back\" name=\"Dead\">");
		printf("					<input type=hidden name=\"%s\" value=\"%s\">", cur_scene, act);
		printf("				</form> </dd>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
//	}


		printf("		<div class=\"main-container\">");
		printf("			<div class=\"main\">");
		printf("				<div class=\"main-one\">");
		printf("					<center>");

	MYSQL_RES *result = 0;
	MYSQL_ROW row = 0;
	MYSQL *con = mysql_init(NULL);

	mysql_real_connect(con, "localhost", "root", "root", "mp", 0, NULL, 0);
	mysql_query(con, "SELECT COUNT(*) FROM save");
	result = mysql_store_result(con);
	row = mysql_fetch_row(result);

char slot[2];	
query = calloc(QS_LEN, 1);
	sprintf(slot, "%d", atoi(row[0])+1);

	if (atoi(row[0])<10)
	{
		mysql_query(con, "SELECT * FROM savetemp");
		result = mysql_store_result(con);
		row = mysql_fetch_row(result);

		strcpy(query, "INSERT INTO save VALUES(");
		strcat(query, slot);
		strcat(query, ", CONCAT(curdate(),' ', curtime()), ");
		strcat(query, row[2]);
		strcat(query, ", ");
		strcat(query, row[3]);
		strcat(query, ",");
		strcat(query, row[4]);
		strcat(query, ",");
		strcat(query, row[5]);
		strcat(query, ",");
		strcat(query, row[6]);
		strcat(query, ",\"");
		strcat(query, cur_scene);
		strcat(query, "\")");
		mysql_query(con, query);
		printf("<script type=\"text/javascript\">alert(\"Successfully Saved\");</script>");
		if (strcmp(cur_scene, "scene6.cgi")==0)
			printf("<script type=\"text/javascript\">post(\'scene7.cgi\', {'scene7.cgi': %s});</script>",act);
		else
			printf("<script type=\"text/javascript\">post(\'%s\', {'%s': %s});</script>", cur_scene, cur_scene, act);
	}
	else
	{
		printf("<script type=\"text/javascript\">alert(\"Unfortunately, the pie is getting smaller and smaller. There's no more room for another save instance unless you replace one.\");</script>");
		mysql_query(con, "SELECT id, name,cur_scene FROM save");
	result = mysql_store_result(con);

	num_fields = mysql_num_fields(result);
	printf("<h1>Save</h1><form action=\"saveaction.cgi\" method=\"post\"><br><table border=1><td align=center>Instance</td><td>to Replace?</td></tr>");
	while ((row = mysql_fetch_row(result))) 
  	{
		printf("<tr>"); 
        	printf("<td align=center>%s</td>", row[1]); 
			printf("<td align=center><input type=\"radio\" name=\"toload\" value=\"%s-%s\"></td>", row[0],row[2]); 
         printf("</tr>"); 
  	}
	printf("</table><input type=submit value=\"Load\"></form>");
  mysql_free_result(result);
  mysql_close(con);

		printf("				</div>");
		printf("			</div>");
		printf("		</div>");
		printf("	");
		printf("	");
	}
//		}
	return 0;
}
