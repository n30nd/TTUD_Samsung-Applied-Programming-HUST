#include "bits/stdc++.h"
using namespace std;
int curr;
int a[31];
int n,k,s;
int kcurr;
int scurr;
int cnt = 0;
void TRY(int i){
    if(i>n){
        if(scurr == s && kcurr == k){
            cnt++;
        }
        return ;
    }

    TRY(i+1);

    scurr += a[i];
    kcurr++;
    TRY(i+1);
    scurr -= a[i];
    kcurr--;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >>s;
    for(int i=1;i<=n;i++) cin >> a[i];

    //init
    kcurr = 0;
    scurr = 0;
    TRY(1);
    cout << cnt ;










    return 0;

}
