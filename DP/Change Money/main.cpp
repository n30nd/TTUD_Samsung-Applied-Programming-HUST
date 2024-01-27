//Tiền mệnh giá D[i]
//tìm số đồng tiền ít nhất để đổi sang x

#include "bits/stdc++.h"
#define INF 1000000
using namespace std;
int d[] = {0, 9,6,5,1};
int x;
int n; // so menh gia
// minCoin la hàm trả về số đồng tiền ít nhất để quy đổi x với mệnh giá tính đến D_i

int mem[100][100];
int minCoin(int i,int x){
    if(x<0) return INF;
    if(x == 0 ) {
        mem[i][x] = 0;
        return 0;
    }

    if(i<1) return INF;

    if(mem[i][x] != -1) return mem[i][x];
    int res = min(minCoin(i-1,x), minCoin(i,x-d[i])+1);
    mem[i][x] = res;
    return res;
}

void Trace(int i, int x){
    if(x<= 0 || i < 1) return;
    if(mem[i][x] == mem[i][x-d[i]] + 1){
        cout << d[i] << " ";
        Trace(i,x-d[i]);
    }
    else {
            Trace(i-1,x);
            }

}
int main(){
    x = 11;
    n = 4;

    //for(int i=1;i<=n;i++) cin >> d[i];
    sort(d+1,d+n+1);
    memset(mem, -1, sizeof(mem));
//    for(int i=0;i<=n;i++) mem[i][0] = 0;
    cout << minCoin(n,x) <<endl ;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            cout << mem[i][j] << " ";
        }
        cout <<endl;

    }
    cout << "trace: ";
    Trace(n,x);
    return 0;
}

