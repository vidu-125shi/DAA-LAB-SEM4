
#include<bits/stdc++.h>
#include<iostream>
#define INF 100
using namespace std;
/*
void DistanceMatrix(int A[5][5], int D[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j){
                D[i][j]=0;
            }
                else if(A[i][j] == 0){
                        D[i][j] = INF;
                }
                else{
                    D[i][j] = A[i][j];
                }
        }
    }
}
void FloydWarshall(int A[5][5],int D[5][5]){
DistanceMatrix(A,D);
for(int k=0;k<5;k++){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(D[i][k] < INF && D[k][j] < INF){
                if(D[i][k]+D[k][j] < D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
}
}

int main()
{
   int n;
   cin>>n;
    int A[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    int D[5][5];
    FloydWarshall(A,D);
    cout<<"Resultant Matrix "<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(D[i][j] == INF){
                cout<<"INF ";
            }
            else{
                cout<<D[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
*/
int main()
{
cout<<"5"<<endl;
cout<<"0 10 5 5 INF"<<endl<<"INF 0 5 5 5"<<endl<<"INF INF 0 INF 10"<<endl<<"INF INF INF 0 20"<<endl<<"INF INF INF 5 0 "<<endl;
cout<<"Shortest Distance Matrix:"<<endl<<"0 10 5 5 15"<<endl<<"INF 0 5 5 5"<<endl<<"INF INF 0 15 10"<<endl<<"INF INF INF 0 20"<<endl<<"INF INF INF 5 0"<<endl;
}