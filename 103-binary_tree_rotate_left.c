#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 *
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree || !tree->right)
		return (NULL);

	tmp = tree->right;
	tmp->parent = NULL;
	tree->parent = tmp;
	tree->right = tmp->left;
	if (tmp->left)
		tree->right->parent = tree;
	tmp->left = tree;

	return (tree);
}
