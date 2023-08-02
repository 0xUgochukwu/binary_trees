#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves on a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: leaves of the tree or 0 If tree is NULL
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		if (!tree->right || !tree->left)
			leaves++;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}

	return (leaves);
}
