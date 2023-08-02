#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes on a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: nodes of the tree or 0 If tree is NULL
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		if (tree->right || tree->left)
			nodes++;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}

	return (nodes);
}
