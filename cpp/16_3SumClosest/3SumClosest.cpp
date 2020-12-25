// Source : https://leetcode-cn.com/problems/3sum-closest/
// Author : Yang Li
// Date   : 2020-12-24

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
        int best = 1e7;                                         //初始的best值必须足够大才行；
        for(int first = 0; first < numssiz - 2; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) continue;
            int third = numssiz - 1;
            int second = first + 1;
            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if(sum == target) return target;               //唯一输出，直接用return结束函数即可，不需要用break等统一到后面的return best；
                best = (abs(best - target) < abs(sum - target)) ? best : sum;
                if(sum < target) {                             //判断条件是当前的sum，不是前面的best；
                    int secondtemp = second + 1;
                    while(secondtemp < third && nums[secondtemp] == nums[secondtemp - 1]) ++secondtemp; //不需要条件secondtemp > first + 1，因为一定满足；
                    second = secondtemp;
                }
                else {
                    int thirdtemp = third - 1;
                    while(second < thirdtemp && nums[thirdtemp] == nums[thirdtemp + 1]) --thirdtemp;   //不需要条件thirdtemp < numssiz - 1，因为一定满足；
                    third = thirdtemp;
                }
            }
        }
        return best; 
    }
};

/**********************************************************************************
* 说明：
* 1.小优化（可以减少运行时间，但不会减少时间复杂度）：
*   当我们枚举到恰好等于 target 的 a + b + c 时，可以直接返回 target 作为答案，不会有再比这个更接近的值了；
*   当我们枚举 a, b, c 中任意元素并移动指针时，可以直接将其移动到下一个与这次枚举到的不相同的元素，减少枚举的次数；
* 2.双指针移动的循环写法：一种是本题这样的，强调second < third，还有一种是第15题那样的，强调第二重循环；
*   实际做题时，建议用前面一种；
* 3.一段代码：
*   auto update = [&](int cur) {
*      if (abs(cur - target) < abs(best - target)) {
*          best = cur;
*      }
*   };
*   update(sum);
*   理解：lambda表达式。“[&]”等价于“[&target, &best, &nums, &n]”；（具体可百度捕捉列表含义）
**********************************************************************************/
