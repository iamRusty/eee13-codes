#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>

int listenfd,connfd;
FILE *fp;
void sig_usr(int signo)
{
	if(signo==SIGINT)
	{
		printf("\nExiting server. \n");
		close(connfd);
		close(listenfd);
		exit(0);
	}
	else
		printf("Unknown signal number\n");
} 
 
int main(int argc, char **argv)
{
	struct sockaddr_in servaddr,cliaddr;
	struct tm *info;
	time_t rawtime;
	socklen_t len = sizeof(cliaddr);
	char cli_ip[32];
	char mesg[1024];
	char get[100];
	char trash[1024];
	char name[100];
	char ext[10];
	int file = 0;
	int count, c;
	int placeholder = 0;
	char *string;

 
  //Ctrl + C handler
  	if(signal(SIGINT, sig_usr) == SIG_ERR)
	printf("Error creating SIG_INT\n");
 
  	listenfd = socket(PF_INET,SOCK_STREAM,0);
  	bzero(&servaddr, sizeof(servaddr));
  	servaddr.sin_family = AF_INET;
  	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  	servaddr.sin_port = htons(12345);
  	if ( bind( listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr) ) < 0 )
  	{
     	perror(NULL);
     	exit(-1);
  	}
 
  	listen(listenfd,2);
   
  	while(1)
  	{
    		connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&len);
    		inet_ntop(AF_INET,(struct in_addr *) &cliaddr.sin_addr, cli_ip, sizeof(cli_ip) );
    		printf("Client %s connected. \n",cli_ip);    
    		while(1)
    		{
      		memset(mesg,0,sizeof(mesg));
      		if( recvfrom(connfd,mesg,sizeof(mesg),0,(struct sockaddr *)&cliaddr,&len) > 0 )
      		{
      		
            		//printf("From %s port %d: %s\n-\n",cli_ip,ntohs(cliaddr.sin_port),mesg);
            		//printf("\n");
   				sscanf( mesg, "GET /%s %s", get, trash);
				//printf("%s\n", get);
			
		  		if (strcmp("HTTP/1.1", get)==0)
		  			strcpy(get, "index.html");
		  	
		  		printf("Requesting %s\n", get);
		  		
		  		file = 0;
		  		
		  		for (count=0; count<strlen(get); count++)
				{
					if (get[count]=='.')
					{
						file++;
						get[count]=' ';
					}
				}
		 		sscanf(get, "%s %s", name, ext);
		  	   	
		  	   	sprintf(get, "%s.%s", name, ext);

		  	   	//time
		  	   	time(&rawtime);
				info = localtime(&rawtime);
				
		  	   	if (file)
		  	   	{
		  	   		if ((strcmp(ext,"jpg")==0)||(strcmp(ext,"html")==0)||(strcmp(ext,"css")==0)||(strcmp(ext,"png")==0))
		  	   		{
		  	   			fp = fopen(get, "rb");
		 				if (fp==NULL)
		  				{
		  					printf("Error 404 File not found.\n");
		  					char *bad_request_response = calloc(1000, 1);
		  					char *content = "<html>\n<body>\n<H1>Error 404</h1>\n<br>\nFile not found\n</body>\n</html>\n";
		  					placeholder = strlen(content);
		  					sprintf(bad_request_response, "HTTP/1.1 404 Not Found\nContent-length: %i\nContent-type: text/html\nDate: %s\n\n%s", placeholder, asctime(info), content);
		  					send(connfd, bad_request_response, strlen(bad_request_response), 0);
		  					free(bad_request_response);
		  					//printf("%s\n", bad_request_response);
		  				}
		  				else
		  				{
		  					fseek(fp, 0, SEEK_END);
		  					long fsize = ftell(fp);
		  					fseek(fp, 0, SEEK_SET);
		  					
		  					char *response = calloc(1000, 1);
		  					if (strcmp(ext, "jpg")==0)
		  						sprintf(response, "HTTP/1.1 200 OK\nContent-length: %li\nContent-Type: image/jpeg\nDate: %s\r\n", fsize, asctime(info));
		  					else if (strcmp(ext, "html")==0)
								sprintf(response, "HTTP/1.1 200 OK\nContent-length: %li\nContent-Type: text/html\nDate: %s\r\n", fsize, asctime(info));
							else if (strcmp(ext, "png")==0)
								sprintf(response, "HTTP/1.1 200 OK\nContent-length: %li\nContent-Type: image/png\nDate: %s\r\n", fsize, asctime(info));
							else
								sprintf(response, "HTTP/1.1 200 OK\nContent-length: %li\nContent-Type: text/css\nDate: %s\r\n", fsize, asctime(info));
		  					send(connfd, response, strlen(response), 0);
		  					
		  					//printf("%s\n", response);
							string = calloc(2, 1);
							while ((c = fread(string, 1, 1, fp))>0)
							{
								send(connfd, string, 1, 0);
								string = calloc(2, 1);
							}
							//printf("%i\n", counter);
		  					free(string);
		  					free(response);
		  					fclose(fp);
		  				}
		  				
		  	   		}
		  	   		else 
		  	   		{
		  	   			printf("Error 415 Unsupported Media File\n");
		  				char *bad_request_response = calloc(1000, 1);
		  				char *content = "<html>\n<body>\n<H1>Error 415</h1>\n<br>\nMedia File not supported\n</body>\n</html>\n";
		  				placeholder = strlen(content);
		  				sprintf(bad_request_response, "HTTP/1.1 415 Unsupported Media File\nContent-length: %i\nContent-type: text/html\nDate: %s\n\n%s", placeholder, asctime(info), content);
		  				send(connfd, bad_request_response, strlen(bad_request_response), 0);
		  				free(bad_request_response);
		  	   		}
		  	   	}
		  	   	else
		  	   	{
		  	   		printf("You are not allowed to access directories\n");
		  			char *bad_request_response = calloc(1000, 1);
		  			char *content = "<html>\n<body>\n<H1>Error</h1>\n<br>\nYou are not allowed to access directories\n</body>\n</html>\n";
		  			placeholder = strlen(content);
		  			sprintf(bad_request_response, "HTTP/1.1 404 Not Found\nContent-length: %i\nContent-type: text/html\nDate: %s\n\n%s", placeholder, asctime(info), content);
					send(connfd, bad_request_response, strlen(bad_request_response), 0);
					free(bad_request_response);
		  	   	}	
	
      		}
      		else 
      		{
        			printf("Client %s disconnected. \n",cli_ip);     
        			break;
      		}
      		//close(connfd); To stop from requesting data
    		}
    		close(connfd);
  	}
  	close(listenfd);

	return 0;
}
