#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert to the right of node
 * @parent: node to insert in
 * @value: value to store in the new node
 * Return: a pointer to the created node, or NULL
 * on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (parent == NULL)
		return (NULL);

	right_node = malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);

	right_node->n = value;
	right_node->left = NULL;
	right_node->right = parent->right;
	right_node->parent = parent;
	if (parent->right)
		parent->right->parent = right_node;
	parent->right = right_node;

	return (right_node);
}
