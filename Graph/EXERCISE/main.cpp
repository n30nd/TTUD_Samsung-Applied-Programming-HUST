#include "bits/stdc++.h"
using namespace std;


int n,m;
vector<int> a[10001];
int d[10001]; //d[v] is level of v

int bfs(int u){
    queue<int> q;
    q.push(u);
    d[u] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int x : a[v]){
            if(d[x] > -1){
                if(d[x]%2 == d[v]%2) return 0;
            }
            else {
                d[x] = d[v]+1;
                q.push(x);
            }
        }
    }
    return 1;
}

int main(){
        cin >> n >>m;
        while(m--){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        //init
        for(int i=1;i<=n;i++) d[i] = -1;

        int ans = 1;

        for(int v=1;v<=n;v++){
            if(d[v] == -1){
                if(!bfs(v)){
                    ans = 0;
                    break;
                }
            }
        }
        cout << ans;
        return 0;
}
