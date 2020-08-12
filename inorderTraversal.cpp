// Binary Tree Inorder Traversal

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

// recursive solution

class Solution {
public:
	vector<int>* p = nullptr; // pointer to array which needs to be inorder traversal of binary tree (pointer to the output)
	void inorder(TreeNode* root) {
		if (!root) return;		// end of recursion
		inorder(root->left);		// left part of the subtree
		p->push_back(root->val);	// root of the subtree
		inorder(root->right);		// right part of the subtree
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>res;				// resulting vector
		p = &res;				// pointer to the resulting vector, this pointer is used in void inorder(TreeNode* root)
		inorder(root);				// call of the recursive function
		return res;
	}
};

// iterative solution

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return vector<int>();
		vector<int> res;				// resulting vector
		stack<TreeNode*> s;				// stack for remembering the root of the give subtree
		TreeNode* temp = root;				// current visited node, starting from the root
		while (!s.empty() || temp) {
			while (temp) {				// go to the most left node, which doesnt have left child
				s.push(temp);			// remember all past root subtree nodes
				temp = temp->left;
			}							
			temp = s.top();				// use the most left node and push it back to the resulting vecotr
			s.pop();
			res.push_back(temp->val);
			temp = temp->right;			// go right, or if the current visiting node doesnt have the right child, then it will be nullptr ( then in the next iteration::  temp := s.top() )
		}
		return res;
	}
};
