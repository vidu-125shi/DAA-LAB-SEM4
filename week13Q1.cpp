#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the caharatcer array: ";
    cin >> n;
    cout << "Enter the character array elements: ";
    vector<char> charArray(n);
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }
    const int MAX_CHAR = 256;
    int freq[MAX_CHAR] = {0};
    for (char ch : charArray) {
        freq[ch]++;
    }
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            cout << char(i) << ": " << freq[i] << endl;
        }
    }
    return 0;
}

