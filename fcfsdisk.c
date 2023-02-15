#include<stdio.h>
#include<stdlib.h>
int main()
{
    int in,n,i,d,Thm1=0,Thm2=0,Thm=0,k=1,j=1,p,q,swap=0,pos;
    printf("Initial position");
    scanf("\n %d",&in);
    printf("\n Enter number ofrequests");
    scanf("\n %d",&n);
    printf("Enter the total disk size \n");
    scanf("%d",&d);
    int a[n],b[10],c[10];

    printf("Enter the sequence");
    for( i=0;i<n;i++)
    {
        scanf("\n %d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
            if(a[i]<in)
            {
                //for 0 to head-1
                b[k]=a[i];
                k=k+1;
            }
            else
            {
                c[j]=a[i];
                j=j+1;
            }
            c[0]=in;
            b[0]=0;
    }
    //Sorting O to head -1
    for(p=0;p<k;p++)
    {
        pos=p;
        for(q=p+1;q<k;q++)
        {
            if(b[pos]>b[q])
            {
                pos=q;
            }
            if(pos!=p)
            {
            swap=b[p];
            b[p]=b[pos];
            b[pos]=swap;
            }
        }
    }
    //sorting for initial to last request
    
    for(p=0;p<j;p++)
    {
        pos=p;
        for(q=p+1;q<j;q++)
        {
            if(c[pos]>c[q])
            {
                pos=q;
            }
            if(pos!=p)
            {
                swap=c[p];
                c[p]=c[pos];
                c[pos]=swap;
            }
        }
    }
     printf("\n k:  %d",k);
      printf("\n j:  %d",j);
    for(i=0;i<k;i++)
    {
        printf("\n %d",b[i]);
    }
    for(i=0;i<j;i++)
    {
        printf("\n %d",c[i]);
    }
    
     for( i=0;i<j;i++)
    {
        Thm1=Thm1+abs(c[i+1]-c[i]);
        
        
    }
    printf("Thm1 :%d",Thm1);
     for( i=0;i<k;i++)
    {
        Thm2=Thm2+abs(b[i+1]-b[i]);
       
    }
     printf("\n Thm2 :%d",Thm2);
    Thm=Thm1+Thm2+(d-1)+(d-1-c[j]);
    printf("Total head movement:%d",Thm);
}