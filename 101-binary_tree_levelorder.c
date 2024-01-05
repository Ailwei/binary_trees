#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = 0, right_height = 0;

		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * print_at_level - Prints nodes at a specific level.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Level to print.
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree in level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height = 0, current_level = 1;

	if (tree && func)
	{
		tree_height = binary_tree_height(tree);
		while (current_level <= tree_height + 1)
		{
			print_at_level(tree, func, current_level);
			current_level++;
		}
	}
}
