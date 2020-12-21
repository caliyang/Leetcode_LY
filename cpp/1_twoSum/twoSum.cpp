// Source : https://leetcode-cn.com/problems/two-sum/
// Author : Yang Li
// Date   : 2020-12-20

/********************************************************************************** 
* 
* 给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
* 
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
* 
* 示例:
* 给定 nums = [2, 7, 11, 15], target = 9
* 因为 nums[0] + nums[1] = 2 + 7 = 9
* 所以返回 [0, 1]
*               
**********************************************************************************/

//循环遍历，O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numssiz = nums.size();
        for(int i1 = 0; i1 < numssiz; ++i1) {
            for(int i2 = i1 + 1; i2 < numssiz; ++i2) {
                if(nums[i1] + nums[i2] == target)
                return {i1, i2};
            }
        }
        cout << "给定值有误" << endl;
        return {};
    }
};

/* 说明：
 * 1.用 return语句 终止程序，而不是 break语句 跳出循环；
 * 2.return语句返回值，不需要构造一个临时对象（类似 vector<int>({i1, i2})），直接用{i1, i2}即可；
 */
