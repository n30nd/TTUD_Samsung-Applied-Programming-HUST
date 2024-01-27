//45. Jump Game II
//Medium
//13.7K
//493
//Companies
//You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
//
//Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
//
//0 <= j <= nums[i] and
//i + j < n
//Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
//
//
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: 2
//Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: nums = [2,3,0,1,4]
//Output: 2
//
//
//Constraints:
//
//1 <= nums.length <= 104
//0 <= nums[i] <= 1000
//It's guaranteed that you can reach nums[n - 1].

#include <bits/stdc++.h>

using namespace std;
//int jump(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> d(n, vector<int>(n, INT_MAX));
//        for(int i=0;i<n-1;i++){
//            for(int c = 1;c<=nums[i];c++){
//                d[i][c+i] = 1;
//            }
//        }
//
////        for(int i=0;i<n;i++){
////            for(int j=0;j<n;j++){
////                cout << d[i][j] << " ";
////            }
////            cout << "\n";
////        }
//        for(int i=n-2;i>=0;i--){
//            if(d[i][i+1]!=INT_MAX && d[i+1][n-1]!= INT_MAX){
//                d[i][n-1] = min(d[i][n-1], d[i][i+1]+d[i+1][n-1]);
//            }
//        }
//        if(d[0][n-1] != INT_MAX) return d[0][n-1];
//        return 0;
//
//    }

int jump(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;
    for(int i =n-2;i>=0;i--){
        int ans = INT_MAX;
        for(int c=1;c<=nums[i];c++){
            if(i+c >= n) break;
            ans = min(ans, dp[c+i]);
        }
        if(ans != INT_MAX) dp[i] = ans + 1;
        else dp[i] = INT_MAX;
    }

    return dp[0];
}
int main()
{
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
    return 0;
}
