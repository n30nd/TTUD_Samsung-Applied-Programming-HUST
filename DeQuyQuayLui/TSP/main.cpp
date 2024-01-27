#include"bits/stdc++.h"
using namespace std;
#define MAX 20

int a[MAX];
bool visited[MAX];
int c[MAX][MAX];
int x[MAX];
int cmin=INT_MAX;
int f_min = INT_MAX;
int g; // can duoi
int n;//so thanh pho
int f0=0;
void TRY(int k){
    for(int v=1;v<=n;v++){
        if(!visited[v]){
            f0 += c[x[k-1]][v];
            g = f0 + cmin*(n-k+1);
            visited[v] = true;
            x[k] = v;
            if(k == n){
                f_min = min(f_min, f0+c[v][1]);
            }
            else if(g < f_min) TRY(k+1);
            f0 -= c[x[k-1]][v];
            visited[v] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
                cin >> c[i][j];
                cmin = min(cmin, c[i][j]);
        }
    }
    x[1] = 1;
    visited[1] = true;
    for(int i=2;i<=n;i++) visited[i] = false;
    TRY(2);
    cout << f_min;
    cout << endl;
    for(int i=1;i<=n;i++) cout << x[i] << " ";


return 0;}
