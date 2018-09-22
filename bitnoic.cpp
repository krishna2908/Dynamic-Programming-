#include<iostream>
#include<stdlib.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)return a;
    return b;
}
int* lis_(int *a,int n)
{
   int *lis=(int*)(malloc(sizeof(int)*n));
   for(int i=0;i<n;i++)lis[i]=1;
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<i;j++)
       {
           if(a[i]>a[j])
           {
             lis[i]=max(lis[i],lis[j]+1);  
           }
       }
   }
return lis;
    
}
int main()
{
    int n=16;
    //cin>>n;
    int a[]{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 
			13, 3, 11, 7, 15};
    //for(int i=0;i<n;i++)cin>>a[i];
    int *li=lis_(a,n);
    int rev[n];
    for(int i=0,j=n-1;i<n;i++)
    {
        rev[i]=a[j--];
    }
    int *lds=lis_(rev,n);
    cout<<"increasing order "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<li[i]<<" ";
    }
    cout<<endl<<"decreasing order "<<endl;
    for(int i=n-1;i!=-1;i--)
    {
        cout<<lds[i]<<" ";
    }
    int re_lds[n];
    for(int i=0,j=n-1;i<n;i++)
    {
        re_lds[i]=lds[j--];
    }
    int m=li[0]+re_lds[0]-1;
    for(int i=1;i<n;i++)
    {
        m=max(m,li[i]+re_lds[i]-1);
    }
    cout<<"bitnoiclength "<<m<<endl;
    
return 0;    
}