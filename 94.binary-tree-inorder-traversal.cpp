/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=
 *
 * [94] 二叉树的中序遍历
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 递归
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     travel(root, res);
    //     return res;

    // }
    // void travel(TreeNode* cur, vector<int>& vet) {
    //     if (cur == nullptr) return;
    //     travel(cur->left, vet);
    //     vet.push_back(cur->val);
    //     travel(cur->right, vet);
    // }
    // 迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {   // 指针来访问节点，访问到最底层
                stk.push(cur);      // 将访问的节点放进栈
                cur = cur->left;  
            } else {
                cur = stk.top();  // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                stk.pop();       
                res.push_back(cur->val);   // 访问根结点
                cur = cur->right;          // 访问右子树
            }
            }
            return res;
        }

    
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

