//Bài toán lộ trình vận tải
//Công ty phân phối sữa cần xếp chuyến cho K xe tải 1,2,...,K
//để giao hàng cho N khách hàng 1,2,...,N từ kho trung tâm (điểm 0).
//Khách hàng i ở điểm i và yêu cầu một lượng hàng là d[i], i= 1..N
//biết c[i][j] là khoảng cách từ điểm i đến điểm j (i,j = 0,1,...,N).
//Xe k có tải trọng là Q với k=1,2...,K
//Lập lộ tình giao hàng cho K xe sao cho
//- Mỗi xe xuất phát từ điểm 0, đi đến các khách hàng và quay về điểm 0
//- Mỗi khách hàng được giao hàng bởi đúng 1 xe
//- Tổng lượng hàng giao cho các khách hàng bởi 1 xe không vượt quá tải trọng của xe đó
//- Tổng hành trình nhỏ nhất
//


//- Tham lam: Tại mỗi bước chọn cặp xe k, khách i sao cho khi thêm i
//vào cuối hành trình của xe k thì khoảng đường tăng thêm là ít nhất

#include <bits/stdc++.h>
using namespace std;
int K,Q,n;
int d[100];
int c[100][100];
vector<int> F[100]; // 2 điểm không chung 1 hành trình của 1 xe
vector<int> P[100];
int load[100];
int m;
int sum = 0;

void input(){
    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) cin >> c[i][j];
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        F[x].push_back(y);
        F[y].push_back(x);
    }

}

bool checkB(int i, int k){
    if(load[k] < d[i]) return false;
    for(int j : F[i]){
        for(int c : P[k]){
            if(j == c) return false;
        }
    }

//    cout << " check ok i= " << i<<", k= "<<k<<endl;
    return true;
}
pair<int,int> selectTruckClient(set<int>& C){
    int sel_i = -1;
    int sel_k = -1;
    int smin = INT_MAX;

    for(int k=1;k<=K;k++){
        for(set<int>::iterator it = C.begin(); it != C.end(); it++){
            int i = *it;
            int last = P[k][P[k].size()-1];
            if(checkB(i,k)){
                 if(smin > c[last][i]){
                    smin = c[last][i];
                    sel_i = i;
                    sel_k = k;
                }
            }
        }

    }

    return {sel_k, sel_i};
}



void init(){
    for(int k=1;k<=K;k++){
        P[k].clear();
        P[k].push_back(0);
        load[k] = Q;
    }
    sum = 0;
}
void greedy(){
    input();
    init();
    set<int> C;
    for(int i=1;i<=n;i++) C.insert(i);

    while(C.size()>0){
        pair<int,int> p = selectTruckClient(C);
        int k = p.first;
        int x = p.second;
        C.erase(x);
        if(k == -1) break;

        int last = P[k][P[k].size()-1];
        P[k].push_back(x);
        load[k] -= d[x];
        sum += c[last][x];

    }

    for(int k=1;k<=K;k++){
        int last = P[k][P[k].size()-1];
        sum += c[last][0];
        P[k].push_back(0);
    }

    cout << "sum = " << sum <<endl;
    for(int k=1;k<=K;k++){
        cout << "k= "<<k <<" : ";
        for(int i=0;i<P[k].size();i++){
            cout << P[k][i] <<" ";
        }
        cout << endl;
        cout << "load_" <<k<<" = "<<load[k]<<endl;
    }
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    greedy();


    return 0;
}
