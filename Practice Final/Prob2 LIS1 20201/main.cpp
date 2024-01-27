//Bài B. LIS1
//Cho dãy số nguyên a. Dãy con của a là dãy thu được bằng cách xóa đi một số phần tử của a (có thể không xóa
//phần tử nào, cũng có thể xóa hết tất cả). Một dãy con được gọi là đẹp nếu phần tử đứng sau lớn hơn phần tử
//đứng trước đúng một đơn vị.
//Yêu cầu: Hãy tìm dãy con đẹp dài nhất của dãy a.
//Dữ liệu vào
//Dòng đầu chứa một số nguyên là số testcase: T (0 ≤ T ≤ 10). Tiếp theo, mỗi testcase được cho trên 2 dòng như
//sau:
//Trang 1 trên 4
//Đề thi CUỐI KỲ môn THUẬT TOÁN ỨNG DỤNG kỳ 20201
//16/01/2021, Chỉ được phép truy cập vào trang nộp bài 202.191.56.251:18888/TTUD20201
//• Dòng đầu chứa số phần tử của dãy a: n
//• Dòng tiếp theo chứa dãy a
//Kết quả
//Ghi ra T dòng, mỗi dòng một số nguyên duy nhất là độ dài của dãy con đẹp dài nhất tìm được tương ứng với
//testcase trong input.
//Ví dụ
//test answer
//1
//6
//3 1 2 4 3 5
//3
//Giải thích
//Dãy con đẹp dài nhất là: 3 4 5. Một dãy con khác cũng đẹp và dài nhất là: 1 2 3
//Hạn chế
//• Trong tất cả các test: n ≤ 105
//, 1 ≤ ai ≤ 109
//• 25% test với n ≤ 20
//• 25% test tiếp theo với n ≤ 1000
//• 25% test tiếp theo với 1 ≤ ai ≤ 106
//• 25% test còn lại không có ràng buộc gì thêm

#include "bits/stdc++.h"
using namespace std;
int t;
int a[100001];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        int dp[n+1];
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int tmp = 1;
            for(int k=1;k<i;k++){
                if(a[i] == a[k]+1){
                    tmp = max(tmp, dp[k]+1);
                }
            }
            dp[i] = tmp;
        }
        cout << dp[n] <<endl;
    }








    return 0;

}
