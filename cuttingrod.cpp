#include <iostream>
using namespace std;

int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)cin>>a[i];
// int length=n;
 int table[n+1][n+1];
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         table[i][j]=0;
     }
 }
 for(int i=1;i<=n;i++)
 {
     for(int j=0;j<=n;j++)
     {
         if(j==0)
         {
             table[i][j]=0;
             continue;
         }
         if(j>=i)
         {
             table[i][j]=max(table[i][j-i]+a[i-1],table[i-1][j]);
         }
         else
         {
             table[i][j]=table[i-1][j];
         }
     }
 }
 cout<<table[n][n]<<endl;
 return 0;
}
 