#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int sum;
    cin>>sum;
    int table[n+1][sum+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=sum;j++)cin>>table[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            {
                table[i][j]=1;
                continue;
            }    
            if(j>=a[i])
            {
                table[i][j]=(i==0? 0 :table[i-1][j])+table[i][j-a[i]];
            }
            else
            {
                table[i][j]=(i==0? 0 :table[i-1][j]);
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<table[i][j]<<" ";
        }
    cout<<endl;
        
    }
    cout<<table[n-1][sum];
    return 0;
}    
