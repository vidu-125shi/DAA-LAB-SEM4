#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void findMaxOccurrence(char arr[], int size) {
    int frequency[26] = {0}; 
    int maxCount = 0;
    char maxChar;

    
    for (int i = 0; i < size; i++) {
        frequency[arr[i] - 'a']++;
    }

    
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            maxChar = i + 'a';
        }
    }

   printf("%c - %d",maxChar,maxCount);
}

void main() {
    int t;
    scanf("%d",&t);
    while(t!=0){
    char arr[MAX_SIZE];
    int size;
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        scanf(" %c", &arr[i]);
    }

  findMaxOccurrence(arr, size);
    t--;
    }

}
