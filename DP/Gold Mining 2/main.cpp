//Sự miêu tả
//The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. The warehouse i has amount of a
//i
// (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.
//Input
//Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
//Line 2 contains n integers a
//1
//,a
//2
//,…,a
//n
//Output
//Contains only one single integer denoting the total amount of golds of selected warehouses.
//Example
//Input
//6 2 3
//3 5 9 6 7 4
//
//Output
//19
#include "bits/stdc++.h"
using namespace std;
int mem[1000001];
int n,l1,l2;
int a[1000001];
int dp(int i){
    if(i<1) return 0;
    if(mem[i] != -1) return mem[i];


    int res = INT_MIN;
    for(int k=l1;k<=l2;k++){
        res = max(res, dp(i-k));
    }
    mem[i] = res + a[i];
//    cout << mem[i] <<"=" <<res<<"+"<<a[i]<<endl;
    return mem[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l1 >> l2;
    for(int i=1;i<=n;i++) cin >> a[i];
    memset(mem, -1, (n+1)*sizeof(int));

    int res = dp(1);
    for(int i=n-l2;i<=n;i++) res = max(res, dp(i));
    cout << res;
    return 0;

    }
