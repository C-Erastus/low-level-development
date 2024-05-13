#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int **arr = NULL;
	int i = 0, j=0;
	arr = (int **)malloc(sizeof(int*)*20); 
	if(arr == NULL)
		printf("Failed to allocate space for the big arrary\n"); 
	for(i = 0; i < 20; i++){
		arr[i] = (int *)malloc(sizeof(int)*30);
		if(arr[i] == NULL){
			printf("failed to allocate space at arr %d \n", i); 
		}
	}

	/* populate the array */
	for (i = 0; i < 20; i++){
		for(j = 0; j < 30; j++){
			arr[i][j] = i+j;
		}
	}

	/* print the array */
	for(i = 0; i < 20; i++){
		for(j = 0; j < 30; j++){
			printf("%3d", arr[i][j]);
		}
		free(arr[i]);
		printf("\n");
	}
	/* free the arrarys */
	free(arr);
	return 0;
}
