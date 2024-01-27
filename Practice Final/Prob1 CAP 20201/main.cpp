//Bài A. CAP
//Cho 2 tập số nguyên dương được biểu diễn bởi 2 dãy a = a1, . . . , an và b = b1, . . . , bm. Hãy tìm số phần tử thuộc
//giao của 2 tập hợp đã cho.
//Dữ liệu vào
//Dòng đầu chứa một số nguyên là số testcase: T (0 ≤ T ≤ 10). Tiếp theo, mỗi testcase được cho trên 4 dòng như
//sau:
//• Dòng đầu chứa số nguyên dương: n
//• Dòng tiếp theo chứa dãy a: a1 a2 ... an
//• Dòng tiếp theo chứa số nguyên dương: m
//• Dòng tiếp theo chứa dãy b: b1 b2 ... bm
//Dữ liệu đảm bảo các số trong cùng một dãy thì đôi một khác nhau.
//Kết quả
//Ghi ra T dòng, mỗi dòng là số phần tử của a giao b tương ứng cho từng testcase trong input.
//Ví dụ
//test answer
//1
//4
//2 1 4 3
//3
//1 5 4
//2
//Hạn chế
//• 2 ≤ n ≤ 100, 1 ≤ ai ≤ 109

#include "bits/stdc++.h"
using namespace std;
int t;
int a[101];
int b[101];
bool visited[10000];
int n,m;
int cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        //init
        for(int i=0;i<10000;i++) visited[i] = false;
        cnt = 0;

        for(int i=1;i<=n;i++) {
                cin >> a[i];
                visited[a[i]] = true;
        }

        cin >> m;
        for(int i=1;i<=m;i++) {
                cin >> b[i];
                if(visited[b[i]]) cnt++;
        }

        cout << cnt <<endl;




    }













    return 0;
}
