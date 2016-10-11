#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


pid_t childpid;
int number;
void sig_alarm(int signo)
{
	if(signo==SIGALRM) {
		printf("Number: %i\n", number);
		kill(childpid, SIGKILL);
	} else {
		printf("Unknown signal number\n");
	}
}

void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
	    printf("\nNumber: %d\n", number);
		kill(childpid, SIGKILL);
	}
}

int main(void)
{
	pid_t pid;
	int fd, a, val;
	unsigned int random;
	struct sigaction act;
	act.sa_handler = sig_alarm;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);



	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &random, sizeof(random));

	a = random % 11;
	number = a + 10;
	printf("Hint: %i\n", number);
	pid=fork();
	if (pid >0) 
	{
		struct sigaction act;
		act.sa_handler = sig_alarm;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		if (sigaction (SIGALRM, &act, 0) == -1) 
		{
			perror (NULL);
			return 1; 
		}
		alarm (10);
		wait(NULL);
		exit(0);
//		pause();
	} 
	else if(pid==0) 
	{
		signal(SIGINT, sig_handler);
		childpid=getpid();
		for (;;)
		{
			scanf("%i", &val);
			if (val == number)
			{
				printf("You're correct.\n");
				signal(SIGALRM, sig_alarm);
				break;
			}
			else
				continue;
		}
		
	}
	
	return 0;
}
