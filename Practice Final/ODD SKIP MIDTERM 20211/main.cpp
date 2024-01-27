#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long l,r;
    cin >> l >>r;

    if(l%2 == 1) l++;
    if(r%2==1) r--;
    cout << (r-l)/2 +1 ;










    return 0;

}

