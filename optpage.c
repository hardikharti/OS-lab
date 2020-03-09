#include<stdio.h>

int main(){
	int n;
	printf("enter the page string length");
	scanf("%d",&n);
	
	int pstr[n];
	printf("enter the page strings");
	for(int i=0;i<n;i++){
		scanf("%d",&pstr[i]);
	}

	int pf;
	printf("enter the page frame");
	scanf("%d",&pf);
	
	int ch[pf];
	int index[pf];
	int hit=0,fault=pf;
	for(int i=0;i<pf;i++){ch[i]=pstr[i];index[i]=100;}
	
	
	int count;
	int x=0;
	
	for(int j=0;j<pf;j++){
			printf("%d",ch[j]);
		}
		printf("\n");	
	
	int min=0;
	for(int i=pf;i<n;i++){
		count=0;
		for(int j=0;j<pf;j++){
			if(pstr[i]==ch[j]){hit++;count=1;break;}
		
		}
		
		if(count==0){
		
			for(int i=0;i<pf;i++){index[i]=100;}
			
			for(int j=0;j<pf;j++){
				
			for(int k=i;k<n;k++){
				if (ch[j]==pstr[k]){index[j]=k;break;}
		}
		
		}
		min=0;
		for(int i=0;i<pf;i++){if(index[i]>index[min]) min=i;}
		
		ch[min]=pstr[i];
		fault++;
		}
		for(int j=0;j<pf;j++){
			printf("%d",ch[j]);
		}
		printf("\n");	
		
				
	}
	
	printf("hits=%d \t faults=%d",hit,fault);
	
	
	
	
	
	


}
