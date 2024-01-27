//Problem: Count solutions to an integer linear equation
//Description
//Given a positive integer n and n positive integers a
//1
//, a
//2
//, ..., a
//n
//. Compute the number of positive integer solutions to the equation:
//                          a
//1
//X
//1
// + a
//2
//X
//2
// + . . . + a
//n
//X
//n
// = M
//
//Input
//Dòng 1: n và M
//Dòng 2: a
//1
//, a
//2
//, ..., a
//n
//Output
//   Số nghiệm nguyên dương
//Ví dụ
//Input
//3 5
//1 1 1
//Output
//6
#include"bits/stdc++.h"
using namespace std;
    int a[100];
    int n;
    int m;
    int mem[100][100];
    int dp(int k,int m){
        if(mem[k][m] != -1) return mem[k][m];
        if(k==0 && m!= 0) return 0;
        int vm = m/a[k];
        int res = 0;
        for(int v=1;v<=vm;v++){
            res += dp(k-1,m-a[k]*v);
        }
        mem[k][m] =res;
        return res;
    }


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(mem, -1, sizeof(mem));
    mem[0][0] = 1;

    cin >> n >> m;

    for(int i=1;i<=n;i++) cin >> a[i];

    cout << dp(n,m);


    return 0;
    }
