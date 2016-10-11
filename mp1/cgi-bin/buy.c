//reference: https://www.digitalocean.com/community/tutorials/how-to-import-and-export-databases-and-reset-a-root-password-in-mysql
//           http://zetcode.com/db/mysqlc/
// to compile: gcc ME06_201366339.c -o ME06_201366339.cgi `mysql_config --ccflags --libs` -std=c99

#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char *data, *contain, *name[20], *name2[20], *value[20];
	int i, num_fields, count=0, count3=0, count_action, count_item, count_price, count_witem, count_wprice, countlen, len;
	int isvalidprice = 0, to_print=1;
	int sr, hp, money, health, trr;
	puts("Content-type:text/html\n\n");
	puts("<html><body>");
	char query[1000];

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

	delimiter = '=';	

	char *container;

	for (count3 = 0; count3<count; count3++)
	{
		container = strtok(name[count3], &delimiter);
		name2[count3]=container;
		container = strtok(NULL, &delimiter);
		value[count3]=container;
	}


	MYSQL_RES *result = 0;
	MYSQL_ROW row = 0;
	MYSQL *con = mysql_init(NULL);

	strcpy(query, "SELECT hp, item1,item2,item3,favor FROM savetemp WHERE id=11");		

	mysql_real_connect(con, "localhost", "root", "root", "mp", 0, NULL, 0);
	mysql_query(con, query);
	result = mysql_store_result(con);

	num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result))) 
  	{
		health=atoi(row[0]);
		money=atoi(row[4]);
		hp=atoi(row[1]);
		sr=atoi(row[2]);
		trr=atoi(row[3]);	
  	}


int count4=0, total=0, cur=0;



//	printf("Content-type:text/html<br>\n\n");
	printf("<html>");
	printf("	<head>");
	printf("		<title>I Hack for lulz, do I?</title>");
	printf("		<link rel=\"stylesheet\" type=\"text/css\" href=\"../assets/style.css\">");
	printf("<script type=\"text/javascript\" src=\"../assets/js/functions.js\"></script>");
	printf("	<link rel=\"icon\" href=\"../assets/hack.ico\">");
	printf("	</head>");
	printf("<body>");
	for (count3 = 0; count3<count; count3++)
	{	
		if (value[count3]==NULL)
			continue;
		//printf("count3:%i<br>", count3);
		else if (strcmp(name[count3], "sr")==0)
		{
		//	printf("count3: %i", count3);
			
			for(count4=0; count4<count;count4++)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "sr")==0)
				{
					
					//printf("true<br>");
					cur=atoi(value[count3]);
					total=total+ (cur * 3);
					break;
				}
			}
			
		
		}
		else if (strcmp(name[count3], "tr")==0)
		{
			for(count4=0; count4<count;)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "tr")==0)
				{
					//printf("true<br>");
					cur=atoi(value[count3]);
					total=total+ (cur * 3);
					break;
				}
		
				count4++;
			}
		}
		else if (strcmp(name[count3], "hp")==0)
		{
			for(count4=0; count4<count;)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "hp")==0)
				{
					//printf("true<br>");
					cur=atoi(value[count3]);
					total=total+ (cur * 1);
					break;
				}
		
				count4++;
			}
		}
		//printf("%s %s<br>", name2[count3], value[count3]);
	}
	printf("%i", total);
	if (total>money)
	{
		printf("<script type=\"text/javascript\">alert(\"You dont have enough favors\")</script>");
		printf("<script type=\"text/javascript\">post(\'store.cgi\', {'store.cgi': 11})</script>");
	}
	else if (total==0)
	{
		printf("<script type=\"text/javascript\">alert(\"You didn't buy anything. lol\")</script>");
		printf("<script type=\"text/javascript\">post(\'store.cgi\', {'store.cgi': 11})</script>");
	}
	else
	{
	for (count3 = 0; count3<count; count3++)
	{	
		if (value[count3]==NULL)
			continue;
		//printf("count3:%i<br>", count3);
		else if (strcmp(name[count3], "sr")==0)
		{
		//	printf("count3: %i", count3);
			
			for(count4=0; count4<count;count4++)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "sr")==0)
				{
					strcpy(query, "UPDATE savetemp SET item2=");
					strcat(query, value[count3]);
					mysql_query(con, query);
		printf("<script type=\"text/javascript\">alert(\"Success\")</script>");
		printf("<script type=\"text/javascript\">post(\'store.cgi\', {'store.cgi': 11})</script>");
					cur=atoi(value[count3]);
					total=total+ (cur * 3);
					break;
				}
			}
			
		
		}
		else if (strcmp(name[count3], "tr")==0)
		{
			for(count4=0; count4<count;)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "tr")==0)
				{
					strcpy(query, "UPDATE savetemp SET item3=");
					strcat(query, value[count3]);
		
					mysql_query(con, query);
		printf("<script type=\"text/javascript\">alert(\"Success\")</script>");
		printf("<script type=\"text/javascript\">post(\'store.cgi\', {'store.cgi': 11})</script>");
					cur=atoi(value[count3]);
					total=total+ (cur * 3);
					break;
				}
		
				count4++;
			}
		}
		else if (strcmp(name[count3], "hp")==0)
		{
			for(count4=0; count4<count;)
			{
				//printf("count4: %i<br>", count4);
				if (value[count4]==NULL)
					count4=count4;
				else if (strcmp(value[count4], "hp")==0)
				{
					strcpy(query, "UPDATE savetemp SET item2=");
					strcat(query, value[count3]);
					mysql_query(con, query);
		printf("<script type=\"text/javascript\">alert(\"Success\")</script>");
		printf("<script type=\"text/javascript\">post(\'store.cgi\', {'store.cgi': 11})</script>");
					cur=atoi(value[count3]);
					total=total+ (cur * 1);
					break;
				}
		
				count4++;
			}
		}
		//printf("%s %s<br>", name2[count3], value[count3]);
	
	}
		
	}
	printf("</body></html>");
}
