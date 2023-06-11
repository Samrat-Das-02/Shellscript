#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<time.h>
#include<limits.h>
int main()
{
    int shmid;
    key_t key=ftok("file",25);
    shmid=shmget(key,1024,0666 | IPC_CREAT);
    char *buffer=(char *)shmat(shmid,NULL,0);
    int turn=0; //0 for parent,1 for child
    sprintf(buffer,"%d",turn);
    srand(time(NULL));
    pid_t child=fork();
    if(child<0)
        {
            printf("fork() failed\n");
            return 0;
        }
    else if(child>0)//parent process 
    {
        while(turn!=0)
            sscanf(buffer,"%d",&turn);
        printf("Parent process is generating numbers :: \n");    
        for(int i=1;i<=100;i++)
        {
            int temp=rand()%500+1;
            sprintf(buffer+(4*i),"%d",temp);
        }
        printf("parent wrote the numbers in the buffer\n");
        turn=1;
        sprintf(buffer,"%d",turn);//give control to the child process 
        while(turn!=0)
            sscanf(buffer,"%d",&turn); //wait until the child process finishes 
        int max=0,min=0;
        sscanf(buffer+(4*101),"%d",&max);  
        sscanf(buffer+(4*102),"%d",&min);   
        printf("MAX:%d \n",max);
        printf("MIN :%d \n",min);
        wait(NULL);
            
    }
    else
    {
        while(turn!=1)
            sscanf(buffer,"%d",&turn);
        int max=0,min=501,data;
        for(int i=1;i<=100;i++)
        {
            sscanf(buffer+(4*i),"%d",&data);
            if(data>max)
                max=data;
            if(data<min)
                min=data;
            printf("  %d  ",data);    
                
        }
        sprintf(buffer+(4*101),"%d",max);
        sprintf(buffer+(4*102),"%d",min);
        turn=0;
        sprintf(buffer,"%d",turn);

    }
    shmdt(buffer);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}