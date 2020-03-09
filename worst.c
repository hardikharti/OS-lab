#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,m,n;
    printf("Enter the number of blocks\n");
    scanf("%d",&m);
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int p[n],b[m],al[n],in[n];
    printf("Enter the size  of each block\n");
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    printf("Enter the size  of each process\n");
    for(i=0;i<n;i++)
    {
        al[i]=0;
        scanf("%d",&p[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(b[al[i]]<=b[j] &&p[i]<b[j] && b[j]!=0)
            al[i]=j;
        }
        in[i]=b[al[i]]-p[i];
        b[al[i]]=0;

    }
    printf("\nProcess\tSize\tBlockno\tinternalfrag\n");
    for(i=0;i<n;i++)
    {
       if(al[i]!=0)
        printf("%d\t%d\t%d\t%d\n",i,p[i],al[i],in[i]);
        else
        printf("%d\t%d\tNot allocated\t\n",i,p[i]);
    }

    
}
