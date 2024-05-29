#include <stdlib.h>
#include "binary_trees.h"

/**
 * BTQueuePush - Push a new node to the back of the queue
 * @queue: Pointer to the head of the queue
 * @node: Pointer to the binary tree node to be pushed
 *
 * Return: Pointer to the newly pushed node
*/
bt_node_queue_t *BTQueuePush(bt_node_queue_t **queue, binary_tree_t *node)
{
	bt_node_queue_t *new_node = malloc(sizeof(bt_node_queue_t));

	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (!*queue)
	{
		*queue = new_node;
	}
	else
	{
		bt_node_queue_t *temp = *queue;

		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}

/**
 * BTQueuePop - Pop the front node from the queue
 * @queue: Pointer to the head of the queue
*/
void BTQueuePop(bt_node_queue_t **queue)
{
	bt_node_queue_t *temp;

	if (!queue || !*queue)
		return;

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}

/**
 * lastInLevelOrder - Find the last node in level order traversal
 * @root: Pointer to the root node of the binary tree
 *
 * Return: Pointer to the last node in level order traversal
*/
heap_t *lastInLevelOrder(heap_t *root)
{
	bt_node_queue_t *queue = NULL;
	heap_t *last = NULL;

	if (!root)
		return (NULL);

	if (!BTQueuePush(&queue, (binary_tree_t *)root))
		return (NULL);

	while (queue)
	{
		heap_t *current = (heap_t *)queue->node;

		if (current->left && !BTQueuePush(&queue, (binary_tree_t *)current->left))
			break;

		if (current->right && !BTQueuePush(&queue, (binary_tree_t *)current->right))
			break;

		last = current;
		BTQueuePop(&queue);
	}

	while (queue)
		BTQueuePop(&queue);

	return (last);
}

/**
 * maxHeapSiftDown - Sift down the root node to maintain the Max Binary Heap
 * @root: Pointer to the root node of the binary tree
*/
void maxHeapSiftDown(heap_t *root)
{
	while (root)
	{
		heap_t *largest = root;
		int temp;

		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;

		root = largest;
	}
}

/**
 * heap_extract - Extract the root node from a Max Binary Heap
 * @root: Pointer to the root node of the binary tree
 * Return: The value of the extracted node
*/
int heap_extract(heap_t **root)
{
	heap_t *root_node;
	heap_t *last;
	int extracted_value;

	if (!root || !*root)
		return (0);

	root_node = *root;
	extracted_value = root_node->n;
	last = lastInLevelOrder(root_node);

	if (!last)
		return (0);

	root_node->n = last->n;

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}

	free(last);

	if (*root)
		maxHeapSiftDown(*root);

	return (extracted_value);
}
