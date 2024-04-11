
#include<stdio.h>
void main()
{
    int n,t;
    scanf("%d",&t);
    
    while(t!=0)
    {
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int key,c=0;
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++){
            
            if(a[i]-a[j] == key || a[j]-a[i] == key){
                c++;
            }
        }
    }

    printf("%d\n",c);
    t--;
    }
}
