#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
struct stu
{
    int a,b;
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    struct stu table[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            table[i][j].a=0;
            table[i][j].b=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        table[i][i].a=arr[i];
        table[i][i].b=0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j=i+l-1;
            //i..j we have an array 
            //pick up i 
            int x1=arr[i]+table[i+1][j].b;
            int y1=table[i+1][j].a;
            //pick up j
            int x2=arr[j]+table[i][j-1].b;
            int y2=table[i][j-1].a;
            //now check which is largets value 
            //if picking i is the best option then
            if(x1>x2)
            {
                table[i][j].a=x1;
                table[i][j].b=y1;
            }
            //picking up j is best option 
            else if(x1<x2)
            {
                table[i][j].a=x2;
                table[i][j].b=y2;
            }
            //
            else
            {
                  table[i][j].a=x2;
                  table[i][j].b=max(y1,y2);
                
            }
            
        }
    }
     cout << table[0][n-1].a <<"  "<< table[0][n-1].b <<endl;
    return 0;
}