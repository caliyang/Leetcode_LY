// Source : https://leetcode-cn.com/problems/3sum-closest/
// Author : Yang Li
// Date   : 2020-12-25

/********************************************************************************** 
* 题目：
* 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
* 找出 nums 中的三个整数，使得它们的和与 target 最接近。
* 返回这三个数的和。假定每组输入只存在唯一答案。
* 
**********************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int numssiz = nums.size();
        int ans = nums[0] + nums[1] + nums[numssiz -1];
        for(int first = 0; first < numssiz - 2; ++first) {
            int third = numssiz - 1;
            for(int second = first + 1; second < numssiz - 1; ++second)
                while(second < third) {             
                    int ans = nums[first] + nums[second] + nums[third];
                    if(ans < target) {
                    ++second;
                    ans = abs(ans - target) < abs(sum - target) ? ans : sum;
                    }
                    else {
                    --third;
                    ans = abs(ans - target) < abs(sum - target) ? ans : sum;
                    }
                }
        }
        return ans; 
    }
};
