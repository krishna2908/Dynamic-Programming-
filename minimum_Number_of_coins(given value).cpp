#include <iostream>
using namespace std;

#define INT_MAX 1000000007

int min(int a,int b)

{
    
if(a>b)return b;
   
 return a;

}

int main()

{
 
   int sum;
   
 cin>>sum;
   
 int n;

    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    int dp[sum+1];
    dp[0]=0;
    for(int i=1;i<=sum;i++)dp[i]=INT_MAX;
    for(int s=1;s<=sum;s++)
    {
        for(int j=0;j<n;j++)
        {
            if(s>=a[j])
            {
                int m=dp[s-a[j]];
                if(m!=INT_MAX)
                {
                    dp[s]=min(dp[s],1+m);               
                }
            }
        }
    }
    for(int i=0;i<=sum;i++)cout<<dp[i]<<endl;
    cout<<" res ="<<dp[sum]<<endl;
    return 0;
}
