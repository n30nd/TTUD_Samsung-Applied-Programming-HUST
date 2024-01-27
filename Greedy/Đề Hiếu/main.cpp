#include "bits/stdc++.h"
using namespace std;

int k,q,n,m;
int d[100];
int c[100][100];
vector<int> f[100]; // khonng cung hanh  trinh
bool visited[100];
vector<int> x[13]; // luu tuyen duong cua moi xe

int s = 0;



int main(){
    cin >> n >>k >>q;
    for(int i=1;i<=n;i++) cin >> d[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        f[x].push_back(y);
        f[y].push_back(x);
    }


    for(int i=1;i<=n;i++) visited[i] = false;








    return 0;

    }
