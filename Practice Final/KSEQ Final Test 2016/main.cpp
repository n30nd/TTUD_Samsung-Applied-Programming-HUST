//Bài A. kseq
//Input: stdin
//Output: stdout
//Time limit: 2 giây
//Memory: 512 MB
//Given a sequence of positive integers a = ha1, . . . , ani. A k-sequence of a is defined to be a sub-sequence
//of a containing k consecutive elements: ai
//, ai+1, . . . , ai+k−1. The weight of a k-sequence is defined to be
//the sum of its elements. Given a positive integer k, you are required to write a program that finds a
//k-sequence having maximal weight.
//Input
//The input consists following lines:
//• line 1: contains n and k (5 ≤ n ≤ 1000000, 1 ≤ k ≤ 50000)
//• line 2: contains n positive integers a1, . . . , an (ai ≤ 1000)
//Result
//Write the weight of the k-sequence found.
//Example
//stdin stdout
//6 3
//2 3 20 4 6 5
//30
//Explanation
//The 3-sequence of maximal weight is 20, 4, 6 and its weight is 20 + 4 + 6 = 30

#include "bits/stdc++.h"
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n,k;
    cin >> n >> k;
    int a[n+1], s[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) s[k] += a[i];
    int s_max = s[k];
    for(int i=k+1;i<=n;i++){
        s[i] = s[i-1] - a[i-k] +a[i];
        s_max = max(s_max, s[i]);
    }

    cout << s_max;












    return 0;
}
