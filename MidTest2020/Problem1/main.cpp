//Bai 1: cho day a1,a2,...,an
//dem so day con co tong bang m, do dai k
//input n,k,m,  a_i
//output so day con co tong bang m do dai k
#include "bits/stdc++.h"
using namespace std;
int n = 7, m= 6, k= 3;
int a[7] = {1,3,2,4,3,1,2};
int solve(){
    int dem = 0;
    int s = 0;
    for(int i=0;i<k;i++){
        s += a[i];
    }

    if(s == m) dem++;
    for(int i=k;i<n;i++){
        s = s - a[i-k]+a[i];
        if(s == m) dem++;
    }
    return dem;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solve();

    return 0;
}

