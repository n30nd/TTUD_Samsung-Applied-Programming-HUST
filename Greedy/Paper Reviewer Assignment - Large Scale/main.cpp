//Vấn đề: Bài tập của người phản biện giấy - Quy mô lớn
//Sự miêu tả
//Người chủ trì hội nghị phải phân công bài báo khoa học cho người phản biện một cách cân bằng. Có N bài báo 1, 2, …, N và M người phản biện 1, 2, …, M. Mỗi bài báo i có một danh sách L(i) những người phản biện sẵn sàng phản biện bài báo đó. Một kế hoạch xem xét là một nhiệm vụ đánh giá các bài báo. Khối lượng của người phản biện là số lượng bài viết mà người đó phải xem xét. Cho hằng số b, hãy tính phép gán sao cho:
//Mỗi bài viết được xem xét bởi chính xác b người đánh giá
//Tải tối đa của tất cả người đánh giá là tối thiểu
//Trong lời giải, mỗi tờ giấy i được biểu diễn bằng một danh sách r(i, 1), r(i, 2), . . ., r(i, b) trong số b người phản biện được giao cho bài viết này
//Đầu vào
//Dòng 1 chứa N, M và b
//Dòng i+1 (i = 1,…,N) chứa số nguyên dương k theo sau là k số nguyên dương biểu thị danh sách L(i)
//đầu ra
//Dòng 1: chứa N
//Dòng i + 1 (i = 1, . . ., N): chứa số nguyên b và b r(i, 1), r(i, 2), . . ., r(i, b) là danh sách người phản hồi được gán cho giấy i
//Ví dụ
//Đầu vào
//5 3 2
//3 1 2 3
//2 1 2
//3 1 2 3
//3 1 2 3
//2 1 3
//đầu ra
//5
//2 1 2
//2 1 2
//2 3 1
//2 3 2
//2 3 1

//#include "bits/stdc++.h"
//using namespace std;
//
//int n,m;
//vector<int> L[1000];
//int b;
//vector<int> R[1000];
//vector<int> R_out[1000];
//int load[1000];
//int load_max;
//
//void input(){
//    cin >> n >>m >> b;
//
//    for(int i=1;i<=n;i++){
//        int k;
//        cin >> k;
//        while(k--) {
//            int j;
//            cin >> j;
//            L[i].push_back(j);
//        }
//    }
//
//}
//
//void init(){
//    for(int i=1;i<=n;i++){
//        R[i].clear();
//        R_out[i].resize(b);
//    }
//    for(int i=1;i<=m;i++) load[i] = 0;
//    load_max = INT_MAX;
//}
//
//bool check(int v, int k){
//    if(R[k].size() == b) return false;
//    for(int i : R[k]) if(i == v) return false;
//    return true;
//}
//void TRY(int k){
//    for(int v : L[k]){
//        if(check(v,k)){
//            R[k].push_back(v);
//            load[v]++;
//            if(k == n && R[k].size() == b){
//                int tmp = INT_MIN;
//                for(int i=1;i<=m;i++) tmp = max(tmp, load[i]);
//
//                if(tmp < load_max){
//                    load_max = tmp;
//                    for(int i=1;i<=n;i++){
//                        for(int j=0;j<R[i].size();j++){
//                            R_out[i][j] = R[i][j];
//                        }
//                    }
//                }
//
//            }
//            else if(R[k].size() != b) TRY(k);
//            else if(k<n && load[k] < load_max) TRY(k+1);
//
//            load[v]--;
//            R[k].pop_back();
//        }
//    }
//}
//
//void solution(){
//    cout << n <<endl;
//    for(int i=1;i<=n;i++){
//        cout << b << " ";
//        for(int j=0;j<R_out[i].size();j++){
//            cout << R_out[i][j] <<" ";
//        }
//        cout << endl;
//    }
//}
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    input();
//    init();
//    TRY(1);
//    solution();
//
//    return 0;
//}

#include "bits/stdc++.h"
using namespace std;
int n,m;
vector<int> L[1000];
int b;
vector<int> R[1000];
int load[1000];



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >>m >> b;

    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        while(k--) {
            int j;
            cin >> j;
            L[i].push_back(j);
        }
    }



    for(int i=1;i<=n;i++){
        R[i].clear();
    }
    for(int i=1;i<=m;i++) load[i] = 0;


    for(int i=1;i<=n;i++){
        vector<bool> visited((m+1), false);
        for(int j=1;j<=b;j++){
            int tmp = INT_MAX;
            int v = -1;
            for(int k : L[i] ){
               if(!visited[k] && load[k] < tmp) {
                    tmp = load[k];
                    v = k;
               }
            }
            visited[v] = true;
            load[v]++;
            R[i].push_back(v);
        }
    }


    cout << n <<endl;
    for(int i=1;i<=n;i++){
        cout << b <<" ";
        for(int c : R[i]) cout << c <<" ";
        cout <<endl;
    }


    return 0;
}

