// Source : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : Yang Li
// Date   : 2020-12-26

/********************************************************************************** 
* 题目：
* 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
* 找出给定目标值在数组中的开始位置和结束位置。
* 如果数组中不存在目标值 target，返回 [-1, -1]。
* 
* 进阶：你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
**********************************************************************************/

// 法一：蛮力枚举法
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        int begin = -1;
        int end = -1;
        for(int i = 0; i <= length - 1; i++) {
            if(nums[i] == target)
                if(begin == -1) begin = i;
                else end = i;
            if(nums[i] > target) break;   
        }
        if(end == -1) end = begin;
        
        return {begin, end};  
    }
};

// 法二：二分查找法
/********************************************************************************** 
* 该题的难点是对重复数字的处理：
* 第一种处理方法是先找到，再向左右扩展开，即下面这种方法；
* 第二种处理方法是找到大于等于target的leftIndex和大于target的rightIndex，如果两个索引对应的值都为target，则区间为[leftIndex, rightIndex]，即力扣展示的方法；
**********************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        //特例
        if(length == 0) return {-1, -1};
        //数组长度为1，且target不为nums[0]的情况并入到了下面一条的if语句中； 
        if(target < nums[0] || target > nums[length - 1]) return {-1, -1}; 
        int l = 0;
        int r = length - 1;
        int begin = -1;
        int end = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(target == nums[mid]) { //可以判断数组长度为1且target等于nums[0]的情况，数组会溢出；
                //数字重复出现时...
                begin = end = mid;
                while(begin >= 0 && target == nums[begin]) --begin;  //与逻辑运算当中的短路处理
                while(end <= length - 1 && target == nums[end])  ++end; //与逻辑运算当中的短路处理
                return {begin + 1, end - 1};
            }
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        return {begin, end};
    }
};
*/

/********************************************************************************** 
* 说明：
* 二分查找法查找有无该target的关键步骤：
*   1.特例：数组长度为0或1时；
*   2.小于等于：l <= r；
*   3.middle等于判断（target == nums[middle]）；
*   4.middle不等于时的处理；
* 二分查找法查找大于等于/大于target的关键步骤：
*   1.特例：数组长度为0或1时；
*   2.小于等于：l <= r；
*   3.middle等于判断（target == nums[middle]）；
*   4.middle不等于时的处理；
**********************************************************************************/
