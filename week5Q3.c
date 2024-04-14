#include<stdio.h>
void main()
{
     int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int m;
        scanf("%d", &m);
    int a1[m];
    for(int i=0;i<m;i++){
        scanf("%d",&a1[i]);
    }
    int n;
    scanf("%d",&n);
    int a2[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a2[i]);
    }
    int i=0,j=0;
    while(i<m && j<n){
        if(a1[i]<a2[j]){
            i++;
        }
        else if(a2[j]< a1[i]){
            j++;
        }
        else{
            printf("%d ",a1[i]);
            i++;
            j++;
        }
    }


        
        
}