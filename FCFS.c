#include<stdio.h>
typedef struct processes
{
    int ID , arrival , burst , start , complete , TAT , Waiting , Response;
}process;

int main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%d" , &n);

    process p[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter the value of p%d arrival and Burst Time : ",i+1);
        scanf("%d%d",&p[i].arrival , &p[i].burst);
        p[i].ID = i+1;
        p[i].start = 0;
        p[i].complete = 0;
        p[i].TAT = 0;
        p[i].Waiting = 0;
        p[i].Response = 0;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].arrival > p[j+1].arrival)
            {
                process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    printf("Gantts Chart : \n");
    int TimeSum = 0;
    for(int i=0;i<n;i++)
    {
        if(TimeSum < p[i].arrival)
        {
            printf("#");
            TimeSum = p[i].arrival;
        }
        printf("P%d\t" , p[i].ID);
        p[i].start = TimeSum;
        p[i].Response = p[i].start - p[i].arrival;
        TimeSum += p[i].burst;
        p[i].complete = TimeSum;
        p[i].TAT = p[i].complete - p[i].arrival;
    }

    printf("\nID\tAT\tBT\tST\tCT\tRT\tTAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].ID , p[i].arrival , p[i].burst , p[i].start , p[i].complete , p[i].Response , p[i].TAT);
    }


}