#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,p[20],n,f,option;
	printf("Enter the no. of pages :- ");
	scanf("%d",&n);
	printf("Enter no. of frames :- ");
	scanf("%d",&f);
	printf("Enter the page references :- \n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	int j,k,pageFault=0,frames[10],flag,point=0,freq[10],min;
	for(i=0;i<f;i++)
    {
		frames[i]=-1;
        	freq[i]=0;
	}
	printf("\nREF\t  Frames\n");
	for(i=0;i<n;i++)
    {
		flag=0;
		for(j=0;j<f;j++)
        {
			if(frames[j]==p[i])
            { //frame already present
				flag=1;
				printf("%d *\t",p[i]);
				freq[j]++;
				break;
			}
		}
		if(flag==0)//frame not present
        {
			min=point;
			k=point;
			for(j=0;j<f;j++)
            {
				if(freq[min]>freq[k])
                {
					min=k;
					point=(point+1)%f;
				}
				k=(k+1)%f;
			}
			frames[min]=p[i];
			point=(point+1)%f;
			pageFault++;
			freq[min]=1;
			printf("%d\t",p[i]);
		}
		for(j=0;j<f;j++){
            		if(frames[j]!=-1){
                		printf("%d   ",frames[j]);
            		}
		}
		printf("\n");
	}
	printf("No. of Page Fault :- %d",pageFault);
}
