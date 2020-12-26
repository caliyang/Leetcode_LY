// Source : https://leetcode-cn.com/problems/search-insert-position/
// Author : Yang Li
// Date   : 2020-12-26

/********************************************************************************** 
* 题目：
* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
* 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
* 你可以假设数组中无重复元素。
**********************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = (int)nums.size();
        int left = 0, right = length - 1, ans = length;
        //特殊情况
        if(length == 0) return 0; //数组长度为0时的情况
        if(target < nums[0]) return 0;  //target小于数组所有值的情况
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] <= target) {
                left = mid + 1;
                ans = mid; 
            } else {
                right = mid - 1;
            }
        }
        return nums[ans] == target ? ans : ans + 1; //如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    }
};

/********************************************************************************** 
* 说明-特例：
* 1.数组长度为0时的情况；
* 2.target小于数组所有值的情况；
* 3.如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
**********************************************************************************/
