// Source : https://leetcode-cn.com/problems/rotate-image/
// Author : Yang Li
// Date   : 2020-03-02

/********************************************************************************** 
* 题目：
* 给定一个 n × n 的二维矩阵 matrix 表示一个图像。
* 请你将图像顺时针旋转 90 度。
* 
* 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
* 请不要 使用另一个矩阵来旋转图像。
**********************************************************************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();  //因为1 <= n <= 20，所以无符号整形可以转换为整型；
       int i, j;
       for(i = 0; i < n / 2; i++) { 
           for(j = 0; j < n; j++) {
               swap(matrix[i][j], matrix[n - i - 1][j]); //水平翻转
           }
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < i; j++) { //不是j < n / 2;
                swap(matrix[i][j], matrix[j][i]); //主对角线翻转
            }
        }
       
    }
};

/********************************************************************************** 
* 说明：
* 方法一：使用辅助数组
* 1.对于矩阵中第 i 行的第 j 个元素，在旋转后，它出现在倒数第 i 列的第 j 个位置；
* 2.亮点代码：auto matrix_new = matrix;
* 3.使用了值拷贝，不满足原地旋转的要求；
* 4.可以使用temp满足原地旋转要求，但数学过程较为复杂，也不具备扩展性，略过；
* 方法二：用翻转代替旋转：可以避免由于temp的使用而带来的复杂性；
**********************************************************************************/
