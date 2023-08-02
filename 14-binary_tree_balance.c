#include "binary_trees.h"


/**
 * _height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree or 0 If tree is NULL
 *
 */

size_t _height(const binary_tree_t *tree)
{
	size_t l_len = 0, r_len = 0;


	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l_len += (_height(tree->left) + 1);
	r_len += (_height(tree->right) + 1);

	if (l_len > r_len)
		return (l_len);
	else
		return (r_len);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor or 0 If tree is NULL
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (!tree)
		return (0);

	h_left = tree->left ? (int)_height(tree->left) : -1;
	h_right = tree->right ? (int)_height(tree->right) : -1;

	return (h_left - h_right);
}
