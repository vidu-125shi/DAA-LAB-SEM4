#include<stdio.h>
void main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        
        int key;int c=0;
        scanf("%d",&key);
      
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(a[i]+a[j] == key){
                    printf("\n%d - %d\n",a[i],a[j]);
                    c++;
                }
            }
        }
        if(c == 0){
            printf("no such elements exist");

        }
    }
}