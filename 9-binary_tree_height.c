#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @root: Pointer to the root node of the tree.
 *
 * Return: Height of the tree. 0 if root is NULL.
 */
size_t binary_tree_height(const binary_tree_t *root)
{
	size_t left_height = 0, right_height = 0;

	if (!root)
		return (0);
	left_height = root->left ? 1 + binary_tree_height(root->left) : 0;
	right_height = root->right ? 1 + binary_tree_height(root->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
