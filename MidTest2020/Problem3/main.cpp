//Tìm số dãy con (k liên tục) có tổng từ A-> B. Sô phần tử lên đến 40
#include "bits/stdc++.h"
using namespace std;
int n = 10;
int a1=3,b1=7;
int a[] = {1,3,2,5,4,6,2,4,5,3};
int dem = 0;

void TRY(int i,int sum){
    if(i==n){
        if(sum>=a1 && sum <= b1) dem++;
        return ;
    }
    TRY(i+1,sum);
    TRY(i+1,sum+a[i]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TRY(0,0);
    cout << dem;


    return 0;
}
