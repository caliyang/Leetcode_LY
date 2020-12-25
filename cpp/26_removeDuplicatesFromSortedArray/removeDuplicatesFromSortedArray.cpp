// Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
// Author : Yang Li
// Date   : 2020-12-25

/********************************************************************************** 
* 题目：
* 给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
* 
* 说明：
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
*               
**********************************************************************************/

//方法：快慢指针；
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        int slow = 0;
        for(int fast = 1; fast < length; fast++) {
            if(nums[fast] != nums[fast - 1]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};

//说明：注意首先验证数组的长度是否为0；
