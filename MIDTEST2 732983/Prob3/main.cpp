#include "bits/stdc++.h"
const int q = 10e9+7;
using namespace std;
int n,m;
int a[101];
int dp(int k,int m1){
    if(k==0 && m1==0) return 1;
    if(k==0 && m1!=0) return 0;
    int vm = m1/a[k];
    int res = 0;
    for(int v=0;v<=vm;v++){
        res += dp(k-1,m-a[k]*v);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>m;
    for(int i=1;i<=n;i++) cin >> a[i];

    cout <<dp(n,m);

    return 0;
}
