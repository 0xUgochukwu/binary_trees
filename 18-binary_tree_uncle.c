#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return:  pointer to the uncle node
 *	If node is NULL, return NULL
 *	If node has no uncle, return NULL
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent = node->parent;


	if (parent->parent->left == parent)
		return (parent->right);
	else
		return (parent->left);
}
