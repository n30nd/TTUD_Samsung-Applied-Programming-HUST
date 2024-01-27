//Cho dãy số nguyên a[1], a[2] .. a[n].
//Hãy đếm Q sô các cặp 2 chỉ số khác nhau i và j trong dãy sao cho
//hai phần tử a[i] và a[j] chênh lệch nhau 1 đơn vị và 1<=i,j<=n
//
//Input n
//a[i]
//output
//Q mod 10e9 +7
#include "bits/stdc++.h"
using namespace std;
const int mod = 10e9+7;
int n;
int a[100001];
map<int,int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        m[a[i]] = m[a[i]]+1;
    }
    int q = 0;
    vector<bool> visited(n+1, false);
    for(int i=1;i<=n;i++){
        if(!visited[a[i]] && m[a[i]+1] != 0){
            visited[a[i]] = true;
            q += m[a[i]] * m[a[i]+1];

        }
    }
    cout << q;
    return 0;
    }
