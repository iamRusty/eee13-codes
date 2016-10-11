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
	puts("Content-type:text/html\n\n");
	puts("<html><body>");
	char query[100];

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

	for (count_action = 0; count_action<count; count_action++)
	{
		if (strcmp("action", name2[count_action])==0)
			break;
	}
	for (count_item = 0; count_item<count; count_item++)
	{
		if (strcmp("item", name2[count_item])==0)
			break;
	}
	for (count_price = 0; count_price<count; count_price++)
	{
		if (strcmp("price", name2[count_price])==0)
			break;
	}
	for (count_witem = 0; count_witem<count; count_witem++)
	{
		if (strcmp("witem", name2[count_witem])==0)
			break;
	}
	for (count_wprice = 0; count_wprice<count; count_wprice++)
	{
		if (strcmp("wprice", name2[count_wprice])==0)
			break;
	}



	MYSQL_RES *result = 0;
	MYSQL_ROW row = 0;
	MYSQL *con = mysql_init(NULL);

	mysql_real_connect(con, "localhost", "root", "root", "ME06_201366339", 0, NULL, 0);

//INSERT
	if (strcmp(value[count_action], "insert")==0)
	{
	mysql_query(con, "SELECT * FROM Grocery");
	result = mysql_store_result(con);

	num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result))) 
  {
		if ((strcmp(value[count_item], row[0])==0)&&(strcmp(value[count_price], row[1])==0))
		{
			printf("Error: Duplicate data.<br>");
		  mysql_close(con);
			printf("<br><a href=../ME06.html>Back</a></body></html");
  		return 0;		
		}
  }
	printf("</table>");
  mysql_free_result(result);
		if ((value[count_item]==NULL)||(value[count_price]==NULL))
		{
			printf("You need to put values for VALUES: Item and Price.<br>"); 
			to_print=0;
		}
		else
		{
				len = strlen(value[count_price]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_price][countlen])==0)
						isvalidprice++;
				}

				if (isvalidprice>0)
				{
					printf("Inappropriate price value.<br>");
					to_print=0;
				}
				else
				{
					strcpy(query, "INSERT INTO Grocery VALUES ('");
					strcat(query, value[count_item]);
					strcat(query, "', ");
					strcat(query, value[count_price]);
					strcat(query, ")");
					if(mysql_query(con, query))
					{
		 	 			fprintf(stderr, "%s\n", mysql_error(con));
						to_print=0;
					}
				}
		}
	}
//DELETE
	else if (strcmp(value[count_action], "delete")==0)
	{
		if ((value[count_witem]==NULL)&&(value[count_wprice]==NULL))
		{
			printf("You need to put value/s for WHERE: Item and/or Price.<br>");
			to_print=0;
		}
		else
		{
			if (value[count_witem]==NULL)
			{
				len = strlen(value[count_wprice]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
						isvalidprice++;
				}			 
				if (isvalidprice>0)
				{
					printf("Inappropriate WHERE: Price<br>");
					to_print=0;
				}
				else
				{
					strcpy(query, "DELETE FROM Grocery WHERE price=");
					strcat(query, value[count_wprice]);
					if(mysql_query(con, query))
  					fprintf(stderr, "%s\n", mysql_error(con));	
				}
			}
			else if (value[count_wprice]==NULL)
			{
				strcpy(query, "DELETE FROM Grocery WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "'");
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
		}
	}
//UPDATE
	else if (strcmp(value[count_action], "update")==0)
	{
		if (((value[count_item]==NULL)&&(value[count_price]==NULL))||((value[count_witem]==NULL)&&(value[count_wprice]==NULL)))
		{
			printf("Error! No data to be updated.<br>");
			to_print=0;
		}
		else
		{
			if ((value[count_item]==NULL)&&(value[count_witem]==NULL))
			{
				len = strlen(value[count_price]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_price][countlen])==0)
					{
						printf("Inappropriate VALUE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
				len = strlen(value[count_wprice]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
					{
						printf("Inappropriate WHERE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
				
				strcpy(query, "UPDATE Grocery SET price=");
				strcat(query, value[count_price]);
				strcat(query, " WHERE price=");
				strcat(query, value[count_wprice]);
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));		
			}
			else if ((value[count_item]==NULL)&&(value[count_wprice])==NULL)
			{
				len = strlen(value[count_price]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_price][countlen])==0)
					{
						printf("Inappropriate VALUE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
			
				strcpy(query, "UPDATE Grocery SET price=");
				strcat(query, value[count_price]);
				strcat(query, " WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "'");
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
			else if (value[count_item]==NULL)
			{
				len = strlen(value[count_price]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_price][countlen])==0)
					{
						printf("Inappropriate VALUE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
				len = strlen(value[count_wprice]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
					{
						printf("Inappropriate WHERE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}

				strcpy(query, "UPDATE Grocery SET price=");
				strcat(query, value[count_price]);
				strcat(query, " WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "' AND price=");
				strcat(query, value[count_wprice]);
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
			else if ((value[count_price]==NULL)&&(value[count_wprice]==NULL))
			{
				strcpy(query, "UPDATE Grocery SET item='");
				strcat(query, value[count_item]);
				strcat(query, "' WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "'");
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
			else if ((value[count_price]==NULL)&&(value[count_witem]==NULL))
			{
				len = strlen(value[count_wprice]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
					{
						printf("Inappropriate WHERE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
				
				strcpy(query, "UPDATE Grocery SET item='");
				strcat(query, value[count_item]);
				strcat(query, "' WHERE price=");
				strcat(query, value[count_wprice]);
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));				
			}
			else if (value[count_price]==NULL)
			{
				len = strlen(value[count_wprice]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
					{
						printf("Inappropriate WHERE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}

				strcpy(query, "UPDATE Grocery SET item='");
				strcat(query, value[count_item]);
				strcat(query, "' WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "' AND price=");
				strcat(query, value[count_wprice]);
				printf("%s<br>", query);
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
			else
			{
				len = strlen(value[count_price]); 
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_price][countlen])==0)
					{
						printf("Inappropriate VALUE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}
				for (countlen = 0; countlen < len; countlen++)
				{
					if (isdigit(value[count_wprice][countlen])==0)
					{
						printf("Inappropriate WHERE: Price<br>");
					  mysql_close(con);
						puts("</body></html");
					  return 0;
					}
				}

				strcpy(query, "UPDATE Grocery SET item='");
				strcat(query, value[count_item]);
				strcat(query, "', price=");
				strcat(query, value[count_price]);
				strcat(query, " WHERE item='");
				strcat(query, value[count_witem]);
				strcat(query, "' AND price=");
				strcat(query, value[count_wprice]);
				if(mysql_query(con, query))
  				fprintf(stderr, "%s\n", mysql_error(con));	
			}
		}
	}
if(to_print==1)
{
	mysql_query(con, "SELECT * FROM Grocery");
	result = mysql_store_result(con);

	num_fields = mysql_num_fields(result);
	printf("<table border=1><tr><td>name</td><td>price</td></tr>");
	while ((row = mysql_fetch_row(result))) 
  {
		printf("<tr>"); 
     for(i = 0; i < num_fields; i++) 
     { 
         printf("<td>%s </td>", row[i]); 
     } 
         printf("</tr>"); 
  }
	printf("</table>");
  mysql_free_result(result);
}
  mysql_close(con);
	printf("<br><a href=../ME06.html>Back</a></body></html");
  return 0;
}
