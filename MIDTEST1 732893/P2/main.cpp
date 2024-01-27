#include "bits/stdc++.h"
using namespace std;
int n,m;
int c[17];
int load_max = INT_MAX;
int a[17][17];
int x[17];
int load[6];
bool check(int v, int k){
    for(int i=1;i<=n;i++){
        if(a[i][k] == 1){
            if(x[i]!=-1 && x[i] >= v ) return false;
        }
    }
    for(int j=1;j<=n;j++){
        if(a[k][j] == 1){
            if(x[j]!=-1 && x[j] <= v ) return false;
        }
    }

    return true;
}

void TRY(int k){
    for(int v=1;v<=m;v++){
        if(check(v,k)){
            load[v] += c[k];
            x[k] = v;
            if(k==n){
                int res = 0;
                for(int i=1;i<=m;i++) res = max(res, load[i]);

                load_max = min(load_max, res);
            }
            else if(load[v] < load_max) TRY(k+1);
            load[v] -= c[k];
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> c[i];

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];

    memset(x, -1, sizeof(x));
    TRY(1);
    cout << load_max <<endl;
//    for(int i=1;i<=n;i++) cout << x[i] << " ";


    return 0;

}
