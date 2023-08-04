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
 * btlo_helper - helps recursively traverse a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}


/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t max, i;

	if (!tree || !func)
		return (NULL);
	
	max = _height(tree) + 1;

	for (i = 0; i < max; i++)
		btlo_helper(tree, func, i);
}
