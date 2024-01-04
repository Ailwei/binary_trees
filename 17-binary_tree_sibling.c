#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 *
 * Return: A pointer to the sibling node, or NULL if node is NULL,
 * the parent is NULL, or node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	binary_tree_t *parent = node->parent;

	if (parent->left == NULL || parent->right == NULL)
		return (NULL);
	if (node == parent->left)
		return (parent->right);
	else
		return (parent->left);
}
