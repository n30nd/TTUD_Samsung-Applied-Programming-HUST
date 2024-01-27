//Bài C. GROUPUP
//Đêm Giao Thừa năm nay có n nhóm người tụ tập đứng dọc đường bờ hồ để xem pháo hoa. Các nhóm được đánh
//số từ 1 đến n theo thứ tự từ đầu đường đến cuối đường, nhóm thứ i có ai người.
//Sắp đến giờ xem pháo hoa, các nhóm này sẽ hợp nhất với nhau để tạo thành một nhóm duy nhất. Quá trình hợp
//nhất nhóm diễn ra như sau:
//• Nếu chỉ còn một nhóm thì dừng quá trình.
//• Ngược lại, hai nhóm kề nhau sẽ hợp lại với nhau: Nhóm 1 hợp lại với nhóm 2, nhóm 3 hợp lại với nhóm 4,
//... Nếu có lẻ nhóm, nhóm sau cùng sẽ không phải làm gì.
//• Đánh số lại các nhóm mới từ đầu đường đến cuối đường, bắt đầu từ 1.
//• Lặp lại bước một.
//Thời gian cần để hai nhóm hợp nhất với nhau bằng tổng số người trong hai nhóm. Mỗi lần hợp nhất, các nhóm sẽ
//thực hiện song song, sau đó chờ các nhóm khác thực hiện xong để tiếp tục lần hợp mới. Do đó thời gian cần cho
//mỗi lần hợp nhất (tức mỗi vòng lặp) sẽ là lượng thời gian lớn nhất trong số các cặp nhóm cần hợp. Cụ thể, thời
//gian mà k nhóm b1, b2, . . . , bk cần để thực hiện một lần hợp nhất là max(b1 + b2, b3 + b4, . . . , bk−1 + bk) nếu k chẵn,
//và max(b1 + b2, b3 + b4, . . . , bk−2 + bk−1) nếu k lẻ.
//Yêu cầu: Hãy tính tổng thời gian hợp nhất của tất cả các nhóm người.
//Dữ liệu vào
//Dòng đầu chứa một số nguyên là số testcase: T (0 ≤ T ≤ 10). Tiếp theo, mỗi testcase được cho trên 2 dòng như
//sau:
//• Dòng đầu chứa số nguyên dương: n
//Trang 2 trên 4
//Đề thi CUỐI KỲ môn THUẬT TOÁN ỨNG DỤNG kỳ 20201
//16/01/2021, Chỉ được phép truy cập vào trang nộp bài 202.191.56.251:18888/TTUD20201
//• Dòng tiếp theo chứa dãy a: a1 a2 ... an
//Kết quả
//Ghi ra T dòng, mỗi dòng là tổng thời gian tìm được tương ứng với testcase trong input.
//Ví dụ
//test answer
//1
//6
//3 1 2 5 4 3
//36
//Giải thích
//Lần 1 mất max(3 + 1, 2 + 5, 4 + 3) = 7 đơn vị thời gian. Các nhóm sau đó: 4 7 7
//Lần 2 mất 4+7=11 đơn vị thời gian. Các nhóm sau đó: 11 7
//Lần 3 mất 11+7=18 đơn vị thời gian. Tổng là 36
//Hạn chế
//• 2 ≤ n ≤ 105
//, 1 ≤ ai ≤ 100
//• Có 50% số test với n ≤ 1000

#include "bits/stdc++.h"
using namespace std;
int t;
int n;
int a[100001];
//int iMem[100001][100001];
//int num(int l,int r){
//    if(iMem[l][r] != -1) return iMem[l][r];
//    if(l==r) {
//        iMem[l][r] = a[l];
//        return a[l];
//    }
//    int m = (l+r)/2;
//    iMem[l][r] = iMem[l][m] + iMem[m+1][r];
//    return iMem[l][r];
//}

//int dem = 0;
//int num(int l, int r){
//    if(l == r) return a[l];
//    int m = (l+r)/2;
//    return num(l,m) + num(m+1,r);
//}
//int dc(int l,int r){
//    int m = (l+r)/2;
//    if(l+1 == r){
//        cout << "Lan " << ++dem << " , [l,r]= "<<l<<" , "<<r<<" ,tg them = "<< max(num(l,m), num(m+1,r)) <<endl;
//        return max(a[l], a[r]);
//    }
//    if(l == r) {
//            cout << "Lan " << ++dem << " , [l,r]= "<<l<<" , "<<r<<" ,tg them = "<< max(num(l,m), num(m+1,r)) <<endl;
//            return a[l];
//    }
//
//    if(m%2 == 1) m--;
//
//    int t1 = dc(l,m);
//    int t2 = dc(m+1,r);
//
//    cout << "Lan " << ++dem << " , [l,r]= "<<l<<" , "<<r<<" ,tg them = "<< max(num(l,m), num(m+1,r)) <<endl;
//    return t1 + t2 + max(num(l,m), num(m+1,r));
//}
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> t;
//    while(t--){
//        cin >> n;
//        for(int i=1;i<=n;i++) cin >> a[i];
//        //init
////        for(int i=1;i<=n;i++)
////            for(int j=1;j<=n;j++)
////                iMem[i][j] = -1;
//        cout << dc(1, n) <<endl;
//    }
//
//
//
//
//
//
//
//
//
//    return 0;
//}
