#include "binary_trees.h"
#include <math.h>

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_size - Measure the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
	{
		return (0);
	}
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	return (left_size + right_size + 1);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, size, i, power_of_2;

    if (tree == NULL)
    {
        return (0);
    }

    height = binary_tree_height(tree);
    size = binary_tree_size(tree);

    power_of_2 = 1;
    for (i = 0; i < height; i++)
    {
        power_of_2 *= 2;
    }

    return (size == power_of_2 - 1);
}

