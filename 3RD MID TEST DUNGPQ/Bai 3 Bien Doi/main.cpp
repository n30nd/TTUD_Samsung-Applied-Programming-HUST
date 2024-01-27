//Bài 3 BIẾN ĐỔI SỐ (P03)
//Cho một số nguyên dương N được ghi trên bảng. Tại mỗi bước, thực hiện 1 trong 2 phép biển đồi sau:
//Xóa N và thay bởi N + 2 (nếu N <= 10000)
//Xóa N và thay bỏi N – 5 (nếu N >= 5)
//Hãy xác định số ít nhất Q các bước biến đổi cần thực hiện để thu được số 0 ghi trên bảng
//Dữ liệu vào
//Số nguyên dương N (1 <=N<=10000)
//Kết quả
//- Ghi giá trị Q
//Ví dụ
//Dữ liệu
//6
//Kết quả
//4


//#include "bits/stdc++.h"
//using namespace std;
//int n;
//bool visited[20004];
//int p[20004];
//int d[20004];
//void trace(int v){
//    while(p[v+10000] != -1){
//        cout << v << " -> ";
//        v = p[v+10000];
//    }
//}
//
//void bfs(){
//    queue<int> q;
//    q.push(0);
//    d[0+10000] = 0;
//    visited[0+10000] = true;
//    p[0+10000] = -1;
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//
//        vector<int> u_new;
//        u_new.push_back(u-2);
//        u_new.push_back(u+5);
//        for(int v : u_new){
//            if(!visited[v+10000]){
//                visited[v+10000] = true;
//                q.push(v);
//                d[v+10000] = d[u+10000]+1;
//                p[v+10000] = u;
//                if(v == n) {
//                    cout << d[v+10000] <<endl;
//                    trace(v);
//                    return;
//                }
//            }
//        }
//    }
//}
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> n;
//    for(int i=0;i<20002;i++) visited[i] = false;
//
//    bfs();
//    return 0;
//
//
//}

#include "bits/stdc++.h"
using namespace std;
int n;
int d[10002];
bool visited[10002];
int p[10002];
void trace(int v){
    while(p[v] != -1){
        cout << v <<" -> ";
        v = p[v];
    }
}
void bfs(){
    queue<int> q;
    q.push(0);
    visited[0] = true;
    d[0] = 0;
    p[0] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        vector<int> u_new;
        if(u-2 <= 10000 && u-2>=0) u_new.push_back(u-2);
        if(u+5 >= 5) u_new.push_back(u+5);

        for(int v : u_new){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                d[v] = d[u]+1;
                p[v] = u;
                if(v == n){
                    cout << d[v] <<endl;
                    trace(v);
                    return ;
                }
            }
        }
    }
}


int main(){
    cin >> n;
    for(int i=0;i<=10002;i++) visited[i] = false;

    bfs();


    return 0;
}
