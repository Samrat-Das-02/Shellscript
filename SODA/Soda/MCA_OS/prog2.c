#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_CHILDREN 10
#define RANGE_SIZE 100000

int is_prime(int n) {
    if (n<=1)
        return 0;

    for (int i=2;i*i<=n;++i) {
        if (n%i==0)
            return 0;
    }

    return 1;
}

void print_primes(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (is_prime(i))
            printf("%d   ", i);
    }
}

int main() {
    pid_t child_pid;
    int range_start = 1;
    int range_end = RANGE_SIZE;
    int i;

    for (i=0;i<NUM_CHILDREN;++i) {
        child_pid = fork();
        if (child_pid == 0) {
            print_primes(range_start, range_end);
            exit(0);
        }
		else{
			wait(NULL);
		}
        range_start = range_end + 1;
        range_end += RANGE_SIZE;
    }
    return 0;
}
