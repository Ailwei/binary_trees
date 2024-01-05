#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes in a binary tree.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common ancestor was found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	
	/* Create arrays to store ancestors of each node */
	binary_tree_t **ancestors_first = NULL;
	binary_tree_t **ancestors_second = NULL;
	
	/* Get ancestors of the first node */
	int count_first = 0;
	const binary_tree_t *temp = first;
	while (temp != NULL)
	{
		count_first++;
		temp = temp->parent;
	}
	ancestors_first = malloc(count_first * sizeof(binary_tree_t *));
	if (ancestors_first == NULL)
		return (NULL);
	temp = first;
	for (int i = 0; i < count_first; i++)
	{
		ancestors_first[i] = (binary_tree_t *)temp;
		temp = temp->parent;
	}
	/* Get ancestors of the second node */
	int count_second = 0;
	temp = second;
	while (temp != NULL)
	{
		count_second++;
		temp = temp->parent;
	}
	ancestors_second = malloc(count_second * sizeof(binary_tree_t *));
	if (ancestors_second == NULL)
	{
		free(ancestors_first);
		return (NULL);
	}
	temp = second;
	for (int i = 0; i < count_second; i++)
	{
		ancestors_second[i] = (binary_tree_t *)temp;
		temp = temp->parent;
	}
	/* Find the lowest common ancestor */
	binary_tree_t *lowest_common_ancestor = NULL;
	for (int i = 0; i < count_first; i++)
	{
		for (int j = 0; j < count_second; j++)
		{
			if (ancestors_first[i] == ancestors_second[j])
			{
				lowest_common_ancestor = ancestors_first[i];
				break;
			}
		}
		if (lowest_common_ancestor != NULL)
			break;
	}
	/* Free allocated memory */
	free(ancestors_first);
	free(ancestors_second);
	return (lowest_common_ancestor);
}
