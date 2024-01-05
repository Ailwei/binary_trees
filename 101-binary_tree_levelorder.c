#include "binary_trees.h"


/**
 * binary_tree_levelorder - Traverses a binary tree using level-order travers.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Use a queue for level-order traversal */
	binary_tree_t **queue = NULL;
	int front = 0, rear = 0;

	/* Allocate space for the queue */
	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return;

	/* Enqueue the root node */
	queue[rear++] = (binary_tree_t *)tree;

	/* Perform level order traversal */
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* Call the function for the current node */
		func(current->n);

		/* Enqueue left and right children if they exist */
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	/* Free the allocated queue */
	free(queue);
}
