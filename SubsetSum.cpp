#include<iostream>
using namespace std;

bool subsetSum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)
            {
                t[i][j]=false;
            }
        }
        
    }
     for(int i=0;i<n+1;i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)
            {
                t[i][j]=true;
            }
        }
        
    }
    for(int i=0;i<n+1;i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
        
    }
    
    return t[n][sum];
}
bool issunset(int arr[],int sum,int n)
{
    bool dp[n+1][sum+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(i==0)
            {
                dp[i][j]=false;
            }
        }
        
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j==0)
            {
                dp[i][j]=true;
            }
        }
        
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(arr[i-1]<sum)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    
    return dp[n][sum];
    
}
bool set(int arr[],int sum,int n)
{   
    if(n==0 && sum==0)
    {
        return true;
    }
    if(n==0)
    {
        return false;
    }
    if(sum==0)
    {
        return true;
    }
    if(arr[n-1]<sum)
    {
        return set(arr,sum-arr[n-1],n-1) || set(arr,sum,n-1);
    }
    return set(arr,sum,n-1);
}
int main()
{
    int arr[]={3, 34, 4, 12, 5, 2};
    int n=6;
    int sum=37;
    cout<<subsetSum(arr,sum,n)<<endl<<issunset(arr,sum,n)<<endl<<set(arr,sum,n)<<endl;
}