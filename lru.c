#include<stdio.h>
int main()
{
 int n,i,j,k ; 
    printf("Enter the number of pages\n");
	scanf("%d",&n);
    int page[n]; 
    printf("Enter the page string\n");
    for(int i=0;i<n;i++)
    scanf("%d",&page[i]);    
	
	int pf,hit=0,fault=0;
    int p=0;
    printf("Enter the page frame\n");
    scanf("%d",&pf);

    int x[pf],pr[pf];
    for(i=0;i<n;i++)
    {
        if(i<pf)
        {
        x[i]=page[i];
        pr[i]=i;
        continue;
        }
        for(j=0;j<pf;j++)
        {
        if(page[i]==x[j])
          {hit+=1;
          
          for(k=0;k<pf;k++)
          {
              if(k!=j && pr[k]>pr[j])
              pr[k]--;
          }
          pr[j]=pf-1;
          break;
          }
        }
        if(j==pf)
        {
            for(k=0;k<pf;k++)
          {
              if(pr[k]==0)
              {x[k]=page[i];
              pr[k]=pf-1;
              }
              else
              {
                  pr[k]--;
              }
              
            
        }
        }
        for(j=0;j<pf;j++)
        printf("%d",x[j]);
        printf("\n");
        
    }
    printf("\nHits=%d , Faults=%d",hit,n-hit);

}