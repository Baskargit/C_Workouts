// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

#include<stdio.h>
#include<stdlib.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

void sortbyprofit(struct Job *jobs[],int jobcount);
void jobsequence(struct Job *jobs,int jobcount,int *maxjob,int *maxprofit,int maxdeadline);

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
        for (int i = 0; i < jobcount; i++)
        {
            printf("%d %d %d\n",jobs[i]->id,jobs[i]->deadline,jobs[i]->profit);
        }

        int maxjob = 0,maxprofit = 0;
        // jobsequence(jobs,jobcount,maxjob,maxprofit,maxdeadline);
        printf("%d %d\n",maxjob,maxprofit);
    }
    
	return 0;
}

void jobsequence(struct Job *jobs,int jobcount,int *maxjob,int *maxprofit,int maxdeadline)
{
    
    while (jobcount >= 0)
    {
        
        jobcount--;
    }
    
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

