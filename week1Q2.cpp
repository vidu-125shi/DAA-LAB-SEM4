#include<iostream>
using namespace std;
int binary(int a[],int l,int r,int k,int&comp)
{
    while(l<=r)
    {  
        int m=(l+r)/2;
        comp++;
        if (a[m]==k)
           return m;
        else if(a[m]<k)
           l=m+1;
        else
          r=m-1;
    }
    return -1;
}
int main()
{
    int j,i,n,t,k;
    cout<<"enter nuumber of test case";
    cin>>t;
    for(j=0;j<t;j++)
    {
        cout<<"enter number of elements";
        cin>>n;
        int a[n],comp=0;
        cout<<"enter elements";
        for(i=0;i<n;i++)
        {
	cin>>a[i];
       }
        cout<<"enter the key";
        cin>>k;
        int l=0;
        int r=n-1;
        int p=binary(a,l,r,k,comp);
        if(p==-1)
        {
            cout<<"not present "<<comp<<endl;
        }
        else
        {
            cout<<"present"<<comp<<endl;
        }
    }
    return 0;
}
