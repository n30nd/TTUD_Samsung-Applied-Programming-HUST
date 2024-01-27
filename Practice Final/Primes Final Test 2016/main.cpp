//Bài C. primes
//Input: stdin
//Output: stdout
//Time limit: 1 giây
//Memory: 512 MB
//Given a positive integer n. Your task is to calculate how many ways to represent n as sum of at most k
//different prime numbers.
//Input
//The input contains two integers n, k (1 ≤ n ≤ 4000,1 ≤ k ≤ 10).
//Result
//Write the number of ways to represent n as sum of at most k different prime numbers.
//Example
//stdin stdout
//28 4 5
//Explanation
//28 can be represented as sum of at most 4 different prime numbers by one of the following ways:
//• 28=2+3+23
//• 28=2+7+19
//• 28=3+5+7+13
//• 28=5+23
//• 28=11+17


#include "bits/stdc++.h"
using namespace std;

vector<int> primes;
int n,k;
int size_primes;
int scurr = 0;
int kcurr = 0;
int cnt = 0;

bool isPrime(int& x){
    for(int i=2;i*i<=x;i++){
        if(x%i == 0) return false;
    }
    return true;
}

void TRY(int i){
    if(i == size_primes){
        if(scurr == n && kcurr <= k) cnt++;
        return;
    }
    scurr += primes[i];
    kcurr++;
    if(scurr <= n && kcurr <= k) TRY(i+1);

    scurr -= primes[i];
    kcurr--;
    if(scurr <=n && kcurr <= k) TRY(i+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >>k;

    for(int i=2;i<=n;i++){
        if(isPrime(i)) primes.push_back(i);
    }

    size_primes = primes.size();
    TRY(0);
    cout << cnt;
    return 0;
}

