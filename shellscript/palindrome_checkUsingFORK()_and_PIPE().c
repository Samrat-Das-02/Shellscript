#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define buffer_size 255

int is_palindrome(char str[]) 
 { 
     int i, len; 
     len = strlen(str); 
  
     for (i = 0; i < len / 2; i++) { 
         if (str[i] != str[len - i - 1]) 
             return 0; 
     } 
     return 1; 
 }
int main()
{
    char buffer[buffer_size];
    int pipe1[2];
    int pipe2[2];
    pid_t child ;
    if(pipe(pipe1)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    if(pipe(pipe2)==-1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    child=fork();
    if(child<0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(child>0)//Parent process 
    {
        close(pipe1[1]); //closing the writing head of the pipe 1
        close(pipe2[0]); //closing the reading head of the pipe 2
        while(1)
        {
            printf("Enter string ('quit' for exit) : ");
            fgets(buffer,buffer_size,stdin);
            buffer[strcspn(buffer,"\n")] ='\0';
           if (strcmp(buffer, "quit") == 0) { 
                 write(pipe2[1], buffer,buffer_size); 
                 break; 
             } 
            write(pipe2[1],buffer,buffer_size);
            
            read(pipe1[0],buffer,buffer_size);
            printf("The entered string is palindrome: %s\n",buffer);
        }
        close(pipe1[0]);
        close(pipe2[1]);
        wait(NULL);
        printf("Parent process is terminated ..\n");
        exit(19);
    }
    else  //child process
    {
        close(pipe1[0]);  //closing the reading head of the pipe1
        close(pipe2[1]);  //closing the writng head of the pipe2
        while(1)
        {
            read(pipe2[0],buffer,buffer_size);
            if(strcmp(buffer, "quit")==0 )
                break;
            if(is_palindrome(buffer))
                write(pipe1[1],"YES",4);
            else
                write(pipe1[1],"NO",3);
                
        }
        close(pipe1[1]);
        close(pipe2[0]);
        printf("The child process is terminated  \n");
        exit(20);
    }
    return 0;
}