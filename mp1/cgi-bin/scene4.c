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
	query = calloc(QS_LEN, 1);

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
	if (atoi(act)>10)
		strcpy(query, "SELECT hp,item1,item2,item3,favor FROM savetemp WHERE id=");		
	else
		strcpy(query, "SELECT hp,item1,item2,item3,favor FROM save WHERE id=");
	strcat(query, act);
	mysql_real_connect(con, "localhost", "root", "root", "mp", 0, NULL, 0);
		mysql_query(con, query);
	result = mysql_store_result(con);

	num_fields = mysql_num_fields(result);
	printf("<table border=1><tr><td>name</td><td>price</td></tr>");
	while ((row = mysql_fetch_row(result))) 
  	{
		health=atoi(row[0]);
		money=atoi(row[4]);
		hp=atoi(row[1]);
		sr=atoi(row[2]);
		trr=atoi(row[3]);	
  	}
  mysql_free_result(result);
  mysql_close(con);





//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//stylesheet file should be placed on localhost html directory (eg. /var/www/html)		printf("	");
//--------------------------------------ALL----------------------------------------

	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("	<head>");
	printf("		<title>I Hack for lulz, do I?</title>");
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	<link rel=\"icon\" href=\"../assets/hack.ico\">");
	printf("	</head>");
	printf("	<body onload=\"createcookie()\">");
	//--SCENES---------------------------------------------------------------
//	{	
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");
		printf("				<form action=\"store.cgi\" method=POST>");		
		printf("						<dd> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 70.5px;\" value=\"Store\"> </dd>", cur_scene);
		printf("			<input type=\"hidden\" name=\"%s\" value=\"%s\">", cur_scene, act);
		printf("				</form>");
		printf("						<dd> <table>");
		printf("							<tr>");
		printf("							<form action=\"load.cgi\" method=POST>");
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Load\"> </td>", cur_scene);
		printf("			<input type=\"hidden\" name=\"%s\" value=\"%s\">", cur_scene, act);
		printf("							</form>");
		printf("							<form action=\"save.cgi\" method=POST>");
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Save\"> </td>", cur_scene);
		printf("			<input type=\"hidden\" name=\"%s\" value=\"%s\">", cur_scene, act);
		printf("							</form>");
		printf("							</tr>");
		printf("						</table> </dd>");
		printf("					<form action=\"credits.cgi\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("					</form>");
		printf("				</form>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> %i </td> </tr> </dd>", health);
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");

		printf("		<div class=\"inventory-container\">");
		printf(" 			<div class=\"inventory\">");
		printf("				<dl> <table> <col width=\"150\"><col width=\"50\">");
		printf("					<dd> <tr>");
		printf("						<td> <span> Inventory </span> </td>");
		printf("						<td> %i </td>", money);
		printf("					</tr> </dd>");
		printf("				</table> ");
		printf("						<dl style=\" border: none;\"> <table> <col width=\"50\"><col width=\"100\"><col width=\"50\">");
		printf("							<dd> <tr>");
		printf("		<form action=\"use_hp.cgi\" method=POST>");
		printf("								<td> <span> %i </span> </td>", hp);
		printf("								<td> <span> HP </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 5px 15px;\" value=\"Use HP\"> </td>", cur_scene);
		printf("<input type=\"hidden\" name=\"%s\" value=\"%s\">", cur_scene, act);
		printf("</form>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> %i </span> </td>", sr);
		printf("								<td> <span> SR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 15px;\" value=\"Automatic\"> 	</td>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> %i </span> </td>", trr);
		printf("								<td> <span> TRR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 10px;\" value=\"Automatic\"> 	</td>");
		printf("							</tr> </dd>");
		printf("						</dl>");
		printf("				</table> </dl> ");
		printf("			</div> ");
		printf("		</div>");	

//main
		printf("		<div class=\"main-container\">");
		printf("			<div class=\"main\">");
		printf("				<div class=\"main-challenge\">");
		printf("	<img src=\"../assets/main_room.jpg\" height=\"488\" width=\"1060\" ></img>");
		printf("				</div>");
		printf("				<div class=\"main-choices\">");
		printf("					<textarea id=\"textField1\" cols=110>Click Next</textarea>");
		printf("					<input type=\"button\" value=\"Next\" onclick=\"display4(%s);\">",act);
		printf("				</div>");
		printf("			</div>");
		printf("		</div>");
//	}
	printf("	</form>");
	printf("	</body>");
	printf("</html>");
return 0;
}
