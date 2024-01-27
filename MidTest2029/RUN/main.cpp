//Huyền đang có một dãy số nguyên a = a1, a2, . . . , an. Cô muốn cắt a thành các đoạn con gồm các phần tử liên
//tiếp của a, sao cho mỗi đoạn đều là một dãy tăng. Hãy giúp Huyền tính xem cô phải cắt a thành ít nhất bao nhiêu
//đoạn để thỏa mãn tính chất trên.
//Dữ liệu vào
//• Dòng đầu chứa số nguyên dương n (1 ≤ n ≤ 105
//)
//• Dòng tiếp theo chứa n số nguyên dương a1 a2 . . . an (0 ≤ ai ≤ 109
//)
//Kết quả
//Ghi một số nguyên duy nhất là số ít nhất các đoạn con tăng của a.
//Ví dụ
//test answer
//6
//3 6 1 7 8 2
//3
//Giải thích
//Dãy a được cắt thành (3,6), (1,7,8), (2)
#include "bits/stdc++.h"
using namespace std;
int n;
int a[100000];
int solve(){
int dem = 1;
int t = a[1];
for(int i=2;i<=n;i++){
    if(a[i] > t){
        t = a[i];
        continue;
    }
    else {
        t = a[i];
        dem++;
    }
}
return dem;

}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

cin >> n;
for(int i=1;i<=n;i++) cin >> a[i];

cout << solve();

return 0;
}
