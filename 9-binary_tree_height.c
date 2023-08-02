#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree or 0 If tree is NULL
 *
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_len = 0, r_len = 0;


	if (!tree)
		return (0); 

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	l_len += (binary_tree_height(tree->left) + 1);
	r_len += (binary_tree_height(tree->right) + 1);

	if (l_len > r_len)
		return (l_len);
	else
		return (r_len);
}
