#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *node, *last;

    if (!root || !*root)
        return (0);

    node = *root;
    value = node->n;

    if (!node->left && !node->right)
    {
        *root = NULL;
        free(node);
        return (value);
    }

    last = get_last_node(*root);
    swap_nodes(node, last);

    if (last->parent->left == last)
        last->parent->left = NULL;
    else
        last->parent->right = NULL;

    free(last);
    heapify(*root);

    return (value);
}

/**
 * get_last_node - gets the last node in a binary heap
 * @root: pointer to the root node of the heap
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    queue_t *queue = NULL, *temp;
    heap_t *node = NULL;

    if (!root)
        return (NULL);

    queue = create_queue(root);
    while (queue)
    {
        node = dequeue(&queue);
        if (node->left)
            enqueue(&queue, node->left);
        if (node->right)
            enqueue(&queue, node->right);
    }

    while (queue)
    {
        temp = queue;
        queue = queue->next;
        free(temp);
    }

    return (node);
}

/**
 * heapify - rebalances a Max Binary Heap
 * @root: pointer to the root node of heap
 */
void heapify(heap_t *root)
{
    heap_t *largest;
    int temp;

    if (!root)
        return;

    largest = root;
    if (root->left && root->left->n > root->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root)
    {
        temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify(largest);
    }
}

/**
 * swap_nodes - swaps two nodes in a binary heap
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
    int temp;

    temp = a->n;
    a->n = b->n;
    b->n = temp;
}
