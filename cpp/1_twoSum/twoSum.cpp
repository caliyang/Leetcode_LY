// Source : https://leetcode-cn.com/problems/two-sum/
// Author : Yang Li
// Date   : 2020-12-20

/********************************************************************************** 
* 题目：
* 给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
* 
* 说明：
* 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
*               
**********************************************************************************/

//暴力枚举匹配，O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numssiz = nums.size();
        for(int i = 0; i < numssiz; ++i) {
            for(int j = i + 1; j < numssiz; ++j) {
                if(nums[i] + nums[j] == target)
                return {i, j};
            }
        }
        return {};
    }
};

/* 说明：
 * 1.用 return语句 终止程序，而不是 break语句 跳出循环；
 * 2.return语句返回值，不需要构造一个临时对象（类似 vector<int>({i1, i2})），直接用{i1, i2}即可；
 */


//哈希表匹配，O(n)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numssiz = nums.size();
        unordered_map<int, int> hashtable;
        for(int i = 0; i < numssiz; ++i) {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()) 
                return {it->second, i};
            hashtable[nums[i]] = i; 
            }
        
        return {};
    }
};
*/

/* 说明：
 * 1.暴力枚举中，为寻找target-nums[i]导致了较高的时间复杂度；
 * 2.考虑到是要在数组中快速寻找到匹配数，因此可以用哈希表来做；
 */
