/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  //这个二维vector中第一维的大小，也就是它包含的vector<int>的数量。不过这里是矩阵行数等于列数
        //对矩阵进行转置，即将矩阵的行和列进行交换。
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (i == j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }  
        }
        // 对每一行进行反转，即将每一行的元素顺序进行反转。
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */

