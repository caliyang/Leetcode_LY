// Source : https://leetcode-cn.com/problems/combination-sum/
// Author : Yang Li
// Date   : 2020-12-27

/********************************************************************************** 
* 题目：
* 给定一个无重复元素的数组 candidates 和一个目标数 target ，
* 找出 candidates 中所有可以使数字和为 target 的组合。
* candidates 中的数字可以无限制重复被选取。
* 
* 说明：
* 所有数字（包括 target）都是正整数。
* 解集不能包含重复的组合。 
**********************************************************************************/

class Solution {
public:
    //void - & - & - & - return - return; 
    void bsa(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combine, int target, int index) {
        //递归基
        if(index == candidates.size()) return; //第一种结果：数组中元素使用完的情况
        if(target == 0) {
            ans.emplace_back(combine);
            return; //第二种结果：命中时的情况
        }

        //递归分类
        bsa(candidates, ans, combine, target, index + 1); //第一种递归：忽略当下索引值的情况

        if(target - candidates[index] >= 0) { //第二种递归：使用当下索引值的情况
            combine.emplace_back(candidates[index]);
            bsa(candidates, ans, combine, target - candidates[index], index);
            combine.pop_back(); // 第三种结果：回溯到最开始的情况
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        bsa(candidates, ans, combine, target, 0);
        return ans;
    }
};

/********************************************************************************** 
* 思路：思路上是从前往后看用或不用，实际上是每次从后往前看用或不用，因此实际输出的combine顺序是逆序列出的；
* 举例：以candidates={2, 3, 6 ,7}和target = 7为例，它是这样遍历的：
*     首先全部元素都不使用，结果是return；
*     然后使用元素7（即过程if(target - candidates[3] >= 0)），元素7的结果是target=0；
*     元素"7"pop出去后，再使用元素6（即过程if(target - candidates[2] >= 0)，后面同理），元素6的结果依次是{6}+return，{6}+target(-7)<0，{6}+target(-6)<0；
*     元素"6"pop出去后，再使用元素3，元素3的结果依次是{3}+return，{3}+target(-7)<0，{3}+target(-6)<0，
*                                 {3, 3}+return，{3, 3}+target(-7)<0，{3, 3}+target(-6)<0，{3, 3}+target(-3)<0；
*     将{3, 3}中的2个元素“3”pop出去后，再使用元素2，元素2的结果依次是{2}+return，{2}+target(-7)<0，{2}+target(-6)<0，
*                                 {2, 3}+return，{2, 3}+target(-7)<0，{2, 3}+target(-6)<0，{2, 3}+target(-3)<0，
*                                 {2, 2}+return，{2, 2}+target(-7)<0，{2, 2}+target(-6)<0，{2, 2, 3}=0，
*                                 {2, 2, 2}+return，{2, 2, 2}+target(-7)<0，{2, 2, 2}+target(-6)<0，{2, 2, 2}+target(-3)<0；
*     将{2, 2, 2}中的3个元素“2”pop出去后，结束整个遍历；
**********************************************************************************/

/********************************************************************************** 
* 说明-递归&回溯：
* 1.对于这类寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决；
* 2.搜索回溯的过程一定存在一些优秀的剪枝方法来使得程序运行得更快。本例中是
*   if(target - candidates[index] >= 0);
* 3.明确自己的树中展示的是哪一时刻的数值。题解中用的时刻是  
*   void dfs(vector <int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx)；
* 4.终止条件为 target <= 0 或者 candidates 数组被全部用完，有三种情况，两种结局：
*   一是target < 0时的结局，往上回溯一步，最终结局为下面二种之一；
*   二是数组被全部用完的结局，即进入if(idx == candidates.size())后，return；
*   三是target = 0的时候，即满足要求的combine；
**********************************************************************************/
