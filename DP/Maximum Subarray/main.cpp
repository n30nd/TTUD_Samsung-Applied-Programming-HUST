//Given an integer array nums, find the
//subarray
// with the largest sum, and return its sum.
//
//
//
//Example 1:
//
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//Example 2:
//
//Input: nums = [1]
//Output: 1
//Explanation: The subarray [1] has the largest sum 1.
//Example 3:
//
//Input: nums = [5,4,-1,7,8]
//Output: 23
//Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
//
//
//Constraints:
//
//1 <= nums.length <= 105
//-104 <= nums[i] <= 104
#include "bits/stdc++.h"

using namespace std;
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int s[n];
        s[0] = nums[0];
        int maxS = nums[0];
        for(int i=1;i<n;i++){
            s[i] = max(nums[i], nums[i]+s[i-1]);
            maxS = max(maxS, s[i]);
        }
        return maxS;
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}
