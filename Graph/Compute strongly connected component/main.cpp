#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6+1;
int n,m;

vector<int> a[MAXN];
vector<int> a1[MAXN];

bool visited[MAXN];
int ncc;
int x[MAXN];
int idx;

void buildResidualGraph(){
    for(int u=1;u<=n;u++){
        for(int v : a[u]){
            a1[v].push_back(u);
        }
    }
}

void init(){
    for(int v=1;v<=n;v++) visited[v] = false;
}

void dfsa(int s){
    for(int v : a[s]){
        if(!visited[v]){
            visited[v] = true;
            dfsa(v);
        }
    }
    idx++;
    x[idx] = s;
}

void dfsa(){
    init();
    idx = 0;
    for(int v=1;v<=n;v++){
        if(!visited[v]){
            visited[v] = true;
            dfsa(v);
        }
    }
}

void dfsa1(int s){
    for(int v : a1[s]){
        if(!visited[v]){
            visited[v] = true;
            dfsa1(v);
        }
    }
}

void dfsa1(){
    init();
    ncc = 0;
    for(int i=n;i>=1;i--){
        int v = x[i];
        if(!visited[v]){
            visited[v] = true;
            ncc++;
            dfsa1(v);
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }


    dfsa();
    buildResidualGraph();
    dfsa1();

    cout << ncc;



    return 0;
}
