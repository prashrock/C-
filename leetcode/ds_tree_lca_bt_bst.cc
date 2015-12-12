//g++ --std=c++11 -g -o ds_tree_lca_bt_bst ds_tree_lca_bt_bst.cc

/**
 * @file  BT/BST find the LCP
 * @brief Find Lowest Commmon Parent/Ancestor given two nodes
 */

#include <iostream>          /* std::cout                    */
#include <iomanip>           /* std::setw                    */
#include <cmath>             /* pow                          */
#include <cassert>           /* assert                       */
#include <algorithm>         /* std::max                     */
#include <string>            /* std::string,                 */
#include <cstring>           /* std::strtok                  */
#include <queue>             /* std::priority_queue          */
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Recursive approach to find LCP of BT               *
 * @param root = current node of BST.                        *
 * @param p, q = Nodes known to be in BT, whose LCA we want  *
 * @ret   LCA node pointer                                   *
 * Note since this is not a BST, need to handle 2 cases      *
 * Check https://github.com/prashrock/CPP/blob/master/tree/binary_tree.h#L369 *
 * for more documentation                                    *
 */
TreeNode* bt_lca(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode *lhs = NULL, *rhs = NULL;
	if(root == NULL || p == NULL || q == NULL)  return NULL;
	else if(root == p || root == q)             return root;
	if(root->left)  lhs = bt_lca(root->left, p, q);
	if(root->right) rhs = bt_lca(root->right, p, q);
	if(lhs && rhs) return root;
	else if(lhs)   return lhs;
	else           return rhs;
}


/**
 * @brief Recursive approach to find LCP of BST              *
 * @param root = current node of BST.                        *
 * @param p, q = Nodes known to be in BST, whose LCA we want *
 * @ret   LCA node pointer                                   *
 */
TreeNode* bst_lca(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL || p == NULL || q == NULL)  return NULL;
	else if(root->val > p->val && root->val > q->val)
		return bst_lca(root->left, p, q);
	else if(root->val < p->val && root->val < q->val)
		return bst_lca(root->right, p, q);
	else return root;
}


	
int main()
{
	cout << "Implement LCP test-cases" << endl;
	return 0;
}
