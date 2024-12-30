/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
    vector<int> preorder_;
    unordered_map<int, int> inorder_map_;
    TreeNode* recurve(int root, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* root_node = new TreeNode(preorder_[root]);
        int inorder_root = inorder_map_[preorder_[root]];
        root_node->left = recurve(root+1, left, inorder_root-1);
        root_node->right = recurve(root+inorder_root-left+1, inorder_root+1, right);  //root+inorder_root-left+1的含义是：通过根节点索引（root）+左子树的长度（inorder_root-1 - left）+ 1 ) 再加1 的位置，就是右子树的根节点的位置。
        return root_node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder_ = preorder;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map_[inorder[i]] = i;
        }
        return recurve(0, 0, inorder.size()-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

