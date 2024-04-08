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
    int key,c=0;int comparisons=0;
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(a[i] == key){
            comparisons++;
            printf("Present %d\n",comparisons); 
            
            break;
        }
        else{
            comparisons++;
            c++;
        }
    }
    if(c == n){
        printf("Not Present %d\n",comparisons);
    }
        
}
}