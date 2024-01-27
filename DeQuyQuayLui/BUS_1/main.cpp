//Một xe bus xuất phát từ điểm 0 và cần phục vụ đón trả
//N khách 1, 2, …, N. Khách thứ i có điểm đón là i và
//điểm trả là N+i. Xe bus chở được tối đa Q khách cùng
//một lúc. Hãy liệt kê tất cả các phương án đón trả cho
//xe bus.
#include "bits/stdc++.h"
using namespace std;
int n;
int q;
int qcurr = 0;
int x[2001];
int x_best[2001];
bool tham[2001];
int c[2001][2001];
int cmin = INT_MAX;
int f0=0;
int f_min=INT_MAX;
int g;
bool check(int v,int k){
    if(v<=n && !tham[v] && qcurr<q){
        return true;
    }
    if(v>n && !tham[v] && tham[v-n]){

         return true;
    }
    return false;
}
void TRY(int k){
    for(int v=1;v<=2*n;v++){
        if(check(v,k)){
            x[k] = v;
            tham[v] = true;
            if(v<=n) qcurr++;
            else qcurr--;
            f0+= c[x[k-1]][v];
            if(k == 2*n){
                //f_min = min(f_min, f0+c[v][0]);
                if(f0+c[v][0] < f_min){
                    f_min = f0+c[v][0];
                    for(int i=1;i<=2*n;i++){
                        x_best[i] = x[i];
                    }
                }
            }
            else if(f0+(2*n-k)*cmin < f_min) TRY(k+1);

            f0-= c[x[k-1]][v];
            if(v<=n) qcurr--;
            else qcurr++;
            tham[v] = false;
        }
    }
}


int main(){
    cin >> n >> q;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }

    for(int i=1;i<=2*n;i++) tham[i] = false;
    x[0] = 0;
    TRY(1);
    //cout << f_min;
    cout << n <<endl;
    for(int i=1;i<=2*n;i++) cout << x_best[i] <<" ";
    return 0;
    }
