//An engineer needs to schedule a machine to run on some given periods 1, . . . , n to produce a chemical
//product C. Each period i is represented by a starting time point si and terminating time point ti (si < ti).
//You can assume that there is no two periods with the same terminate point. Due to a technical constraint,
//the machine must run on exactly two periods that are not overlap (two periods i and j are not overlap
//if ti < sj or tj < si). If the machine is runned on the period i, then the amount of C it will produce is
//equal to the duration of the period i (which is equal to ti − si). Help the engineer to select k (k ≤ 3)
//not-overlap periods to run the machine such that the amount of C produced is maximal.
//Input
//The input consists the following lines:
//• Line 1: contains two positive integers n and k (2 ≤ n ≤ 106
//, k ≤ 3);
//• Line i + 1: contains two positive integers si and ti (1 ≤ si < ti ≤ 3 × 106
//).
//Result
//The output consists of only one single integer which is the amount of product C the machine will produce
//in the k selected periods. In case there is no solution (there does not exist two periods that are not
//overlap), the output contains the value -1.

#include "bits/stdc++.h"
using namespace std;
int n,k;
int s[1000001];
int t[1000001];

int greedy1(){


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> s[i] >>t[i];
    }













    return 0;
}
