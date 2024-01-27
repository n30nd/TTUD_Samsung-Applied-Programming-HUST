//Sự miêu tả
//Có M kệ trong kho lớn 1, 2, . . ., M trong đó kệ j đặt tại điểm j của kho (j = 1, ..., M).
//Có N sản phẩm 1, 2, . . ., N. Số lượng sản phẩm i trong kệ j là Q[i][j].
//Nhân viên kho xuất phát từ cửa (điểm 0) của kho, muốn tham quan một số kệ hàng
//(mỗi kệ chỉ được ghé thăm tối đa một lần) và quay lại cửa lấy sản phẩm cho
//đơn hàng của khách hàng trong đó tổng số lượng sản phẩm i anh ta phải lấy là q[i] (i = 1, 2, . . ., N).
//Khoảng cách di chuyển từ điểm i đến điểm j là d(i,j) (0 <= i,j <= M).
//Tìm thứ tự các kệ cần ghé thăm sao cho tổng khoảng cách di chuyển là nhỏ nhất.
//
//Đầu vào
//Dòng 1: hai số nguyên dương N và M (1 <= N <= 50, 1 <= M <= 1000)
//Dòng 1 + i (i = 1, ..., N): chứa dòng thứ i của Q
//Dòng N + i + 2 (i = 0, 1, ..., M): chứa dòng thứ i của ma trận khoảng cách d
//Dòng N + M + 3: chứa q[1], q[2], . . ., q[N]
//
//Một nghiệm được biểu diễn bằng dãy n số nguyên dương x1, x2, . . ., xn thể hiện trình tự các kệ sẽ được ghé thăm
//
//đầu ra
//Dòng 1: chứa số nguyên dương n
//Dòng 2: chứa n số nguyên dương x1, x2, . . ., xn
//
//Ví dụ
//Đầu vào
//6 5
//3 2 2 4 2
//4 3 7 3 5
//6 7 2 5 4
//2 3 3 2 1
//2 5 7 6 1
//7 2 1 6 5
//0 16 10 13 13 19
//16 0 8 3 19 5
//10 8 0 7 23 11
//13 3 7 0 16 6
//13 19 23 16 0 22
//19 5 11 6 22 0
//8 7 4 8 11 13
//
//đầu ra
//4
//2 3 1 5
//
//Giải thích : lộ trình của nhân viên kho là: 0 - 2 - 3 - 1 - 5 - 0
//Tham lam: chọn kệ tiếp theo sẽ có trung bình giá trị / khoảng cách với thằng trc lớn nhất

#include "bits/stdc++.h"
using namespace std;
int m,n;
int Q[51][1001];
int q[51];
int curr[51];
int d[1001][1001];
int x[1001]; // ds kệ
bool visited[1001];

void input(){
    cin >> n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> Q[i][j];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++) cin >> d[i][j];
    }

    for(int i=1;i<=n;i++) cin >>q[i];
}


void init(){
    x[0] = 0;
    for(int i=1;i<=n;i++){
        visited[i] = false;
        curr[i] = 0;
    }
}

// chon nha cho buoc k
int selectHouse(int k){
    int select = -1;
    float smax = 0;

    for(int j=1;j<=m;j++){
        if(!visited[j]){
            float ds = 1.0*d[x[k-1]][j];
            float scurr = 0;
            for(int i=1;i<=n;i++){
                scurr += Q[i][j]>q[i]? q[i] : Q[i][j];
            }
            scurr = scurr/ds;

            if(scurr > smax){
                smax = scurr;
                select = j;
            }
        }
    }

    return select;
}


int selectHouse2(int k){
    int select = -1;
    float smax = 0;

    for(int j=1;j<=m;j++){
        if(!visited[j]){
            float ds = 1.0*d[x[k-1]][j];
            float scurr = 0;
            for(int i=1;i<=n;i++){
                scurr += Q[i][j];
            }
            scurr = scurr/ds;

            if(scurr > smax){
                smax = scurr;
                select = j;
            }
        }
    }

    return select;
}


bool check(){
    for(int i=1;i<=n;i++) if(q[i] > 0) return false;
    return true;
}

bool check2(){
    for(int i=1;i<=n;i++) if(curr[i] < q[i]) return false;
    return true;
}

void greedy(){
    init();
    for(int k=1;k<=n;k++){
        int sel_x = selectHouse2(k);
        visited[sel_x] = true;
        x[k] = sel_x;
        for(int i=1;i<=n;i++){
            q[i] = Q[i][sel_x] > q[i] ? 0 : q[i] - Q[i][sel_x];
        }
        if(check()){
            cout << k <<endl;
            for(int i=1;i<=k;i++) cout << x[i] <<" ";

            int sout = 0;
            for(int i=1;i<=k;i++) sout += d[x[i-1]][x[i]];
            cout << endl <<sout <<endl;
            break;
        }
    }
}

void greedy2(){
    init();
    for(int k=1;k<=n;k++){
        int sel_x = selectHouse2(k);
        visited[sel_x] = true;
        x[k] = sel_x;
        for(int i=1;i<=n;i++){
            curr[i] += Q[i][sel_x];
        }
        if(check2()){
            cout << k <<endl;
            for(int i=1;i<=k;i++) cout << x[i] <<" ";

            int sout = 0;
            for(int i=1;i<=k;i++) sout += d[x[i-1]][x[i]];
            cout << endl <<sout <<endl;
            break;
        }
    }
}





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    init();
    //greedy();
    greedy2();

    return 0;
}
