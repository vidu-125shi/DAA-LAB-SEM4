#include <stdio.h>


void jumpSearch(int a[],int n,int key_element){
    int l = 0, r = n - 1, c = 0, f = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (key_element == a[mid]) {
            c++;

           for(int left=mid-1;left>=0;left--){
            if(a[left]==key_element){
                c++;
            }
           }

            for(int right=mid+1;right<n;right++){
            if(a[right]==key_element){
                c++;
            }
           }
            f = 0;
            break;
        } else if (a[mid] > key_element) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (f != 1) {
        printf("%d - %d\n", key_element, c);
    } else {
        printf("Element %d not found in the array.\n", key_element);
    }
}


void main() {
 
    int t;
    printf("enter number of test cases\n");scanf("%d",&t);
    for(int i=0;i<t;i++){
         int n;int key_element; 
         printf("enter size of array\n");scanf("%d",&n);

  int a[n] ;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("enter element to be searched\n");scanf("%d",&key_element);
    jumpSearch(a,n,key_element);
    }
}
