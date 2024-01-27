//Problem B. Aggressive cows
//Input File Name: Standard Input
//Output File Name: Standard Output
//Time Limit: 1s
//Memory Limit: 256 MB
//Farmer John has built a new long barn, with N (2 ≤ N ≤ 100, 000) stalls. The stalls are located along
//a straight line at positions x1, . . . , xN (0 ≤ xi ≤ 1, 000, 000, 000).
//His C (2 ≤ C ≤ N) cows don’t like this barn layout and become aggressive towards each other once
//put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls,
//such that the minimum distance between any two of them is as large as possible. What is the largest
//minimum distance?
//Input
//t – the number of test cases, then t test cases follows.
// Line 1: Two space-separated integers: N and C
// Lines 2 . . . N + 1: Line i + 1 contains an integer stall location, xi
//Output
//For each test case output one integer: the largest minimum distance.
//Examples
//Standard Input Standard Output
//1
//5 3
//1
//2
//8
//4
//9
//3
//Explanation
//FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

#include "bits/stdc++.h"
using namespace std;
int n,c ;
int x[1000];
bool check(int d){
    int t = 1;
    int dem = 1;
    for(int i=2;i<=n;i++){
        if(x[i]-x[t] >= d){
            t = i;
            dem++;
        }
    }
    return dem >= c;
}
int solve(int lo,int hi){
    int res = lo;
    while(lo <= hi){
        int m = (lo+hi)/2;
        if(check(m)){
            res = m;
            lo = m+1;
        }
        else {
            hi = m-1;
        }
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i=1;i<=n;i++) cin >> x[i];

    sort(x+1,x+n+1);
    int lo=0;
    int hi = x[n]-x[1];

    cout << solve(lo, hi);

    return 0;
}
