#include<stdio.h>
int  main()
 {
     int n;
     printf("Enter the number of processes:\n");
     scanf("%d",&n);
     int a[n],b[n],t[n],w[n],i,j,flag=0,idle[100],x=0,cs=0,last=-2; 
     printf("Enter the arrival time of each process:\n");
     for(i=0;i<n;i++)
            scanf("%d",&a[i]);
     printf("Enter the burst time of each process:\n");
     for(i=0;i<n;i++)
            scanf("%d",&b[i]);
     for(i=0;;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[j]<=i && a[j]!=-1)
             {
                 i=i+b[j];
                 flag++;
                 t[j]=i-a[j];
                 w[j]=t[j]-b[j];
                 a[j]=-1;
                j=0;
             }
         }
         if(j==n)
         {
             idle[x]=i;
             x++;
         }
         if(flag==n)
         break;
     }
     printf("   TAT  WT\n");
     for(i=0;i<n;i++)
            printf("%d)  %d   %d\n",i+1,t[i],w[i]);
     printf("\nCPU Idle time\n");
     for(i=0;i<x-1;i++)
            printf("%d to %d\n",idle[i],idle[i]+1);

     printf("\nContext switches:%d\n",cs);
 }