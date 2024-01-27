//Cho hai xâu (hoặc hai mảng số nguyên) n phần tử X[1], . . . , X[n] và
//Y [1], . . . , Y [m], hãy tìm độ dài của dãy con chung dài nhất của hai
//xâu
//X ="abcb"
//Y ="bdcab"
//Dãy con chung dài nhất của X và Y , "bcb", có độ dài 3
#include "bits/stdc++.h"
using namespace std;
string x = "abcb";
string y = "bdacb";
int iMem[100][100];

int lcs(int i,int j){
    if(iMem[i][j] != -1) return iMem[i][j];

    if(i<0 || j<0) {
        iMem[i][j] = 0;
        return 0;
    }

     int res = max(lcs(i-1,j), lcs(i,j-1));
     if(x[i] == y[j]) res = max(res, 1+lcs(i-1,j-1));
    iMem[i][j] = res;
    return res;
}

void trace(int i,int j){
    if(i<0 || j<0) return ;
    if(iMem[i][j] == iMem[i-1][j]){
        trace(i-1,j);
        return ;
    }
    if(iMem[i][j] == iMem[i][j-1]){
        trace(i,j-1);
        return ;
    }
    if(x[i] == y[j] && iMem[i][j] == iMem[i-1][j-1]+1){
        trace(i-1,j-1);
        cout << x[i] <<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(iMem, -1, sizeof(iMem));

    cout << lcs(x.length()-1,y.length()-1)<<endl;
    trace(x.length()-1,y.length()-1);

    return 0;

}
