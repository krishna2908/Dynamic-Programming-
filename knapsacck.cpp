#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    
    int n=3,sum=50;
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int table[n+1][sum+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=sum;j++)table[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=wt[i-1])
            {
                table[i][j]=max(table[i-1][j],val[i-1]+table[i-1][j-wt[i-1]]);
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
            
        }
    }
    cout<<table[n][sum]<<endl;
    return 0;
}