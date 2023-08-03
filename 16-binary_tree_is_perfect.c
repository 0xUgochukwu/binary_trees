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
 * _size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree or 0 If tree is NULL
 *
 */
size_t _size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		count += _size(tree->left);
		count += _size(tree->right);
		count++;
	}

	return (count);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 *
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect_size, actual_size;

	perfect_size = (1 << (int)_height(tree)) - 1;
	actual_size = (int)_size(tree);

	return (perfect_size == actual_size);
}
