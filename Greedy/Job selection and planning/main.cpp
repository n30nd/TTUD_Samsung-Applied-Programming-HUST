//Problem: Job selection and planning
//Description
//Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
//Select and schedule a subset of jobs of J such that the total profits is maximal.
//Input
//Line 1: contains a positive integer n (1 <= n <= 10
//5
//)
//Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10
//5
//)
//Output
//Write to total profits obtained from the subset of jobs found.
//
//Example
//Input
//6
//3 10
//2 40
//6 70
//3 50
//5 80
//1 60
//Output
//300
#include"bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> d_p;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >>y;
        d_p.push_back({x,y});
    }
    sort(d_p.begin(), d_p.end(), [](auto a, auto b){
    return a.second > b.second;
            });

    int out = 0;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        for(int j = min(n, d_p[i].first)-1; j>=0;j--){
            if(!visited[j]){
                visited[j] = true;
                out += d_p[i].second;
                break;
            }
        }
    }
    cout << out ;
}
