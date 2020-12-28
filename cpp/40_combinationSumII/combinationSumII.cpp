// Source : https://leetcode-cn.com/problems/combination-sum-ii/
// Author : Yang Li
// Date   : 2020-12-27

/********************************************************************************** 
* 题目：
* 给定一个数组 candidates 和一个目标数 target ，
* 找出 candidates 中所有可以使数字和为 target 的组合。
* candidates 中的每个数字在每个组合中只能使用一次。
* 
* 说明：
* 所有数字（包括 target）都是正整数。
* 解集不能包含重复的组合。 
**********************************************************************************/



/********************************************************************************** 
* 说明：
* 1.数组元素重复与否，每个元素的使用次数多少，大致可以分为5类：
*   不重复 + 无数次：leetcode第39题；（典型的递归和回溯搜索问题）
*   不重复 + 一次：leetcode第39题中，递归式分类中的index全部写为index+1；（典型的递归和回溯搜索问题）
*   重复   + 无数次：对数组元素sort处理后，用条件candidates[index] == candidates[index - 1]跳过当次元素，从而转化为“不重复 + 无数次”问题的求解；
*   重复   + 一次（每类元素）：对数组元素sort处理后，用条件candidates[index] == candidates[index - 1]跳过当次元素，从而转化为“不重复 + 一次”问题的求解；
*   重复   + 一次（每个元素）：本题求解；
**********************************************************************************/

/*补充-错误答案：一点奇怪的是，数组元素重复的话，直接照搬“不重复 + 一次”的求解，如果首先不sort，输出甚至会少，而不是带有重复的全部输出；
                                                                         另外，sort后再reverse，输出也会少；
class Solution {
public:
    void bsa(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combine, int target, int index) {
        //递归基
        if(index == candidates.size()) return;
        if(target == 0) {
            ans.emplace_back(combine);
            return;
        }

        //递归式分类
        bsa(candidates, ans, combine, target, index + 1);

        if(target - candidates[index] >= 0) {
            combine.emplace_back(candidates[index]);
            bsa(candidates, ans, combine, target - candidates[index], index + 1);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //sort(candidates.begin(), candidates.end()); //数组元素重复的话，如果首先不sort，输出甚至会少；
        vector<vector<int>> ans;
        vector<int> combine;
        bsa(candidates, ans, combine, target, 0);
        return ans;
    }
};
*/
