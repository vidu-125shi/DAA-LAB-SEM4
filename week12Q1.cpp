#include<iostream>
#include<math.h>
using namespace std;

int lcs(string x, string y)
{
    int n = x.size();
    int m = y.size();

    int res[n+1][m+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                res[i][j] = 0;
            }
            else if(x[i - 1] == y[j - 1])
            {
                res[i][j] = res[i-1][j-1] + 1;
            }
            else
            {
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }
    cout << "The longest subsequence: ";
    for(int j = 1; j<= m; j++)
    {
        if(res[n][j] != res[n][j - 1])
        {
            cout << x[j - 1];
        }
    }

    return res[n][m];
}

int main(){
    string str1, str2;
    cout << "Enter sequence 1: ";
    cin >> str1;
    
    cout << "Enter sequence 2: ";
    cin >> str2;

    int x = lcs(str1, str2);
    cout << "\nlongest common subsequence: "<< x << endl;
}

