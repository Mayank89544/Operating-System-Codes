#include<stdio.h>

typedef struct processes
{
    int ID , arrival , burst , start , complete , response , TAT , waiting;
}process;

int main()
{
    int n;
    printf("Enter the no. of Processes : ");
    scanf("%d",&n);

    process p[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter the P%d arrival and burst time : ",i+1);
        scanf("%d%d",&p[i].arrival , &p[i].burst);

        p[i].ID = i+1;;
        p[i].complete = 0;
        p[i].response = 0;
        p[i].start = 0;
        p[i].response = 0;
    }

    int TimeSum = 0 , idle_time = 0 , Complete = 0;
    
    while(Complete != n)
    {
        int pid = -1;
        int mini = 1e8;

        for(int i=0;i<n;i++)
        {
            if(p[i].arrival <= TimeSum && p[i].complete == 0)
            {
                if(p[i].burst < mini)
                {
                    pid = i;
                    mini = p[i].burst;
                }
                else if(p[i].burst == mini)
                {
                    if(p[i].arrival < p[pid].arrival)
                    {
                        pid = i;
                    }
                }
            }
        }
        if(pid == -1)
        {
            printf("#");
            idle_time++;
            TimeSum++;
        }
        else
        {
            printf("P%d",p[pid].ID);
            p[pid].start = TimeSum;
            TimeSum += p[pid].burst;
            Complete++;
            p[pid].complete = TimeSum;
        }
    }
    printf("\nID\tAT\tBT\tST\tCT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].ID , p[i].arrival , p[i].burst , p[i].start , p[i].complete);
    }


}