#include "bits/stdc++.h"
using namespace std;
const int MAXN = 13;
const int MAXK = 6;
int K,Q,n;
int d[MAXN];
int c[MAXN][MAXN];
vector<int> P[MAXK];
bool visited[MAXN];
vector<int> F[MAXN];
int load[MAXK];
int S = 0;

bool check(int i,int k){
    if(visited[i] || load[k] < d[i]) return false;
    for(int v : F[i]){
        for(int v1 : P[k]){
            if(v == v1) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) cin >>c[i][j];

    int m;
    cin >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        F[u].push_back(v);
        F[v].push_back(u);
    }

    //init
    for(int k=1;k<=K;k++){
        P[k].clear();
        P[k].push_back(0);
        load[k] = Q;
    }
    S = 0;

    for(int i=1;i<=n+1;i++) visited[i] = false;

    for(int turn =1;turn <= n+1;turn ++){
        int sel_i = -1;
        int sel_k = -1;
        int smin = INT_MAX;

        for(int i=1;i<=n;i++){
            for(int k=1;k<=K;k++){
                if(check(i,k)){
                    int last = P[k].back();
                    if(c[last][i] < smin){
                        smin = c[last][i];
                        sel_i = i;
                        sel_k = k;
                    }
                }
            }
        }

        if(sel_i != -1){
            visited[sel_i] = true;
            P[sel_k].push_back(sel_i);
            load[sel_k] -= d[sel_i];
            S += smin;
        }


        cout << endl << "turn " <<turn<<" : sel_i,sel_k = " <<sel_i <<" , "<<sel_k <<endl;
        cout << "S = " << S <<endl;
        for(int k=1;k<=K ;k++){
            cout << "k= "<<k<<" :";
            for(int v : P[k]) cout << v <<" -> ";
            cout << endl;
        }

    }

    for(int k=1;k<=K;k++){
        cout << "load_"<<k<< "= "<<load[k] <<endl;
    }
    for(int k=1;k<=K;k++){
        S += c[P[k].back()][0];
        P[k].push_back(0);
    }
    cout << S <<endl;
    for(int k=1;k<=K ;k++){
        cout << "k= "<<k<<" :";
        for(int v : P[k]) cout << v <<" -> ";
        cout << endl;
    }
    return 0;
}
