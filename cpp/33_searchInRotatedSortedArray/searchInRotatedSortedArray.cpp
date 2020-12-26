// Source : https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// Author : Yang Li
// Date   : 2020-12-26

/********************************************************************************** 
* 题目：
* 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后
* 可能变为 [4,5,6,7,0,1,2] ）。
* 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
**********************************************************************************/

// 思路：判断是左边有序还是右边有序,总在有序的那部分查找；
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        //二分查找法中的两个特例；
        if(length == 0) return -1;
        if(length == 1) return target == nums[0] ? 0 : -1;
        int l = 0;
        int r = length - 1;
        //二分查找法的判断条件是有“=”的
        while(l <= r) {
            int mid = (l + r) / 2;
            if(target == nums[mid]) return mid;
            //判断是左边有序还是右边有序,总在有序的那部分查找
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target  && target < nums[mid]) r = mid -1;
                else l = mid + 1;
            } else {
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }

        return -1;
    }
};
  
/********************************************************************************** 
* 说明：
* 1.二分查找法中的两个特例：数组长度为0或1时；
* 2.二分查找法的判断条件是有“=”的;
**********************************************************************************/
