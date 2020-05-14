// 0 1 Knapsack using Dynamic Programming.
#include<bits/stdc++.h>
using namespace std;
long long int a[107][100007];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    long long int n,W;
    cin>>n>>W;
    long long int v[n+1],w[n+1];		//values,weight
    
    for(long long int i=1;i<=n;i++)
    {
        long long int x;
        cin>>w[i]>>v[i];
        
    }
    
    long long int k=1; 
    for(long long int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(w[i]>w[j])
            {
                long long int temp=w[i];
                w[i]=w[j];
                w[j]=temp;
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
    
    
    for(long long int i=0;i<=n;i++)
    {
        for(long long int j=0;j<=W;j++)
        {
            if (i==0 || j==0)
            {
                a[i][j]=0;
                continue;
            }
            
            if((w[i])>j)
            a[i][j]=a[i-1][j];
            
            else
            {
                a[i][j]=max(a[i-1][j-w[i]] + v[i],a[i-1][j]);
            }
            
            
        }
    }
    cout<<(a[n][W]);
}
//Time Complexity=(n*w)