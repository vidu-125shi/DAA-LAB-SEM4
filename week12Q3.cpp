#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printPermutations(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main() {
    string input;
    cin >> input;
    cout<<"Permutation of the string in lexicographic order"<<endl;
    printPermutations(input);
    return 0;
}
