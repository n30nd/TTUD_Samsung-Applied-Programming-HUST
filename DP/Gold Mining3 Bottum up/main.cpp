#include "bits/stdc++.h"
using namespace std;
int n,l1,l2;
int main(){
    cin >> n >> l1 >> l2;
    int a[n+1], f[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    f[1] = a[1];
    for(int i=2;i<=l1;i++){
        f[i] = max(f[i-1], a[i]);
    }
    for(int i=l1+1;i<=n;i++){
        f[i] = max(f[i-1], f[i-l1]+a[i]);
    }
    cout << f[n];
    return 0;
}
