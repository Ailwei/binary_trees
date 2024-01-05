#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @node: Pointer to the node to measure the depth.
 *
 * Return: If node is NULL, the function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(node->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: First node.
 * @second: Second node.
 *
 * Return: Lowest common ancestor or NULL if none found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t height_first = 0, height_second = 0;
	const binary_tree_t *temp = NULL;

	height_first = binary_tree_depth(first);
	height_second = binary_tree_depth(second);
	if (height_first && height_second)
	{
		if (height_first > height_second)
		{
			temp = first;
			first = second;
			second = temp;
		}
		while (first)
		{
			temp = second;
			while (temp)
			{
				if (first == temp)
					return ((binary_tree_t *)first);
				temp = temp->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}

