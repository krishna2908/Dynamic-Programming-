#include<iostream>
using namespace std;
int min(int a,int b)
{
    if(a>b)return b;
    return a;
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    int table[n][n],mark[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            table[i][j]=0;
            mark[i][j]=0;
        }
        
    }
for(int i=0;i<n;i++)
{
    mark[i][i]=1;
    table[i][i]=0;
}
for(int l=2;l<=n;l++)
{
    for(int i=0;i<n-l+1;i++)
    {
        int j=i+l-1;
        if(l==2&&str[i]==str[j])
        {
         table[i][j]=0;
         mark[i][j]=1;
         continue;
        }
        if(str[i]==str[j]&&mark[i+1][j-1])
        {
            mark[i][j]=1;
        }
        if(mark[i][j])
        {
            table[i][j]=0;
        }
       else
       {
           table[i][j]=1000000007;
           for(int k=i;k<=j-1;k++)
           {
               
               table[i][j]=min(table[i][j],1+table[i][k]+table[k+1][j]);
           }
       }
    }   
}
cout<<table[0][n-1]<<endl;
return 0;
}
        