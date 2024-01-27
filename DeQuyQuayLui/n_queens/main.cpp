//Problem: Count number of Queen solutions with some specified queens
//Description
//Given a chess board N x N on which there are K being placed in some cells. Compute the number of solutions to place other N - K queens in other cells such that among N queens on the board, no two queens attack each other.
//A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
//
//Input
//Line 1: contains a positive integer N (1 <= N <= 12)
//Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
//Output
//Write the number of solutions
//
//Example
//Input
//4
//0 1 0 0
//0 0 0 0
//0 0 0 0
//0 0 1 0
//Output
//1
#include "bits/stdc++.h"
using namespace std;
#define MAX 20
int a[MAX][MAX];
bool bCol[2*MAX], bdiag1[2*MAX], bdiag2[2*MAX]; // cot dc dung hay k
int x[MAX];
bool rowExist[MAX]; // hang da ton tai tu trc chua
int n;
int dem = 0;

void TRY(int k){
    if(rowExist[k]){
        if(k==n) dem++;
        else TRY(k+1);
    }
    else {
        for(int v=1;v<=n;v++){
            if(bCol[v] && bdiag1[k+v] && bdiag2[k-v+n]){
                bCol[v] = false;
                bdiag1[k+v] = false;
                bdiag2[k-v+n] = false;
                x[k] = v;
                if(k == n) {
                    dem++;
                }
                else TRY(k+1);

                bCol[v] = true;
                bdiag1[k+v] = true;
                bdiag2[k-v+n] = true;
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=2*MAX;i++){
        bCol[i] = true;
        bdiag1[i] = true;
        bdiag2[i] = true;
    }
    for(int i=1;i<=n;i++){
        rowExist[i] = false;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]==1){
                rowExist[i] = true;
                bCol[j] = false;
                bdiag1[i+j] = false;
                bdiag2[i-j+n] = false;
                x[i] = j;
            }
        }
    }

    TRY(1);
    cout << dem;




return 0;}
