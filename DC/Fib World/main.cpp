//Problem E. Fibonacci Words
//Input File Name: stdin
//Output File Name: stdout
//Time Limit: 1 s
//Memory Limit: 256 MB
//The Fibonacci word sequence of bit strings is defined as:
//F(n) =
//
//
//
//0 if n = 0
//1 if n = 1
//F(n − 1) + F(n − 2) if n ≥ 2
//Here denotes concatenation of strings. The first few elements are:
//n F(n)
//0 0
//1 1
//2 10
//3 101
//4 10110
//5 10110101
//6 1011010110110
//7 101101011011010110101
//8 1011010110110101101011011010110110
//9 1011010110110101101011011010110110101101011011010110101
//Given a bit pattern p and a number n, how often does p occur in F(n)?
//Input
//The first line of each test case contains the integer n (0 ≤ n ≤ 100). The second line contains the bit
//pattern p. The pattern p is nonempty and has a length of at most 100 000 characters.
//Output
//For each test case, display its case number followed by the number of occurrences of the bit pattern p in
//F(n). Occurrences may overlap. The number of occurrences will be less than 263
//.
//Examples
//stdin stdout
//6
//10
//Case 1: 5

#include "bits/stdc++.h"
using namespace std;
string f[100];
int len[100];
int n;
string s;
int check1(){
    int dem = 0;
    int ls = s.length();
    int lf = f[n].length();

    for(int i=0;i<=lf-ls;i++){
        if(s == f[n].substr(i,ls)){
                dem++;}
    }
    return dem;
}
int cM(int n){
    int dem = 0;
    int ls = s.length();
    for(int i=len[n-1]-ls+1;i<len[n-1];i++){
        if(f[n].substr(i,ls) == s) dem++;
    }
    return dem;
}
int c(int n){
    if(len[n] < s.length()) return 0;
    return c(n-1)+c(n-2)+ cM(n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    f[0] = "0";
    f[1] ="1";
    len[0] = 1;
    len[1] = 1;
    for(int i=2;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
        len[i] = len[i-1]+len[i-2];
    }

    cout << check1() <<endl;
    cout << c(n);

    return 0;
    }
