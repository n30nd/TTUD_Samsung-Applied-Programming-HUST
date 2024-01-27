//Description
//Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.
//
//Input
//Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
//Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A
//
//Output
//Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.
//
//Ví dụ
//Input
//8 12 5 6
//1 1 0 0 0 0 1 0 0 0 0 1
//1 0 0 0 1 1 0 1 0 0 1 1
//0 0 1 0 0 0 0 0 0 0 0 0
//1 0 0 0 0 0 1 0 0 1 0 1
//1 0 0 1 0 0 0 0 0 1 0 0
//1 0 1 0 1 0 0 0 1 0 1 0
//0 0 0 0 1 0 1 0 0 0 0 0
//1 0 1 1 0 1 1 1 0 1 0 1
//
//Output
//7
#include"bits/stdc++.h"
using namespace std;
int a[1000][1000];
bool visited[1000][1000];
int n,m,r,c;
int cnt = 0;
int soleMaze(){
    int di[] = {0,0,-1,1};
    int dj[] = {-1,1,0,0};
    vector<vector<int>> d(m+1,vector<int>(n+1));
    d[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int ii = p.first;
        int jj = p.second;

        for(int v=0;v<4;v++){
            int newi = ii+di[v];
            int newj = jj+dj[v];

//            if(newi<1 || newi>n ||newj<1 || newj>m){
//                return d[ii][jj]+1;
//            }

            if(a[newi][newj]==0 && !visited[newi][newj]){
                visited[newi][newj] = true;
                q.push({newi,newj});
                d[newi][newj] = d[ii][jj]+1;

                if(newi==1 || newi ==n ||newj==1 ||newj==m) return d[newi][newj]+1;
//                cout << ii<<"_"<<jj<<" to "<<newi<<"_"<<newj<<endl;
            }

        }
    }

    return -1;
}

int main(){
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) visited[i][j] = false;
    }

    cout << soleMaze();



    return 0;
    }
