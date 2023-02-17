#include<stdio.h>
int main()
{
    int i,nop,temp[10],bt[10],at[10],slice;
    int rem,sum=0,count=0,wt=0,tat=0;
    float avg_wt,avg_tat;

    printf("Enter the number of processes :");
    scanf("%d",&nop);
    rem=nop;

    for(i=0;i<nop;i++)
    {
        printf("Arrival time of Process[%d] :",i+1);
        scanf("%d",&at[i]);
        printf("Burst time of Process[%d] :",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];

    }

    printf("Enter the time slice");
    scanf("%d",&slice);

    printf("\nProcess\t\tBT\tTAT\tWT\n");
    for(sum=0,i=0;rem!=0;)
    {
        if(temp[i]<=slice&&temp[i]>0)
        {
            sum+=temp[i];
            temp[i]=0;count=1;
        }
        else if(temp[i]>slice)
        {
            temp[i]=temp[i]-slice;
            sum+=slice;
        }
        if(temp[i]==0&&count==1)
        {
            rem--;
            printf("Process[%d]\t%d\t%d\t%d\n",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }

        if(i==nop-1)
        {i=0;}
        else if(at[i+1]<=sum)
        {i++;}
        else
        {i=0;}

    }
    avg_wt=wt*1.0/nop;
    avg_tat=tat*1.0/nop;
    printf("Avg tat : %f",avg_tat);
    printf("Avg wt  : %f",avg_wt);

}