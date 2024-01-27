////Problem: CBUS Large-Size
////Description
////There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0.
////Input
////Line 1 contains n and k (1≤n≤1000,1≤k≤50)
////Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
////Output
////Line 1: write the value n
////Line 2: Write the sequence of points (pickup and drop-off) of passengers (separated by a SPACE character)
////Example
////Input
////5 3
////0 5 8 11 12 8 3 3 7 5 5
////5 0 3 5 7 5 3 4 2 2 2
////8 3 0 7 8 8 5 7 1 6 5
////11 5 7 0 1 5 9 8 6 5 6
////12 7 8 1 0 6 10 10 7 7 7
////8 5 8 5 6 0 8 5 7 3 4
////3 3 5 9 10 8 0 3 4 5 4
////3 4 7 8 10 5 3 0 6 2 2
////7 2 1 6 7 7 4 6 0 5 4
////5 2 6 5 7 3 5 2 5 0 1
////5 2 5 6 7 4 4 2 4 1 0
////
////Output
////5
////1 2 6 7 5 10 3 4 8 9
//#include "bits/stdc++.h"
//using namespace std;
//int n,k,kcurr;
//int x[2001];
//bool visited[2001];
//int c[1001][1001];
//
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >>n >>k;
//    for(int i=0;i<=2*n;i++){
//        for(int j=0;j<=2*n;j++){
//            cin >> c[i][j];
//        }
//    }
//    memset(visited, false, sizeof(bool)*(n+1));
//
//    x[0] = 0;
//    kcurr = 1;
//    for(int i=1;i<=2*n;i++){
//        if(x[i-1] <= n){
//            if(kcurr < k){
//                int cmin = INT_MAX;
//                int x_curr;
//                for(int j=1;j<=n;j++){
//                    if(!visited[j] && c[x[i-1]][j] < cmin){
//                        cmin = c[x[i-1]][j];
//                        xcurr = j;
//                    }
//                }
//
//                if(cmin < c[i-1][x[i-1]+n]) {
//                    x[i] = x_curr;
//                    visited[i] = true;
//                    kcurr++;
//                }
//                else {
//                    x[i] = x[i-1]+n;
//                    visited[x[i]] = true;
//                    kcurr--;
//                }
//            }
//            else {
//
//            }
//
//
//        }
//    }
//
//
//    return 0;
//}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> c(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            cin >> c[i][j];
        }
    }

    vector<bool> visited(2 * n + 1, false);
    vector<int> route;
    route.push_back(0);  // Bắt đầu từ điểm 0

    // Thực hiện thuật toán Nearest Neighbor
    for (int i = 0; i < n; ++i) {
        int currentPoint = route.back();
        int nextPoint = -1;
        int minDistance = INF;

        // Tìm hành khách gần nhất chưa được phục vụ
        for (int j = 1; j <= 2 * n; ++j) {
            if (!visited[j] && c[currentPoint][j] < minDistance) {
                nextPoint = j;
                minDistance = c[currentPoint][j];
            }
        }

        // Di chuyển đến điểm tiếp theo và đánh dấu hành khách đã được phục vụ
        visited[nextPoint] = true;

        // Thêm điểm đón và trả khách vào danh sách
        route.push_back(nextPoint - n);
        route.push_back(nextPoint);
    }

    // In kết quả
    cout << n << endl;
    for (int i = 0; i < route.size(); ++i) {
        cout << route[i] << " ";
    }

    return 0;
}

