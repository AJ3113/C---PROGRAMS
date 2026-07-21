#include<stdio.h>
#define MAX 100
int main()
{
    int n;
    int job[MAX],profit[MAX],deadline[MAX],slot[MAX]={0};
    printf("Enter the number of jobs: \n");
    scanf("%d",&n);
    printf("Enter the profit and deadline for each jobs: \n");
    for(int i=0;i<n;i++)
    {
        job[i]=i+1; 
        scanf("%d %d",&profit[i],&deadline[i]);
    }
    //arranging jobs in dercreasing order of profit
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(profit[i]<profit[j])
            {
                int temp;
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=deadline[i];j>0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=job[i];
                break;
            }
        }
    }
    printf("\nThe scheduled jobs are :\n");
    for(int i=1;i<n;i++)
    {
        if(slot[i]!=0)
        {
            printf("slot %d->job %d\n",i,slot[i]);
        }
    }

}