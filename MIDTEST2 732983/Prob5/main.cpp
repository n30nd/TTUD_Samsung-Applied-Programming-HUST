
#include "bits/stdc++.h"
using namespace std;
#define ull unsigned long long
int n;
const ull p = 10e9+7;

int solve(){
    vector<int> f0(n+1,0);
    vector<int> f1(n+1,0);
    vector<int> f2(n+1,0);

    f0[1] = 1;
    f1[1] = 1;
    f2[1] = 1;
    for(int i=2;i<=n;i++){
        f0[i] = f1[i-1]+f2[i-1];
        f1[i] = f0[i-1]+f2[i-1];
        f2[i] = f0[i-1]+f1[i-1]+f2[i-1];
    }
    return f0[n]+f1[n]+f2[n];
}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << solve();
    return 0;
}

//#include "bits/stdc++.h"
//using namespace std;
//int n;
//int x[100];
//int dem = 0;
//bool check(int v,int k){
//    if(k==1) return true;
//    if(x[k-1]==0 && v==0) return false;
//    if(x[k-1]==1 && v==1) return false;
//    return true;
//}
//void TRY(int k){
//    for(int v=0;v<3;v++){
//        if(check(v,k)){
//            x[k] = v;
//            if(k==n){
//                dem++;
//                cout <<endl;
//                for(int i=1;i<=n;i++) cout <<x[i]<< " ";
//            }
//            else TRY(k+1);
//        }
//    }
//
//}
//
//
//int main(){
//    cin >> n;
//    TRY(1);
//    cout << "dem = "<<dem;
//    return 0;
//}
