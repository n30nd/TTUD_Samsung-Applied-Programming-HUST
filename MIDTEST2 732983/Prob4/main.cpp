#include "bits/stdc++.h"
using namespace std;
int n;
int c[1001][1001];
int x[1001];
int xbest[1001];
bool visited[1001];
int cmin = INT_MAX;
int f_min = INT_MAX;
int fcurr = 0;
void TRY(int k){
    for(int i=2;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            x[k] = i;
            fcurr += c[x[k-1]][i];
            if(k == n){
                if(fcurr+c[i][1] < f_min){
                    f_min = fcurr + c[i][1];
                    for(int j=1;j<=n;j++){
                        xbest[j] = x[j];
                    }
                }
            }
            else if(fcurr + (n-k+1)*cmin < f_min) TRY(k+1);
            fcurr -= c[x[k-1]][i];
            visited[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    for(int i=1;i<=n;i++) visited[i] = false;

    x[1] = 1;
    visited[1] = true;
    TRY(2);
    cout << f_min <<endl;
    for(int i=1;i<=n;i++) cout << xbest[i] <<" ";
    return 0;
}
