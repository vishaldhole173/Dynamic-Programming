#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[],int val[],int w,int n)
{   
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
        
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(wt[i-1]<w)
            {
                t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
        
    }
    return t[n][w];
}
int main()
{   
    int wt[]={4,5,6};
    int val[]={1,2,3};
    int n=3;
    int w=3;
    cout<<knapSack(wt,val,w,n)<<endl;
}
