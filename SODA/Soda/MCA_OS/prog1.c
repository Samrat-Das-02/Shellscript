#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t child;
	
	child=fork();
	if(child==0){
		printf("child process pid:: %d\n",getpid());
		printf("Parent pid of child process::%d\n",getppid());
		printf("press any key to finish child process");
		char ch;
		scanf("%c",&ch);
	}
	else{
		int status;
		waitpid(child,&status,0);
		printf("exit status of child:: %d\n",WEXITSTATUS(status));
		printf("parent process pid:: %d\n",getpid());
		printf("Parent pid of parent process::%d\n",getppid());
		printf("parent process exited\n");
	}
	return 0;
}
