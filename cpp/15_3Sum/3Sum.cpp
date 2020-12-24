// Source : https://leetcode-cn.com/problems/3sum/
// Author : Yang Li
// Date   : 2020-12-24

/********************************************************************************** 
* 题目：
* 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
* 使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
* 
* 注意：答案中不可以包含重复的三元组。
* 
**********************************************************************************/

/**********************************************************************************
* 说明：
* 1.不可以包含重复的三元组：一是需要排序，从小到大，且a<=b<=c；
*                         二是对于某一重循环而言，相邻两次枚举的元素不能相同；
    （如果直接蛮力枚举，后续需要继续对“含义二”导致的重复去重，比较麻烦）
* 2.双指针使用说明：排序后，蛮力枚举中的第三重循环可以与第二重循环并列进行，
*   也就是说,保持第二重循环不变，而将第三重循环变成一个从数组最右端开始向左移动的指针,
*   满足“枚举数组中两个元素时，随着第一个元素的递增，第二个元素是递减的”，因此可用双指针；
* 3.排序后，在第一重循环固定后，用哈希表的一个难点是，对“含义二”导致的重复去重；
**********************************************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numssiz = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < numssiz - 2; ++first){
            if(first > 0 &&  nums[first - 1] == nums[first])  continue;
            int target = -nums[first];
            int third = numssiz - 1;
            for(int second = first + 1; second < numssiz - 1; ++second){
                if(second > first + 1 && nums[second] == nums[second - 1])  continue;
                while(second < third && nums[second] + nums[third] > target){
                    --third;
                }
            if(second == third)  break;
            if(nums[second] + nums[third] == target)  
                answer.push_back({nums[first], nums[second], nums[third]});
            }
        }

        return answer;
    }
};
