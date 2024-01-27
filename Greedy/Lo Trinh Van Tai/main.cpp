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
//- Hành trình của xe đi quãng đường dài nhất là nhỏ nhất có thể được
//

//Tham lam 1:
//- Mỗi bước, chọn xe k là xe đang có độ dài hành trình nhỏ nhất
//- Chọn khách hàng i gần với điểm cuối cùng của hành trình xe k nhất
// để phục vụ mà không vi phạm tải trọng
//
// Tham lam 2:
//- Tại mỗi bước, chọn cặp xe k và khách hàng i sao cho khi thêm điểm khách hàng i
//vào cuối hành trình của xe k thì độ dài hành trình xe dài nhất là ít nhất và không
//vi phạm ràng buộc về tải trọng
//

#include "bits/stdc++.h"
using namespace std;
const int N = 1000;
int n,K,Q;
int d[N];
int c[N][N];
vector<int> P[100]; // hành trình của các xe
int F[100]; //tổng độ dài hành trình xe
int load[100]; // tải của mỗi xe


void input(){
    cin >> n >> K >> Q;
    for(int i=1;i<=n;i++) cin >> d[i];

    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++){
        cin >> c[i][j];
    }
}

int selectTruck(){
    int minF = INT_MAX;
    int select = -1;
    for(int k=1; k<= K;k++){
        if(minF > F[k]){
            minF = F[k];
            select = k;
        }
    }

    return select;
}

int selectClient(set<int>& C,int k){
    int select = -1;
    int minF = INT_MAX;
    int last = P[k][P[k].size()-1];

    for(set<int>::iterator it=C.begin(); it!= C.end(); it++){
        int i = *it;
        if(load[k]+d[i] <= Q){
            if(minF > c[last][i]){
                minF = c[last][i];
                select = i;
            }
        }
    }

    return select;
}

pair<int,int> selectTruckClient(set<int>& C){
    int sel_k =-1;int sel_i = -1;int minF = INT_MAX;

    for(int k=1;k<=K;k++){
        for(set<int>::iterator it = C.begin();it != C.end(); it++){
            int i = *it;
            int last = P[k][P[k].size()-1];

            if(load[k] + d[i] > Q) continue;

            int maxL =F[k] + c[last][i];
            for(int j=1;j<=K;j++) if(j != k){
                if(maxL < F[j]) maxL = F[j];
            }

            if(minF > maxL){
                minF = maxL;
                sel_k = k;
                sel_i = i;
            }
        }
    }

    return {sel_k, sel_i};
}

void init(){
    for(int k=1;k <= K; k++){
        F[k] = 0;
        load[k] = 0;
        P[k].clear();
        P[k].push_back(0);
    }
}

void printSolution(){
    for(int k =1;k <= K;k++){
        F[k] += c[P[k].size()-1][0];
        P[k].push_back(0);
    }
    for(int k=1; k<= K;k++){
        cout << "P[" << k <<"]: ";
        for(int i =0;i<P[k].size();i++){
            cout << P[k][i] <<", ";
        }
        cout << " length = " << F[k] <<endl;
    }
}

void greedy1(){
    init();
    cout << "greedy 1..." <<endl;
    set<int> C;
    for(int i=1;i<=n;i++) C.insert(i);
    while(C.size() > 0){
        int k = selectTruck();
        int x = selectClient(C, k);
        if(x == -1) {
            cout << "cannot serve more clients" <<endl;
            break;
        }

        int last = P[k][P[k].size()-1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }
    printSolution();
}

void greedy2(){
    init();
    cout << "greedy2 ..."<<endl;
    set<int> C;
    for(int i=1;i<=n;i++){
        C.insert(i);
    }

    while(C.size() > 0){
        pair<int, int> s = selectTruckClient(C);
        if(s.first == -1){
            cout << "cannot serve more clients" <<endl;
            break;
        }

        int k = s.first;
        int x = s.second;

        int last = P[k][P[k].size()-1];
        load[k] += d[x];
        F[k] += c[last][x];
        P[k].push_back(x);
        C.erase(x);
    }
    printSolution();

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    //greedy1();
    greedy2();


    return 0;
}
