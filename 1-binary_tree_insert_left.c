#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert to the left of node
 * @parent: node to insert in
 * @value: value to store in the new node
 * Return: a pointer to the created node, or NULL
 * on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left = malloc(sizeof(binary_tree_t));

	if (!left || !parent)
		return (NULL);

	left->n = value;
	left->right = NULL;
	left->left = NULL;
	left->parent = parent;
	parent->left = left;

	return (left);


}
