//Cho n điểm 1,2,...,n
//kcach i -> j là d[i][j]
//từ 1 đi qua các đỉnh còn lại mỗi đỉnh đúng 1 lần rồi quay về 1
//tìm hành trình với tổng khoảng cách ngắn nhất
//
//ý tưởng tham lam: từ đỉnh hiện tại, đến đỉnh gần nhất

#include "bits/stdc++.h"

using namespace std;
const int N = 1000;
int d[N][N];
int n;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> d[i][j];
        }
    }
}

int selectMin(set<int>& C, int cur){
    int minD = 1e9;
    int select = -1;
    for(set<int>::iterator it = C.begin(); it != C.end();it++){
        int i = *it;
        if(minD > d[cur][i]){
            minD = d[cur][i];
            select = i;
        }
    }

    return select;
}

void greedy(){
    set<int> C;
    for(int i=2;i<=n;i++) C.insert(i);
    int cur = 1;

    vector<int> S;
    S.push_back(cur);
    int F = 0;
    while(C.size() > 0){
        int x = selectMin(C, cur);
        C.erase(x);
        F += d[cur][x];
        S.push_back(x);
        cur = x;
    }
    F += d[cur][1];

    for(int i=0;i<S.size();i++){
        cout << S[i] << " ";
    }
    cout << endl << "length = " << F <<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    greedy();



    return 0;

}
