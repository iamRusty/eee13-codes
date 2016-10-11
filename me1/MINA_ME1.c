#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int a[3288][4];
	FILE * fp;
	//Using the shortcut - 15 lines a month = fit the criteria 
	fp = fopen ("dates.txt", "r+");
	int count;   
	int temp = 0;
	int fifteen= 1;
	printf("The following fit the criteria: (shortcut method)\n");
	for (count = 0; count<3288; count++)
	{
		fscanf(fp, "%d/%d/%d,%d", a[count], a[count]+1, a[count]+2, a[count] +3);
  		if (temp == a[count][0])
		{
  			fifteen++;
			if (fifteen == 15)
    			printf("%d %d\n", a[count][0], a[count][2]);
		}
  		else
  		{
    		fifteen = 1;
    		temp = a[count][0];
  		} 
	}
 
    fclose(fp);
	
	printf("The following fit the criteria: (counting the fridays, saturdays and sundays in a month)\n");
	//By counting the number of fridays, saturdays and sundays in a month
	int friday = 0, saturday = 0, sunday = 0;
	fp = fopen ("dates.txt", "r+");
	for (count = 0; count<3288; count++)
	{
		fscanf(fp, "%d/%d/%d,%d", a[count], a[count]+1, a[count]+2, a[count] +3);
  		if (temp == a[count][0])
		{
  			if (a[count][3] == 0)
				friday++;
			else if (a[count][3] == 1)
				saturday++;
			else if (a[count][3] == 2)
				sunday++;
			
			if ((friday==5)&&(saturday==5)&&(sunday==5))
				printf("%d - %d\n", a[count][0], a[count][2]);
		}
  		else
  		{
    		friday = 0;
			saturday = 0;
			sunday = 0;
    		temp = a[count][0];
			
			if (a[count][3] == 0)
				friday++;
			else if (a[count][3] == 1)
				saturday++;
			else if (a[count][3] == 2)
				sunday++;
  		} 
	}
	
	fclose(fp);
	//Couting the number of fridays, saturdays and sundays for all months 
	friday = 0;
	saturday = 0;
	sunday = 0;
	fp = fopen ("dates.txt", "r+");
	for (count = 0; count<3288; count++)
	{
		fscanf(fp, "%d/%d/%d,%d", a[count], a[count]+1, a[count]+2, a[count] +3);
  			if (a[count][3] == 0)
				friday++;
			else if (a[count][3] == 1)
				saturday++;
			else if (a[count][3] == 2)
				sunday++;
	}
	fclose(fp);
   return(0);
}
