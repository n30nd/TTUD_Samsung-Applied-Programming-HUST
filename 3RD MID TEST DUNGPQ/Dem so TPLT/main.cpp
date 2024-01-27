#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6+1;
int n,m;
vector<int> a[MAXN];
bool visited[MAXN];
int dem = 0;

void dfs(int u){
    for(int v : a[u]){
        if(!visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>n >>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    //init
    for(int i=1;i<=n;i++) visited[i] = false;
    dem = 0;

    for(int u=1;u<=n;u++){
        if(!visited[u]){
            dem++;
            visited[u] = true;
            dfs(u);
        }
    }

    cout << dem;

    return 0;
}
