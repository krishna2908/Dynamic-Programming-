#include <iostream>
using namespace std;
int will_It_get_sum(int *a,int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=sum;j++)t[i][j]=0;
    for(int i=0;i<=n;i++)t[i][0]=1;
    for(int i=1;i<=n;i++)
    {
     //   cout<<a[i-1]<<endl;
        for(int j=1;j<=sum;j++)
        {
            if(j>=a[i-1])
            {
                
                t[i][j]=(t[i-1][j]||t[i-1][j-a[i-1]]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
            
        }
    }

cout<<" get table her "<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<t[i][j]<<" ";
        }
    cout<<endl;
        
    }
    return t[n][sum];
}
int main()
{
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<will_It_get_sum(a,sum,n)<<endl;
    return 0;
}    
    