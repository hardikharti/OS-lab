#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,m,n,x=1,block;
    printf("Enter the number of blocks\n");
    scanf("%d",&m);
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int p[n],al[n];
    printf("Enter the size  of each block\n");
       scanf("%d",&block);
    printf("Enter the size  of each process\n");
    for(i=0;i<n;i++)
    {
        al[i]=0;
        scanf("%d",&p[i]);
    }
    for(i=0;i<n && m!=0;i++)
    {
       if(p[i]<=block)
       {
            al[i]=x;
            x++;
            m--;
       }
       else
       {
           al[i]=-1;
       }
       

    }
    printf("\nProcess\tSize\tBlockno\tinternal frag\n");
    for(i=0;i<n;i++)
    {
        if(al[i]!=-1)
        printf("%d\t%d\t%d\t%d\n",i,p[i],al[i],block-p[i]);
        else
        {
        printf("%d\t%d\tnot allocated\n",i,p[i]);
        }
        
    }

    
}
