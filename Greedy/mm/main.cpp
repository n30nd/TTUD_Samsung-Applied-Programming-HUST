#include <bits/stdc++.h>

using namespace std;


const int INF = 1e9;
int n,k,q;
int d[1000];
int c[1000][1000];
vector<int> p[100];
int load[100];
vector<int> xdot[100];
int s[100]; // tong quang duong di cua cac xe


int selectXe(){
    int maxS = INT_MIN;
    int select = -1;
    for(int i = 1;i<= k;i++){
        if(maxS < s[i]){
            select = i;
        }
    }

    return select;
}

int selectClient(set<int>& C, int i){
    int select = -1;
    int minS = INT_MAX;

    int last = p[i][p[i].size()-1] ;

    for(auto it = C.begin(); it != C.end(); it++){
        int j = *it;

        if(load[i] + d[j] <= q){
            if(minS > c[last][j] ){
                minS = c[last][j];
                select = j;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >>k >>q;
    for(int i=1;i<=n;i++) cin >> d[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
        }
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        xdot[x].push_back(y);
        xdot[y].push_back(x);
    }


    return 0;
}
