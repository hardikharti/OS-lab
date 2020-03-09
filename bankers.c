#include<stdio.h>
#include<stdlib.h>

void main()
{
int available[3],n,i,k,ind=0,j;
printf("Enter the number of processes\n");
scanf("%d",&n);
int max[n][3],allocate[n][3],need[n][3],f[n],ans[n];
printf("Enter the maximum need for each process \n");
for(i=0;i<n;i++)
{
 f[i]=0;
 ans[i]=0;
 for(j=0;j<3;j++)
 scanf("%d",&max[i][j]);
 
}

printf("Enter the allocated resources for each process \n");
for(i=0;i<n;i++)
{
 for(j=0;j<3;j++)
 scanf("%d",&allocate[i][j]);
}

printf("Enter the available resources \n");
for(i=0;i<3;i++)
scanf("%d",&available[i]);

for(i=0;i<n;i++)
{ 
 for(j=0;j<3;j++)
 need[i][j]=max[i][j]-allocate[i][j];
}

 
 for (i = 0; i < n; i++) { 
        if (f[i] == 0) { 
               int flag = 0; 
               for (j = 0; j < 3; j++) { 
                    if (need[i][j] > available[j]){ 
                      flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (int y = 0; y < 3; y++) 
                        available[y] += allocate[i][y]; 
                    f[i] = 1; 
                  i=0;
                } 
            } 
            if(i==n-1)
            break;          
        }
  
   printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
    }
    
