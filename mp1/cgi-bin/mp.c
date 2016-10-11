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
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	</head>");
	printf("	<body>");
//	printf("act:%s <br>cur_scene:%s %i", act, key, count2);


	//--CREDITS-----------------------------------------------------------
	if (strcmp(act,"Credits") == 0)
	{
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("					<dd>");
		printf("					<form action=\"../index.html\" method=POST>");
		printf("							<input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\">");
		printf("					</form>"); 
		printf("					</dd>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
	}
	//--SAVE/LOAD---------------------------------------------------------
	if ((strcmp(act,"Save") == 0) || (strcmp(act,"Load") == 0))
	{
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");
		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");
		printf("				<form action=\"mp.cgi\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("				</form>");
		printf("				<dd>");
		if (strcmp(cur_scene, "index.html")==0)
			printf("			<form action=\"../index.html\" method=POST>");
		else
			printf("			<form action=\"mp.cgi\" method=POST>");
		printf("					<input type=\"submit\" style=\"padding: 10px 65px;\" value=\"Back\" name=\"Dead\">");
		printf("					<input type=hidden name=\"%s\" value=\"%s\">", cur_scene, cur_scene);
		printf("				</form> </dd>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
	}
	//--DEAD---------------------------------------------------------------
	if (strcmp(act,"Dead") == 0) 
	{
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("					<form action=\"../index.html\" method=\"POST\">");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("					</form>");
		printf("					<form action=\"mp.cgi\" method=\"POST\">");
		printf("						<dd> <input type=\"submit\" name=\"Dead\" style=\"padding: 10px 72px;\" value=\"Load\"> </dd>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("					</form>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> # </td> </tr> </dd>");
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");
	}
	//--SURVIVED-------------------------------------------------------------
	if (strcmp(act,"Survive") == 0)
	{
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");		
		printf("						<dd> <table>");
		printf("							<tr>");
		printf("				<form action=\"mp.cgi\" method=POST>"); 
		printf("								<td> <input type=\"submit\" name=\"Survive\" style=\"padding: 10px 24px;\" value=\"Load\"> </td>");
		printf("								<td> <input type=\"submit\" name=\"Survive\" style=\"padding: 10px 24px;\" value=\"Save\"> </td>");
		printf("							</tr>");
		printf("						</table> </dd>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("				</form>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> # </td> </tr> </dd>");
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");
	}
	//--STORE---------------------------------------------------------
	if (strcmp(act,"Store") == 0)
	{
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");
		
		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");
		printf("				<form action=\"mp.cgi\" method=POST>");		
		printf("						<dd> <table>");
		printf("							<tr>"); 
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Load\"> </td>", cur_scene);
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Save\"> </td>", cur_scene); 
		printf("							</tr>");
		printf("						</table> </dd>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("						</form>");
		printf("						<form action=\"mp.cgi\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 65px;\" value=\"Back\"> </dd>", cur_scene);
		printf("						<input type=\"hidden\" name=\"%s\" value=\"%s\">", cur_scene, cur_scene);
		printf("				</form>");		
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> # </td> </tr> </dd>");
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");
		printf("		<div class=\"inventory-container\">");
		printf(" 			<div class=\"inventory\">");
		printf("				<dl> <table> <col width=\"150\"><col width=\"50\">");
		printf("					<dd> <tr>");
		printf("						<td> <span> Inventory </span> </td>");
		printf("						<td> # </td>");
		printf("					</tr> </dd>");
		printf("				</table> ");
		printf("						<dl style=\" border: none;\"> <table> <col width=\"50\"><col width=\"100\"><col width=\"50\">");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> HP </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 15px;\" value=\"Use HP\"> </td>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> SR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 15px;\" value=\"Use SMR\"> </td>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> TRR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 10px;\" value=\"Use TRR\"> </td>");
		printf("							</tr> </dd>");
		printf("						</dl>");
		printf("				</table> </dl> ");
		printf("			</div> ");
		printf("		</div>");
	}
	//--SCENES---------------------------------------------------------------
	if (strcmp(act, "Scene1")==0)
	{	
		printf("		<div class=\"sidebar-container\">");
		printf(" 			<div class=\"sidebar\">");

		printf("				<dl>");
		printf("				<form action=\"../index.html\" method=POST>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 68.5px;\" value=\"Home\"> </dd>");
		printf("				</form>");
		printf("				<form action=\"mp.cgi\" method=POST>");		
		printf("						<dd> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 70.5px;\" value=\"Store\"> </dd>", cur_scene);
		printf("						<dd> <table>");
		printf("							<tr>"); 
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Load\"> </td>", cur_scene);
		printf("								<td> <input type=\"submit\" name=\"%s\" style=\"padding: 10px 24px;\" value=\"Save\"> </td>", cur_scene); 
		printf("							</tr>");
		printf("						</table> </dd>");
		printf("						<dd> <input type=\"submit\" name=\"action\" style=\"padding: 10px 65px;\" value=\"Credits\"> </dd>");
		printf("				</form>");
		printf("				</dl>");
		printf("			</div> ");
		printf("		</div>");
		printf("		<div class=\"health-container\">");
		printf(" 			<div class=\"health\">");
		printf("				<dl> <table> <col width=\"150px\"><col width=\"50px\">");
		printf("						<dd> <tr> <td> <span>Health</span> </td> <td> # </td> </tr> </dd>");
		printf("				</table> </dl>");
		printf("			</div>");
		printf("		</div>");
		printf("		<div class=\"inventory-container\">");
		printf(" 			<div class=\"inventory\">");
		printf("				<dl> <table> <col width=\"150\"><col width=\"50\">");
		printf("					<dd> <tr>");
		printf("						<td> <span> Inventory </span> </td>");
		printf("						<td> # </td>");
		printf("					</tr> </dd>");
		printf("				</table> ");
		printf("						<dl style=\" border: none;\"> <table> <col width=\"50\"><col width=\"100\"><col width=\"50\">");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> HP </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 15px;\" value=\"Use HP\"> </td>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> SR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 15px;\" value=\"Use SMR\"> 	</td>");
		printf("							</tr> </dd>");
		printf("							<dd> <tr>");
		printf("								<td> <span> # </span> </td>");
		printf("								<td> <span> TRR </span> </td>");
		printf("								<td> <input type=\"submit\" name=\"inventory\" style=\"padding: 5px 10px;\" value=\"Use TRR\"> 	</td>");
		printf("							</tr> </dd>");
		printf("						</dl>");
		printf("				</table> </dl> ");
		printf("			</div> ");
		printf("		</div>");	
	}
//--ONE PANE----
	if ((strcmp(act,"Save")==0) || (strcmp(act,"Load")==0) || (strcmp(act,"Store")==0) || (strcmp(act,"Credits")==0) || (strcmp(act, "Dead")==0) || (strcmp(act, "Survive")==0)) 
		{
		printf("		<div class=\"main-container\">");
		printf("			<div class=\"main\">");
		printf("				<div class=\"main-one\">");
		printf("					");
		printf("				</div>");
		printf("			</div>");
		printf("		</div>");
		printf("	");
		printf("	");
		}
//--TWO PANE----
	if (strcmp(act, "Scene1")==0)
	{
		printf("		<div class=\"main-container\">");
		printf("			<div class=\"main\">");
		printf("				<div class=\"main-challenge\">");
		printf("	<img src=\"../assets/main_room.jpg\" height=\"488\" width=\"1060\" ></img>");
		printf("				</div>");
		printf("				<div class=\"main-choices\">");
		printf("					<textarea id=\"textField1\" cols=100>Hello</textarea>");
		printf("					<input type=\"button\" value=\"Next\" onclick=\"display(%i);\">", count_dia++);
		printf("				</div>");
		printf("			</div>");
		printf("		</div>");
	}

//--------------------------------------ALL----------------------------------------
printf("	</form>");
printf("	</body>");
printf("</html>");


	return 0;
}

