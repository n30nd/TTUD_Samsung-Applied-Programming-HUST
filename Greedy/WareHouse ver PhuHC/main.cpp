#include<bits/stdc++.h>
using namespace std;

int Q[51][1005];
int c[1005][1005];
int n,m;
int visited[1005];
int q[1005];
int A[1005];
int curr[1005]={};

bool check(){
    for(int i=1; i<=n; i++){
        if (curr[i]<q[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>Q[i][j];
        }
    }

    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            cin>>c[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        cin>>q[i];
    }

    A[0]=0;
    int k=1;
    bool check=false;
    while(!check){
        float tmp=0;
        int v=0;
        for(int i=1; i<=m; i++){
            float curr=0;
            if (visited[i]!=1){
                for(int j=1; j<=n; j++){
                    curr+=Q[j][i];
                }
                curr=curr/c[A[k-1]][i];
            }
            if(curr>tmp){
                tmp=curr;
                v=i;
            }
        }
        A[k]=v;
        visited[v]=1;
        for(int i=1; i<=n; i++){
            curr[i]+=Q[i][v];
        }
        k++;
        check=true;
        for(int i=1; i<=n; i++){
            if (curr[i]<q[i]){
                check = false;
                break;
            }
        }
    }
    cout<<k-1<<endl;
    for(int i=1; i<k; i++){
        cout<< A[i]<<" ";
    }

}
