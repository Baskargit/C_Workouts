// O(n2) time complexity
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// Below is accepted solution
// 0.75 seconds

// Inefficient soln
#define MAX 501


int getId(int M[MAX][MAX], int n)
{
    int celebrityexists = 0;
    int celebritycount = 0;
    int celebrityindex;
    
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        
        for(int j=0; j<n; j++)
        {
            // he may or maynot know himself
            if(i != j) 
            {
                sum += M[i][j];   
            }
        }
        
        if(sum == 0) {
            celebritycount++;
            celebrityindex = i;
            celebrityexists = 1;
        }
    }
    
    if(celebrityexists && celebritycount == 1)
    {
        for(int i=0; i<n; i++)
        {
            if(i != celebrityindex) 
            {
                // If anyone don't know the celebrity
                if(M[i][celebrityindex] != 1)
                {
                    return -1;
                }
            }
        }
        
        // Everyone knows the celebrity
        return celebrityindex;
    }
    else
    {
        return -1;
    }
}