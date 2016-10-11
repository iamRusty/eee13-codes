#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>


int count;

int main(void)
{
	char buffer[128];
	char fifoname[] = "myfifo";
	int fifofd;
	pid_t childpid;
	count=9;
	int fifofd2;
	char fifoname2[] = "myfifo2";

	childpid=fork();
	if (childpid > 0)
	{
		printf("Countdown\n");
		mkfifo(fifoname, S_IRUSR | S_IWUSR);
		fifofd = open(fifoname, O_WRONLY);
		do 
		{
			fifofd2 = open(fifoname2, O_RDONLY);
			read(fifofd2, buffer, sizeof(buffer));
			sleep(1);
			strcpy(buffer, "");
			sprintf(buffer, "%d", count);
			printf("parent: %s\n", buffer);
			write(fifofd, buffer, strlen(buffer)+1 );
			count = count-1;
		} while (strcmp(buffer,"0") != 0);
	}
	else if (childpid == 0)
	{
		fifofd = open(fifoname, O_RDONLY);
		do 
		{		
			read(fifofd, buffer, sizeof(buffer));
			printf("child: %s\n", buffer);
			mkfifo(fifoname2, S_IRUSR | S_IWUSR);
			fifofd2 = open(fifoname2, O_WRONLY);
			write(fifofd2, buffer, strlen(buffer)+1 );
		} while (strcmp(buffer,"0") != 0);
	}
		close(fifofd);
		unlink(fifoname);
		close(fifofd2);
		unlink(fifoname2);
	return 0;
}
