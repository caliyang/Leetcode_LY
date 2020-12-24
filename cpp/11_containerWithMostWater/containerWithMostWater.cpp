// Source : https://leetcode-cn.com/problems/container-with-most-water/
// Author : Yang Li
// Date   : 2020-12-22

/********************************************************************************** 
* 题目：
* 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
* 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
* 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
* 
* 说明：
* 你不能倾斜容器。
* 
**********************************************************************************/

/**********************************************************************************
 * 说明：
 * 1.感觉类似于小学奥数题。。。
 * 2.双指针的核心思想：先求每个局部的最大值，在每个局部的最大值中的最大值即为整体的最大值；
 * 3.输出结果不是正确答案时，按照程序流程来推，不是按照解题思想来推；
 **********************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, tail = height.size() - 1;
        int answer = 0;
        while(first < tail){
            int area = min(height[first], height[tail]) * (tail - first);
            answer = max(answer, area);
            if(height[first] < height[tail])  ++first;
            else --tail;
        }

        return answer;
    }
};
