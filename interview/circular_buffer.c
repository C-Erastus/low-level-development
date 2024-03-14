#include <stdio.h>

struct queue{
    int *value; 
    int head;
    int tail; 
    int num_entries;
    int size; 
};

int main(int argc, char** argv)
{
    struct queue *q1; 

    printf("This is my queue implementation\n");
    
    return 0;
} 
