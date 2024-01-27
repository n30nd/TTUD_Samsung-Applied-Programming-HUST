//Cho dãy a1,a2,...,an Tìm tổng lớn nhất của dãy con (k liên tiếp nghĩa là k có 2 ptu nào đứng cạnh nhau)
#include "bits/stdc++.h"
using namespace std;
int n = 5;
int a[] = {3,-1,-2,4,-5};
int iMem[100];
int dp(int i){
    if(i<0) return 0;
    if(iMem[i] != -1) return iMem[i];

    int res = max(dp(i-1), dp(i-2)+a[i]);
    iMem[i] = res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(iMem, -1, sizeof(iMem));

    cout << dp(n-1)<<endl;
    for(int i=0;i<n;i++) cout <<a[i]<<" ";
    cout <<endl;
    for(int i=0;i<n;i++) cout <<iMem[i]<<" ";

    return 0;
}
