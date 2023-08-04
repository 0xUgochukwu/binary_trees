#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *	   NULL If no common ancestor was found
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t f_depth, s_depth;

	if (!first || !second)
		return (NULL);

	f_depth = binary_tree_depth(first);
	s_depth = binary_tree_depth(second);

	while (f_depth > s_depth)
	{
		first = first->parent;
		f_depth--;
	}

	while (s_depth > f_depth)
	{
		second = second->parent;
		s_depth--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}



/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth or 0 If tree is NULL
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree && tree->parent)
	{
		depth += (1 + binary_tree_depth(tree->parent));
		return (depth);
	}

	return (0);
}
