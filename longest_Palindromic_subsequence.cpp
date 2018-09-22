#include <iostream>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int n=str.length();
  int table[n][n];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
        table[i][j]=0;
      }
  }
  for(int i=0;i<n;i++)table[i][i]=1;
  for(int l=2;l<=n;l++)
  {
      for(int i=0;i<n-l+1;i++)
      {
          int j=i+l-1;
          if(str[i]==str[j]&&l==2)
          {
              table[i][j]=2;
             continue;
          }
          if(str[i]==str[j])
          {
              table[i][j]=table[i+1][j-1]+2;
              continue;
          }
          else
          {
              table[i][j]=max(table[i+1][j],table[i][j-1]);
          }
          
      }
  }
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
      {
          cout<<table[i][j]<<" ";
               
          
      }
      cout<<endl;
   }
  cout<<table[0][n-1]<<endl;
  
  return 0;
}