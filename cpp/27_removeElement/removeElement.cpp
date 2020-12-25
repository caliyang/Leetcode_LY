// Source : https://leetcode-cn.com/problems/remove-element/
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

//快慢指针法

//法一：重复元素较多的情况下
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int slow = 0;
        //if(length == 0) return 0; slow=0包含了数组长度为0的情况；
        for(int fast = 0; fast < length; fast++) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

//法二：重复元素较多的情况下
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int bigIndex = length - 1; 
        int index = 0;
        while(index <= bigIndex) { //此处应该是小于等于，不是小于
            if(nums[index] == val) {
                swap(nums[index], nums[bigIndex]); //nums[index] = nums[size];更好
                bigIndex--;
            } else {
                index++;
            }
        }
        return bigIndex + 1; //因为bigIndex只是索引值，因此最后应该加1
    }
};

/********************************************************************************** 
* 说明：
* 1.原地删除/原地移除：可以理解为覆盖不需要元素或者把不需要元素移至数组末尾；
* 2.slow=0包含了数组长度为0的情况，因此不需要if(length == 0) return 0; 
**********************************************************************************/
