#include "bits/stdc++.h"
using namespace std;
int n,m;
vector<int> adj[1000001];
bool visited[1000001];
int cnt = 0;

void dfs(int u){
    for(int v : adj[u]){
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


    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[u].push(v);
        adj[v].push(u);
    }

    for(int i=1;i<=n;i++) visited[i] = false;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            visited[i] = true;
            dfs(i);
        }
    }

    cout << cnt;



    return 0;
}
