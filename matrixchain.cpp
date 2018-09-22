#include<iostream>
using namespace std;
int min(int a,int b)
{
    if(a>b)return b;
    return a;
}
int main()
{
    int a[]={2,3,6,4,5};
    int t[5][5];
    int n=5;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)t[i][j]=0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            int q=1000000007;
            for(int k=i;k<=j-1;k++)
            {
                int tmp=t[i][k]+t[k+1][j]+a[i-1]*a[k]*a[j];
                q=min(q,tmp);   
            }
            t[i][j]=q;
        }
    }
  for(int i=1;i<n;i++)
  {
      for(int j=1;j<n;j++)
      {
          cout<<t[i][j]<<" ";
      }
      cout<<endl;
  }
    cout<<t[1][n-1]<<endl;
    return 0;
}