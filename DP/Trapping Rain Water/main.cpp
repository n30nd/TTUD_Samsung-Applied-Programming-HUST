//42. Trapping Rain Water
//Hard
//30K
//439
//Companies
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
//
//
//Example 1:
//
//
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
//Example 2:
//
//Input: height = [4,2,0,3,2,5]
//Output: 9

#include"bits/stdc++.h"
using namespace std;

    int find_first_index_of_bigger_r(vector<int>&height, int l){
        int n= height.size();
        for(int i=l+1;i<n;i++){
            if(height[l] <= height[i]) return i;
        }
        return -1;
    }
    int trap(vector<int>& height) {
        int s = 0;
        int l;
        int n = height.size();
        for( l=0;l<n;){
            int r = find_first_index_of_bigger_r(height, l);
            if(r != -1){
                s+= (r-l-1)*height[l];
                cout << "l= "<<l<<"r= "<<r<<"deltas= "<<(r-l-1)*height[l] <<endl;
                l = r;
            }
            else {
                l++;
            }
        }
        return s;
    }


int main(){

    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(h);


    return 0;
}
