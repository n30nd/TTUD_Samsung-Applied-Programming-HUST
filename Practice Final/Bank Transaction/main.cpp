//THI CUỐI KỲ THUẬT TOÁN ỨNG DỤNG
//Thời gian: 120 phút
//MÔ TẢ CHUNG CHO BÀI 1, 2, 3, 4
//Dữ liệu về các giao dịch chuyển tiền ngân hàng trong một ngày được cho bởi định dạng sau đây:
//<from account> <to_accounts <money> <time_point> <atm>
//Trong đó:
//<from account>: là tài khoản chuyển tiền (xâu kỳ tự độ dài tiừ 6 đến 20)
//<to_account>: tài khoản nhận tiền (xâu kỳ tự độ dài từ 6 đến 20)
//<money>: số tiền được chuyển trong giao dịch (số nguyên từ 1 đến 100)
//<time_point>: thời điểm giao dịch diễn ra, đó là một xâu ký tự định dạng HH:MM:SS (giờ phút: giây)
//<atm>: mã của ATM nơi thực hiện giao dịch chuyển tiền (xâu ký tự độ dài từ 3 đến 10)
//Ví dụ: T00112233445 T001234002 20 08:36:25 BIDV (tại ATM BIDV, tài khoản T00112233445 chuyến 20$ cho tài khoản T001234002 tại thời điểm 08:36:25 (08 giờ, 36 phút, 25 giây).
//Một chu trình giao dịch độ dài n bắt đầu từ tài khoản A1 là 1 dãy các tài khoản khác nhau A1, A2, ..., An trong đó A1 có chuyến tiền cho A2; A2 có chuyển tiền cho A3, An có chuyển tiền cho A1
//Viết chương trình thực hiện các truy vấn sau đây trên tập dữ liệu giao dịch chuyển tiền nêu trên
//?total_money_transaction: tổng số tiền trong tất cả các giao dịch đã cho
//?total_money_transaction_from <account>: tính tổng số tiền được chuyến đi bởi tài khoản <account>
//?inspect_cycle<acc> tính và trả về giá trị 1 nếu có 1 chu trình giao dịch độ dài <n> bắt đầu từ giao dịch <acc>; và trả về 0, nếu ngược lại
//?max_money_period <time1> <time2>: tính số tiền của giao dịch lớn nhất được thực hiện trong giai đoạn từ <time1> đến <time2> (<time1> và <time2> có định dạng HH:MM:SS như trên)
//Input (stdin)
//Dữ liệu đầu vào bao gồm 2 khối thông tin: khối thông tin về giao dịch và khối thông tin về các truy vấn
//Khối thông tin về giao dịch bao gồm các dòng (mỗi bộ dữ liệu test có thể lên đến 100000 dòng)
//Mỗi dòng là thông tin về 1 giao dịch được mô tả theo định dạng nêu trên
//Khối thông tin về giao dịch được kết thúc bởi dòng chứa ký tự #
//
//
//
//BÀI 1. Chỉ thực hiện truy vẫn dang ?total_money_transaction
//Input
//1000000005 T000000002 30 06:05:27 atm6
//1000000001 T000000005 20 10:13:45 atm1
//T000000004 T000000005 10 20:43:08 atm1
//?total_money_transaction
//Output
//60
//
//Bài 2 Truy vấn dạng ?total_money_transaction_from <account>
//Input
//T000000005 1000000002 30 06:05:27 atm6
//T000000001 1000000005 20 10:13:45 atm1
//T000000004 T000000005 10 20:43:08 atm1
//1000000001 T000000002 40 10:13:45 atm1
//#
//?total_money_transaction_from T000000001
//?total_money_transaction_from 1000000005
//
//Output
//60
//30
//BÀI 3. Chỉ thực hiện truy vấn dạng ?inspect_cycle
//Input
//T000000005 1000000002 30 06:05:27 atm6
//T000000001 T000000005 20 10:13:45 atm1
//T000000004 T000000005 10 20:43:08 atm1
//T000000001 T000000002 40 10:13:45 atm1
//T000000002 T000000001 60 11:13:40 atm1
//#
//?inspect_cycle T000000001 3
//?inspect_cycle T000000004 2
//?inspect_cycle T000000001 2
//#
//Output
//1
//0
//1
//BÀI 4. Chỉ thực hiện truy vấn dạng ?max_money_period
//Ví dụ
//Input
//T000000005 T000000002 34 06:05:27 atm6
//T000000001 T000000005 90 10:13:45 atm1
//T000000004 T000000005 96 20:43:08 atm1
//T000000005 T000000002 81 06:05:27 atm2
//T000000005 T000000002 11 04:45:38 atm2
//#
//?max_money_period 00:00:00 23:59:59
//?max_money_period 04:00:20 06:05:26
//?max_money_period 06:05:27 10:13:45
//#
//Output
//96
//11
//90

#include "bits/stdc++.h"
using namespace std;

int money_from[10000];
int money_at_time[86400];
int total_money = 0;
vector<int> adj[10000];
int end_point;
bool visited[10000];

bool TRY(int u,int k){
    if(k==1){
        for(int v : adj[u]){
            if(v == end_point) return true;
        }
    }
    else {
        for(int v: adj[u]){
            if(!visited[v] && v!=end_point){
                visited[v] = true;
                if(TRY(v,k-1) == true){
                    return true;
                }
                visited[v] = false;
            }
        }
    }
    return false;
}
int account_to_int(string &ac){
    int t = 0;
    for(int i=1;i<ac.size();i++){
        t = t*10 + (ac[i] - '0');
    }
    return t;
}

int time_to_int(string& time){
    int h = (time[0]-'0')*10 + time[1]-'0';
    int m = (time[3]-'0')*10 + time[4]-'0';
    int s = (time[6]-'0')*10 + time[7]-'0';
    return h*3600+m*60+s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //init
    for(int i=0;i<10000;i++){
        money_from[i] = 0;
        adj[i].clear();
    }
    for(int i=0;i<86400;i++) money_at_time[i] = 0;

    string from_ac, to_ac, time,atm;
    int money;

    while(cin >> from_ac){
        if(from_ac == "#") break;
        cin >> to_ac >> money >> time >> atm;

        money_from[account_to_int(from_ac)] += money;
        adj[account_to_int(from_ac)].push_back(account_to_int(to_ac));
        total_money += money;
        money_at_time[time_to_int(time)] = max(money_at_time[time_to_int(time)], money);
    }

    string q;
    while(cin >> q){
        if( q == "#") break;
        if(q == "?total_money_transaction") {
            cout <<total_money <<endl;
            continue;
        }
        if(q == "?total_money_transaction_from"){
            string ac;
            cin >> ac;
            cout << money_from[account_to_int(ac)] <<endl;
            continue;
        }
        if(q== "?inspect_cycle"){
            int k;
            cin >> from_ac >> k;
            end_point = account_to_int(from_ac);
            for(int i=0;i<10000;i++) visited[i] = false;
            cout << TRY(end_point, k)<<endl;
            continue;

        }
        if(q == "?max_money_period"){
            string time1,time2;
            cin >> time1 >>time2;

            int t1 = time_to_int(time1);
            int t2 = time_to_int(time2);
            int max_money = 0;
            for(int i=t1;i<=t2;i++){
                max_money = max(max_money, money_at_time[i]);
            }
            cout << max_money <<endl;
            continue;
        }

    }

    return 0;
}
