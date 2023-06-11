#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define num_child 10
#define range 100000
int is_prime(int n)
{
    int i;
    if(n<=1)
        return 0;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
void print_prime(int start,int end)
{
    for(int i=start;i<=end;i++)
        {
            if(is_prime(i))
                printf("%d ",i);
        }
}
int main()
{
    pid_t child;
    int range_start=1;
    int range_end=range;
    for(int i=0;i<num_child;i++)
    {
      child=fork();
      if(child==0)
      {
          print_prime(range_start,range_end);
          exit(0);
      }
      else if(child<0)
        {
            perror("fork");
            exit(1);
        }
        range_start=range_end+1;
        range_end=range_end+range;
        for(int i=0;i<num_child;i++)
        {
            wait(NULL);
            
        }
    }
}