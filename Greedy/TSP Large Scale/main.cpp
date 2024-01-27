//Vấn đề: TSP - Quy mô lớn
//Sự miêu tả
//Có n thành phố 1, 2, ..., n. Quãng đường đi từ thành phố i đến thành phố j là c(i,j), với i,j = 1, 2, ..., n. Một người muốn tìm một chuyến du lịch khép kín ghé thăm mỗi thành phố đúng một lần (trừ thành phố xuất phát). Tìm hành trình của người đó sao cho tổng quãng đường đi được là nhỏ nhất.
//Một giải pháp được biểu diễn bằng dãy x
//1
//, x
//2
//, . . ., x
//N
//  (một hoán vị của 1, 2, . . ., n) trong đó chuyến đi khép kín là: x
//1
//-> x
//2
//-> x
//3
//-> . . . -> x
//N
//-> x
//1
//.
//Đầu vào
//Dòng 1: số nguyên dương n (1 <= n <= 1000)
//Dòng i+1 (i = 1, . . ., n): chứa dòng thứ i của ma trận khoảng cách x (các phần tử cách nhau bằng ký tự SPACE)
//đầu ra
//Dòng 1: viết n
//Dòng 2: viết dãy điểm x
//1
//, x
//2
//, . . ., x
//N
//(hoán vị 1, 2, . . ., n) của hành trình được tìm thấy.
//Ví dụ
//Đầu vào
//4
//0 1 1 9
//1 0 9 3
//1 9 0 2
//9 3 2 0
//đầu ra
//4
//1 3 2 4
#include "bits/stdc++.h"
using namespace std;

int n;
int c[1001][1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >>c[i][j];

    int s = INT_MAX;
    vector<int> x(n+1);

    vector<int> x_res(n+1);
    for(int st=1;st<=n;st++){
        x[1] = st;
        int stmp = 0;
        vector<bool> visited((n+1), false);
        visited[st] = true;
        for(int k=2;k<=n;k++){
            int tmp = INT_MAX;
            int sel = -1;

            for(int i=1;i<=n;i++){
                if(!visited[i]){
                    if(c[x[k-1]][i] < tmp) {
                        tmp = c[x[k-1]][i];
                        sel = i;
                    }
                }
            }
            x[k] = sel;
            visited[sel] = true;
            stmp += tmp;
        }
        if(stmp < s) {
            s = stmp;
            for(int i=1;i<=n;i++) x_res[i] = x[i];
        }
    }

    cout << n <<endl;
    for(int i=1;i<=n;i++) cout << x_res[i] <<" ";
    return 0;
}
