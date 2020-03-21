// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

#include<stdio.h>
#include<stdlib.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

struct output
{
    int totaljobs;
    int totalprofit;
};

void sortbyprofit(struct Job *jobs[],int jobcount);
void jobsequence(struct Job *jobs,int jobcount,int *maxjob,int *maxprofit,int maxdeadline);

void jobSeq(int jobcount,int maxdeadline,struct Job *jobs[jobcount],int *maxjob,int *maxprofit,int currentJob,int currentDeadlinecount,int currentProfit,int currentJobCount);

struct output *jobseq1(int jobcount,int maxdeadline,struct Job *jobs[jobcount]);
void printSlots(int maxdeadline,int deadline[maxdeadline]);

int main()
{
	int testCaseCount;
    scanf("%d",&testCaseCount);
    
    for(int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        int jobcount;
        scanf("%d",&jobcount);

        int maxdeadline = 0;
        struct Job *jobs[jobcount];
        for (int i = 0; i < jobcount; i++)
        {
            struct Job *job = (struct Job *)malloc(sizeof(struct Job));

            if (job != NULL) {
                scanf("%d %d %d",&job->id,&job->deadline,&job->profit);
                jobs[i] = job;
            }
            
            maxdeadline = (job->deadline > maxdeadline) ? job->deadline : maxdeadline;
        }

        printf("Maxdeadline : %d\n",maxdeadline);

        printf("After profit based sort \n");
        sortbyprofit(jobs,jobcount);
        printf("id  Dead  Profit\n");
        for (int i = 0; i < jobcount; i++)
        {
            printf("%d %d %d\n",jobs[i]->id,jobs[i]->deadline,jobs[i]->profit);
        }

        int maxjob = 0,maxprofit = 0;
        
        // jobSeq(jobcount,maxdeadline,jobs,&maxjob,&maxprofit,0,0,0,0);

        struct output *result = jobseq1(jobcount,maxdeadline,jobs);
        maxjob = result->totaljobs;
        maxprofit = result->totalprofit;

        printf("%d %d\n",maxjob,maxprofit);
    }
    
	return 0;
}

struct output *jobseq1(int jobcount,int maxdeadline,struct Job *jobs[jobcount])
{
    struct output *result = (struct output *)malloc(sizeof(struct output));
    result->totaljobs = 0;
    result->totalprofit = 0;

    int slots[maxdeadline + 1];
    for (int i = 1; i <= maxdeadline; i++)
    {
        slots[i] = 0;
    }
    
    for (int i = 0; i < jobcount; i++) // Actual logic
    {
        if (slots[jobs[i]->deadline] == 0)
        {
            slots[jobs[i]->deadline] = jobs[i]->profit;
        }
        else
        {
            for (int j = jobs[i]->deadline - 1; j >= 1; j--)
            {
                if (jobs[i]->profit == 34)
                {
                    printf("\n\n 34 = %d\n",j);
                }
                
                if (jobs[i]->deadline > slots[j] && slots[j] == 0)
                {
                    slots[j] = jobs[i]->profit;
                    break;
                }
            }
        }
    }


    for (int i = 1; i <= maxdeadline; i++)
    {
        if (slots[i])
        {
            result->totaljobs += 1;
            result->totalprofit += slots[i];
        }
    }

    printSlots(maxdeadline,slots);

    return result;
}

void sortbyprofit(struct Job *jobs[],int jobcount)
{
    // Bubble sort
    for (int i = 0; i < jobcount; i++)
    {
        for (int j = i+1; j < jobcount; j++)
        {
            if (jobs[i]->profit < jobs[j]->profit) 
            {
                struct Job *temp = jobs[i];

                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

void printSlots(int maxdeadline,int slots[maxdeadline])
{
    printf("\nPrinting slot values \n");

    int counter = 0;
    for (int i = 0; i < maxdeadline + 1; i++)
    {
        printf("i = %d ===> profit = %d ===> counter = %d\n",i,slots[i],(slots[i]) ? ++counter : 0);
    }
    
    printf("\n");
}

void jobSeq(int jobcount,int maxdeadline,struct Job *jobs[jobcount],int *maxjob,int *maxprofit,int currentJob,int currentDeadlinecount,int currentProfit,int currentJobCount)
{
    if (currentJob < jobcount)
    {
        if (jobs[currentJob]->deadline + currentDeadlinecount <= maxdeadline)
        {
            // Include
            *maxprofit = (jobs[currentJob]->profit + currentProfit > *maxprofit) ? jobs[currentJob]->profit + currentProfit : *maxprofit;
            *maxjob = (currentJob + 1 > *maxjob) ? currentJob + 1 : *maxjob;
            jobSeq(jobcount,maxdeadline,jobs,maxjob,maxprofit,currentJob + 1,jobs[currentJob]->deadline + currentDeadlinecount,currentProfit + jobs[currentJob]->profit,currentJobCount + 1);
        }

        // Else        
        // Not include 
        jobSeq(jobcount,maxdeadline,jobs,maxjob,maxprofit,currentJob + 1,currentDeadlinecount,currentProfit,currentJobCount);
    }
    else
    {
        return;
    }
}

void jobsequence(struct Job *jobs,int jobcount,int *maxjob,int *maxprofit,int maxdeadline)
{
    
    while (jobcount >= 0)
    {
        
        jobcount--;
    }
    
}


