#include<stdio.h>
#define MAX 100
int main()
{
    int n;
    printf("Enter the number of items: \n");
    scanf("%d",&n);
    float weight[MAX],profit[MAX],ratio[MAX],capacity,totalprofit=0;
    printf("Enter the weight and profit: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
        ratio[i]=profit[i]/weight[i];
    }
    printf("Enter the capacity of knapsack: \n");
    scanf("%f",&capacity);
    //arranging items in decreasing order of ratio
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                float temp;
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(weight[i]<=capacity)
        {
            capacity-=weight[i];
            totalprofit+=profit[i];
        }
        else
        {
            totalprofit+=profit[i]*capacity/weight[i];
            break;
        }
    }
    printf("Total profit: %f\n", totalprofit);  
    return 0;
}