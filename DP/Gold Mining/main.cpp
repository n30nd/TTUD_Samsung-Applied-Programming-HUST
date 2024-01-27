//Problem: Gold Mining
//Description
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
#include"bits/stdc++.h"

using namespace std;

int goldMining(int a[], int n, int l1, int l2){
    vector<int> s(n, 0);
    int maxS = INT_MIN;

    for(int i=0;i<l2;i++){
        int ans = INT_MIN;
        for(int k=i-l2;k<=i-l1;k++){
            if(k>=0) ans = max(ans, s[k]);
        }
        s[i] = max(a[i], a[i]+ans);
        maxS = max(maxS, s[i]);
    }

    for(int i=l2;i<n;i++){
        int ans = INT_MIN;
        for(int k=i-l2;k<=i-l1;k++){
            ans = max(ans, s[k]);
        }
        s[i] = max(a[i], a[i]+ans);
        maxS = max(maxS, s[i]);
    }

    return maxS;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,l1,l2;
    cin >> n >> l1 >> l2;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << goldMining(a, n, l1, l2);

    return 0;
}
