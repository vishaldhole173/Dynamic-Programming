
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

int solve(int wt[],int val[],int w,int n)
{
    if(w==0 or n==-1) return 0;
    if(t[w][n]!=-1) return t[w][n];
    if(wt[n]>w)
    {
        return t[w][n]=solve(wt,val,w,n-1);
    }
    return max(val[n]+solve(wt,val,w-wt[n],n-1),solve(wt,val,w,n-1));
}

int knapSack(int wt[],int val[],int w,int n)
{
    memset(t,-1,sizeof(t));

    return solve(wt,val,w,n-1);
    
}

int main()
{   
    
    int wt[]={4,5,6};
    int val[]={1,2,3};
    int n=3;
    int w=3;
    cout<<knapSack(wt,val,w,n)<<endl;
}