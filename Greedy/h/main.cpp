#include "bits/stdc++.h"
using namespace std;
const int mod = 10e9+7;
int n;

int a[200001];
int b[200001];



int main(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++) cin >> b[i];

    int i = 0;
    int j = 1;

    int s = 0;
    int sign = 1;

    while(i<n){
        if(j<n-1 && b[j+1] == 2){
            sign = b[j];
            i++;
            j++;
            int tmp = a[i];
            while(j<=n && b[j] == 2){

                i++;
                j++;
                tmp = (tmp*a[i])%mod;
            }

            if(sign == 0) s = s- tmp;
            if(sign == 1) s = s + tmp;
            continue;
        }

        if(b[j]==0){
            s = s - a[i+1];
            i++;
            j++;
        }
        if(b[j] == 1){
            s = s + a[i+1];
            i++;
            j++;
        }
    }

    cout << s;

    return 0;

    }
