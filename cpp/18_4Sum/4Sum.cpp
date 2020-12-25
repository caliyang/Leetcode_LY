// Source : https://leetcode-cn.com/problems/4Sum/
// Author : Yang Li
// Date   : 2020-12-25

/********************************************************************************** 
* 题目：
* 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
* 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
* 找出所有满足条件且不重复的四元组。
* 
* 说明：
* 答案中不可以包含重复的四元组。 
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int numssiz = nums.size();
        vector<vector<int>> ans;
        if(numssiz < 4) return ans; //给定的数组长度小于4，直接返回一个空vector；
        for(int first = 0; first < numssiz - 3; ++first) {
            if(first > 0 && nums[first] == nums[first - 1]) continue; 
            //用if，不用while，否则会锁死在这个循环里面
            if((nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3]) > target) break; 
            //break等价于return ans;
            if((nums[first] + nums[numssiz - 1] + nums[numssiz - 2] + nums[numssiz - 3]) < target) continue;
            for(int second = first + 1; second < numssiz - 2; ++second) {
                if(second > first + 1 && nums[second] == nums[second - 1]) continue; 
                //用if，不用while；
                //nums[second] == nums[second - 1]打成nums[first] == nums[first - 1]，浪费了2个多小时在“正确位置”找“错误”...
                if((nums[first] + nums[second] + nums[second + 1] + nums[second + 2]) > target) break; 
                //break不等价于return ans；
                //nums[second] + nums[second + 1] + nums[second + 2]打成nums[second] + nums[second + 2] + nums[second + 3]；
                if((nums[first] + nums[second] + nums[numssiz - 1] + nums[numssiz - 2]) < target) continue;
                int forth = numssiz - 1;
                int third = second + 1;
                while(third < forth) {
                    int sum = nums[first] + nums[second] + nums[third] + nums[forth];
                    if(sum == target) {
                        ans.push_back({nums[first], nums[second], nums[third], nums[forth]});
                        while(third < forth && nums[third] == nums[third + 1]) ++third;
                        ++third;
                        while(third < forth && nums[forth] == nums[forth - 1]) --forth;
                        --forth; 
                    } else if(sum < target) {
                        int thirdtemp = third + 1;
                        while(thirdtemp < forth && nums[thirdtemp] == nums[thirdtemp - 1]) ++thirdtemp;
                        third = thirdtemp;
                        //++third;
                    } else {
                        int forthtemp = forth - 1;
                        while(third < forthtemp && nums[forthtemp] == nums[forthtemp + 1]) --forthtemp;
                        forth = forthtemp;
                    }
                }                                  
            }

        }

        return ans;
    }
};

/********************************************************************************** 
* 说明：
* 1.记得判断，当给定的数组长度小于4时，直接返回一个空vector；
* 2.认真写代码。nums[second] == nums[second - 1]打成nums[first] == nums[first - 1]，
*              nums[second] + nums[second + 1] + nums[second + 2]打成nums[second] + nums[second + 2] + nums[second + 3]，
*              忽略了上述打字错误，浪费2个多小时在后面“正确的位置”找错误；
* 3.注意和第16题target检查的不同，此处的检查应该分为三类，因为可能有多个符合要求的四元数；
**********************************************************************************/
