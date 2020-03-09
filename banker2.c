#include <stdio.h> 
#include <string.h>  
int P; 
int R; 
 
int total = 0; 

int safe[4];
int sz = 0;
int is_available(int process_id, int allocated[][R], 
                  int max[][R], int need[][R], int available[]) 
{ 
int i;
  
    int flag = 1; 
    for (int i = 0; i < R; i++) { 
  
        if (need[process_id][i] > available[i]) 
            flag = 0; 
    } 
  
    return flag; 
} 
 
void safe_sequence(int marked[], int allocated[][R], int max[][R], 
                   int need[][R], int available[]) 
{ 
  int i;
    for (i = 0; i < P; i++) { 
  
        if (!marked[i] && is_available(i, allocated, max, need, available)) { 
  
            marked[i] = 1; 
  
            
            for (int j = 0; j < R; j++) 
                available[j] += allocated[i][j]; 
  
safe[sz] = i;
sz++;
          
            safe_sequence(marked, allocated, max, need, available); 
     
sz--;
safe[sz] = 0; 
  
            marked[i] = 0; 
  
   
            for (int j = 0; j < R; j++) 
                available[j] -= allocated[i][j]; 
        } 
    } 

    if (sz == P) { 
  
        total++; 
        for (int i = 0; i < P; i++) { 
  
            printf("P%d  ", safe[i] + 1); 
        } 
  
        printf("\n");
    } 
} 
  
int main() 
{ 

	printf("Enter number of processes and number of resource types\n"); 
	scanf("%d%d", &P,&R);
	int available[R];
	int allocated[P][R];
	int max[P][R];
	int i,j;
	printf("Enter available resources matrix\n");
	for (i=0;i<R;i++)
	{
		scanf("%d", &available[i]);
	}
	printf("Enter allocated resources matrix\n");
	for (i=0;i<P;i++)
		for (j=0;j<R;j++)
			scanf("%d", &allocated[i][j]);
	printf("Enter max matrix\n");
	for (i=0;i<P;i++)
		for (j=0;j<R;j++)
			scanf("%d", &max[i][j]);
   
  
  
    int marked[P]; 
	for(i= 0 ; i < P; i++)
	marked[i] = 0;
  
    int need[P][R]; 
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) 
            need[i][j] = max[i][j] - allocated[i][j]; 
  
    printf("Safe sequences are:\n"); 
    safe_sequence(marked, allocated, max, need, available); 
  if (total == 0)
printf("System is unsafe");
else 
    printf("\n %d  safe-sequences\n", total ); 


    return 0;
}
