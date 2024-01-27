//Dãy con tăng dài nhất
//Cho một dãy n số nguyên A[1], A[2], . . . , A[n], hãy tìm độ dài của
//dãy con tăng dài nhất?
//Định nghĩa: Nếu xoá đi 0 phần tử hoặc một số phần tử của dãy A thì
//sẽ thu được một dãy con của A
//Ví dụ: a = [2, 0, 6, 1, 2, 9]
//[2, 6, 9] là một dãy con
//[2, 2] là một dãy con
//[2, 0, 6, 1, 2, 9] là một dãy con
//[] là một dãy con
//[9, 0] không là một dãy con
//[7] không là một dãy con

#include "bits/stdc++.h"
using namespace std;
int a[] = {2, 0, 6, 1, 2, 9};
int iMem[100];

int lis(int i){
    int res = 1;
    if(iMem[i] != -1) return iMem[i];

    for(int j=i-1;j>=0;j--){
        if(a[j] < a[i] ){
            res = max(res, 1+lis(j));
        }
    }
    iMem[i] = res;
    return res;
}

void trace(int i){
    for(int j=i-1;j>=0;j--){
        if(a[j]<a[i] && iMem[i]==iMem[j]+1){
            trace(j);
            break;
        }
    }
    cout << a[i] <<" ";

    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = sizeof(a)/sizeof(int);
    memset(iMem, -1, n*sizeof(int));
    cout << lis(n-1) <<endl;
    trace(n-1);
    }
