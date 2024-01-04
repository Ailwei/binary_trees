#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves in the tree. If tree is NULL, return 0.
 */


size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right_leave, left_leave;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	left_leave = binary_tree_leaves(tree->left);
	right_leave = binary_tree_leaves(tree->right);
	return (left_leave + right_leave);
}
