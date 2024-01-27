//cho các tờ tiền mệnh giá 1,5,10,25,100 xu
//tìm số tờ ít nhất để đổi cho 34xu
#include"bits/stdc++.h"
using namespace std;
vector<int> C = {1,5,10,25,100};
int n=34;
int ncurr = 34;
int cothedemSoTo2(){
    int out = 0;
    while(!C.empty() && ncurr!=0){
        int x = C[C.size()-1];

        if(x<=ncurr) {
            ncurr = ncurr - x;
            out++;
        }
        else {
            C.pop_back();
        }
    }
    if(ncurr == 0) return out;
    return -1;

}
int main()
{
    cout << cothedemSoTo2();
    return 0;
}
