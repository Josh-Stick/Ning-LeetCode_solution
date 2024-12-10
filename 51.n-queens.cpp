/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    vector<vector<string>> result;
    void backtrace(int n, int row, vector<string>& path) {
        if (row == n) {
            result.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, path, n)) {
                path[row][col] = 'Q';
                backtrace(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& path, int n) {
        // 检查列
        for (int i = 0; i < row; i++) {
            if (path[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >=0; i--, j--) {
            if (path[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (path[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> path(n, string(n, '.'));
        backtrace(n, 0, path);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

