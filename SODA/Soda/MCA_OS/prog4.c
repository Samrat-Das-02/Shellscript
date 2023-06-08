#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    while (1){
        printf("1. ls\n");
        printf("2. pwd\n");
        printf("3. uname\n");
        printf("4. exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        pid_t pid = fork();
        if (pid==0){
				printf("Child process id is::%d\n",getpid());
                if(choice==1){
                    char *args[]={"ls",NULL};
                    execv("/bin/ls",args);
                }
                else if(choice==2){
                    char *args[]={"pwd",NULL};
                    execv("/bin/pwd",args);
                }
                else if(choice==3){
                    char *args[]={"uname",NULL};
                    execv("/bin/uname", args);
                }
                else{
                    printf("Invalid choice\n");
                    exit(EXIT_FAILURE);
                }
        }
        else {
            wait(NULL);
            printf("\n");
        }
    }
    
    return 0;
}
