
#include<stdio.h>
void main()
{
    int n,t;
    scanf("%d",&t);
    int f=1;
    while(t!=0)
    {
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            k=j+1;
            if(a[i]+a[j] == a[k]){
             
                printf("%d %d %d\n",i+1,j+1,k+1);f=0;
            }
            
        }
    }
   
    if(f==1){
    printf("No sequence found");
    
    }
    t--;
    }
}
