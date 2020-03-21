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
struct output *jobsequence(int jobcount,int maxdeadline,struct Job *jobs[jobcount]);

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

        sortbyprofit(jobs,jobcount);

        struct output *result = jobsequence(jobcount,maxdeadline,jobs);
        printf("%d %d\n",result->totaljobs,result->totalprofit);
    }
    
	return 0;
}

struct output *jobsequence(int jobcount,int maxdeadline,struct Job *jobs[jobcount])
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

