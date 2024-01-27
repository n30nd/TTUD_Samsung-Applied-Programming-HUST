//Description
//Given a set of segments X = {(a
//1
//, b
//1
//), . . . , (a
//n
//, b
//n
//)} in which ai < bi are coordinates of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in which no two segments of the subset intersect
//Input
//Line 1: contains a positive integer n (1 <= n <= 100000)
//Line i+1 (i= 1,...,n): contains ai and bi (0 <= a
//i
// <= b
//i
//<= 1000000)
//Output
//Number of segments in the solution found.
//Example
//Input
//6
//0 10
//3 7
//6 14
//9 11
//12 15
//17 19
//
//Output
//4
#include"bits/stdc++.h"
using namespace std;
int n;
vector<pair<int,int>> c;
vector<pair<int,int>> s;

bool check(pair<int,int> x){
    if(s.empty()) return true;
    return x.first > s.back().second;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x>>y;
        c.push_back({x,y});
    }
    sort(c.begin(), c.end(), [](pair<int,int> a, pair<int,int> b){
         return a.second < b.second ;
         });
    int out = 0;
    for(auto x : c){
        if(check(x)) {
            s.push_back(x);
            out++;
        }
    }
    cout << out;
    return 0;
}
