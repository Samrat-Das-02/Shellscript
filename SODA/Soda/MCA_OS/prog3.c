#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 
  
#define BUFFER_SIZE 64 
 int checkPalindrome(char str[]); 
  
 int main() { 
  
     char buffer[BUFFER_SIZE]; 
  
     int pipe1[2]; //for child
     int pipe2[2]; //for parent
  
     if (pipe(pipe1) == -1) {return 1;} 
     if (pipe(pipe2) == -1) {return 2;} 
  
     pid_t pid = fork(); 
  
     if(pid == -1) {return 3;}; 
  
     if (pid == 0){ 
         close(pipe1[0]); //closing read end of child
         close(pipe2[1]); //closing write end of parent
  
         while (1){ 
             read(pipe2[0], buffer, BUFFER_SIZE); 
  
             if (strcmp(buffer, "quit") == 0) { 
                 break; 
             } 
  
             if(checkPalindrome(buffer)){ 
                 write(pipe1[1], "Yes", 4); 
             }else{ 
                 write(pipe1[1], "No", 3); 
             } 
  
         } 
         close(pipe1[1]); 
         close(pipe2[0]); 
         printf("\nLeaving child process\n"); 
         exit(20); 
     }else{ 
         close(pipe1[1]); 
         close(pipe2[0]); 
  
         while (1){ 
             printf("\nEnter string ( for exit 'quit' ) :\n"); 
             fgets(buffer, BUFFER_SIZE, stdin); 
             buffer[strlen(buffer)-1] = '\0'; 
  
             if (strcmp(buffer, "quit") == 0) { 
                 write(pipe2[1], buffer, BUFFER_SIZE); 
                 break; 
             } 
  
             write(pipe2[1], buffer, BUFFER_SIZE); 
  
             read(pipe1[0], buffer, BUFFER_SIZE); 
             printf("\nIs palindrome?: %s", buffer); 
         } 
  
         close(pipe1[0]); 
         close(pipe2[1]); 
         wait(NULL); 
         printf("\nLeaving parent process\n"); 
         exit(19); 
     } 
  
     return 0; 
 } 
  
 int checkPalindrome(char str[]) 
 { 
     int i, len; 
     len = strlen(str); 
  
     for (i=0;i<len/2;i++) { 
         if (str[i]!=str[len-i-1]) 
             return 0; 
     } 
     return 1; 
 }
