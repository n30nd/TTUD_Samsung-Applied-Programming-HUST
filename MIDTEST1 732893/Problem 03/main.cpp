#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    string s;
    int t;
    while(cin >> s){
        if(s == "#") break;
        if(s == "PUSH"){
            cin >> t;
            pq.push(t);
        }
        if(s == "POP"){
            cout << pq.top() <<endl;
            pq.pop();
        }

    }

    return 0;
}
