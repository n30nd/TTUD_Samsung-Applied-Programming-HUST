//Problem: Count solution to integer - linear equation - DP
//Description
//Given 2 positive integers n and M and n positive integers a
//1
//, a
//2
//, . . ., a
//n
//. Compute the number Q of non-negative solutions to the following equation:
//a
//1
//x
//1
// + a
//2
//x
//2
// + . . . + a
//n
//x
//n
// = M
//
//Input
//Line 1: contains n and M (1 <= n <= 100, 1 <= M <= 10000)
//Line 2: contains a
//1
//, a
//2
//, . . ., a
//n
// (1 <= a
//i
// <= 10)
//
//Output
//Write Q mod 109+7
//
//Example
//Input
//3 4
//2 3 2
//
//Output
//3
//
//Explanation: there are 3 solutions:
//2*0 + 3*0 + 2*2 = 4
//2*1 + 3*0 + 2*1 = 4
//2*2 + 3*0 + 2*0 = 4

#include "bits/stdc++.h"
using namespace std;

#define MAXM 10001
#define MAXN 101

int n,m;
int a[MAXN];
int s[MAXN][MAXM];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n>>m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            s[i][j] = 0;
        }
    }
    for(int j=0;j<=m;j++){
        if(j%a[1] == 0) s[1][j] = 1;
        else s[1][j] = 0;
    }


    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            int x = 0;
            while(j-a[i]*x >= 0) {
                s[i][j] += s[i-1][j-a[i]*x];
                x++;
            }
        }
    }

    cout << s[n][m];
    return 0;
}
