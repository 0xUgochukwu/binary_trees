#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves on a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: leaves of the tree or 0 If tree is NULL
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree && (tree->right || tree->left))
	{
		count += binary_tree_leaves(tree->left);
		count += binary_tree_leaves(tree->right);
		count++;
	}

	return (count);
}
