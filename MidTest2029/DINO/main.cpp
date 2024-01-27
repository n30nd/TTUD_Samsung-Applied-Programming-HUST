//Bài 2. DINO
//Khủng long kỳ thực không hề hung dữ như người ta vẫn tưởng, chúng rất thông minh và dễ bảo. Bạn là người
//trông giữ khủng long và có nhiệm vụ sắp xếp lại khủng long trong chuồng. Chuồng chỉ có một cửa ra vào, và chiều
//ngang hẹp chỉ vừa đủ cho một con khủng long di chuyển, vì thế con nào vào chuồng trước thì sẽ phải ra sau. Ở
//cạnh chuồng có một hành lang. Hành lang có một cửa vào và một cửa ra, và chiều ngang cũng vừa đủ cho một con
//khủng long di chuyển, nên con nào vào trước sẽ phải ra trước.
//Có n con khủng long, tất cả đều đang ở trong chuồng. Con khủng long thứ i (tính từ cửa chuồng vào trong) có số
//hiệu pi (p1, p2, . . . , pn là một hoán vị của {1, 2, . . . , n}). Để sắp xếp lại các con khủng long, bạn sẽ sử dụng đèn
//báo hiệu được lắp ở chuồng và hành lang. Khi bật đèn báo hiệu ở chuồng, nếu trong chuồng có khủng long thì một
//con khủng long trong chuồng sẽ đi sang hành lang. Khi bật đèn báo hiệu ở hành lang, nếu ở hành lang có khủng
//long thì một con khủng long ở hành lang sẽ đi vào chuồng. Rõ ràng là có thể sắp xếp lại khủng long chỉ sử dụng
//các thao tác bật đèn như trên. Tuy nhiên vì mải ngắm nhìn con khủng long yêu thích mà bạn đã quên mất công
//việc của mình. Lúc về nhà, bạn nhớ lại thứ tự ban đầu của các con khủng long và thứ tự bật đèn của mình. Bạn
//tự hỏi, sau những thao tác đó thì thứ tự hiện tại của các con khủng long trong chuồng sẽ như thế nào?
//Dữ liệu vào
//• Dòng đầu chứa số nguyên dương n (1 ≤ n ≤ 105
//)
//• Dòng tiếp theo chứa n số nguyên dương p1 p2 . . . pn
//• Dòng tiếp theo chứa một xâu s (1 ≤ |S| ≤ 106
//) gồm nhiều ký tự viết liền nhau, các ký tự C cho biết bạn
//bật đèn ở chuồng, các ký tự H cho biết bạn bật đèn ở hành lang. Lưu ý các đèn là đèn báo hiệu và sẽ tắt
//ngay sau khi được bật sáng. Các đèn được bật theo đúng trình tự trong xâu s
//Kết quả
//Ghi ra số hiệu của các con khủng long trong chuồng theo thứ tự từ cửa chuồng vào trong. Dữ liệu đảm bảo sau
//khi kết thúc, tất cả khủng long đều ở trong chuồng.
//Ví dụ
//test answer
//4
//3 1 4 2
//CCHCCHHH
//4 3 1 2
//Hạn chế
//Có 25% test với |s| = 2n, si = C ∀i ≤ n, si = H ∀i > n
#include "bits/stdc++.h"
using namespace std;

int n;
int a[100000];
string s;
stack<int> st;
queue<int> q;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

cin >> n;
for(int i=1;i<=n;i++){
    cin >> a[i];
}
cin >> s;
for(int i =n;i>=1;i--) st.push(a[i]);
int t;
for(char c : s){
    if(c == 'C'){
        t = st.top();
        st.pop();
        q.push(t);
    }
    else {
        t = q.front();
        q.pop();
        st.push(t);
    }
}

while(!st.empty()){
    cout << st.top() <<" ";
    st.pop();
}
return 0;
}
