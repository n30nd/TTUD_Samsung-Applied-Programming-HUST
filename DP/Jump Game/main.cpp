
//Jump Game
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
////
//Return true if you can reach the last index, or false otherwise.
//
//
//
//Example 1:
//
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2:
//
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
//
//
//Constraints:
//
//1 <= nums.length <= 104
//0 <= nums[i] <= 105

#include "bits/stdc++.h"

using namespace std;

//bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        bool check[n];
//        check[0] = true;
//        for(int i=0;i<n;i++){
//            for(int c = 1; c<=nums[i];c++){
//                check[i+c] = true;
//                if(check[n-1]) return true;
//            }
//        }
//        return false;
//    }


//
//bool canJump(vector<int>& nums){
//    int n = nums.size();
//    if(n<=1) return true;
//    vector<bool> check(n, false);
//    check[0] = true;
//
//    for(int i=0;i<n;i++){
//        if(check[i]){
//            for(int c=1; c<= nums[i];c++){
//                if(i+c<n){
//                check[i+c] = true;
//                if(i+c == n-1) return true;
//                }
//            }
//        }
//    }
//    return false;
//}

bool canJump(vector<int>& nums){
    int n = nums.size();
    int last_pos = 0;
    for(int i=0;i<n;i++){
        if(i<=last_pos){
             int curr = i+nums[i];
            last_pos = max(last_pos, curr);
        }
    }
    return last_pos >= (n-1);

    }
int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums);
    return 0;
}
