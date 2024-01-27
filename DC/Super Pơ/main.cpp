//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//
//
//Example 1:
//
//Input: a = 2, b = [3]
//Output: 8
//Example 2:
//
//Input: a = 2, b = [1,0]
//Output: 1024
//Example 3:
//
//Input: a = 1, b = [4,3,3,8,5,2]
//Output: 1
#include "bits/stdc++.h"
using namespace std;
const int mod = 1337;
int exp(int a, int n){
    int b = exp(a,n/2)%mod;
    if(n%2 == 0) return (b*b)%mod;
    else return ((b*b)%mod)*a%mod;
}
int superPow(int a, vector<int>& b) {
    int n = b.size();
    int p =0;
    for(int i=0;i<n;i++){
        p = (p*10+b[i]) % mod;
    }

    return exp(a,p);
}

int main(){
    int a=2;
    vector<int> b = {3};
    cout << superPow(a,b);

}
