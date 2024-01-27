//Problem: Max Even SubSequence
//Description
//Given a sequence of n integers a=a
//1
//, . . ., a
//n
//. A subsequence of a consists of contiguous elements of a (for example, a
//i
//, a
//i+1
//, . . . ,a
//j
//). The weight of a subsequence is defined to be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. Find the even-subsequence of a having largest weight.
//Input
//Line 1: contains a positive integer n (1 <= n <= 10
//6
//)
//Line 2: contains a
//1
//, . . ., a
//n
// (-10
//6
// <= a
//i
// <= 10
//6
//)
//Output
//The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.
//Example
//Input
//4
//1  2  -3  4
//Output
//4

#include "bits/stdc++.h"
#define ll long long
#define MAX 1000001
using namespace std;
    ll a[MAX];
    ll sc[MAX], sl[MAX];
    bool bc[MAX], bl[MAX];
    int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    ll maxSC = INT_MIN;
    for(int i=1;i<=n;i++) {
            cin >> a[i];
            bc[i] = false;
            bl[i] = false;
            sc[i] = 0;
    }


    if(a[1]%2 == 0){
        bc[1] = true;
        bl[1] = false;
        sc[1] = a[1];
        maxSC = a[1];
    }
    else {
        bl[1] = true;
        bc[1] = false;
        sl[1] = a[1];
    }

    for(int i=2;i<=n;i++){
        if(a[i]%2 == 0){
            if(bc[i-1] && sc[i-1]>0){
                sc[i] = sc[i-1]+a[i];
            }
            else sc[i] = a[i];
            bc[i] = true;
            if(bl[i-1]){
                sl[i] = sl[i-1] + a[i];
                bl[i] = true;
            }
            else bl[i-1] = false;
        }

        else {
            if(bc[i-1] && sc[i-1]>0){
                sl[i] = sc[i-1]+a[i];
            }
            else sl[i] = a[i];
            bl[i] = true;

            if(bl[i-1]){
                sc[i] = sl[i-1] + a[i];
                bc[i] = true;

           }
            else bc[i] = false;
        }

        if(bc[i]) maxSC = max(maxSC, sc[i]);
    }

    if(maxSC != INT_MIN) cout << maxSC;
    else cout << "NOT_FOUND";

    return 0;
}
