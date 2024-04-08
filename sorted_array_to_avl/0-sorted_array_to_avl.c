#include "binary_trees.h"

/**
 * build_avl_tree - Builds an AVL tree from a sorted array
 *
 * @array: The array to be converted
 * @start: The start index of the array
 * @end: The end index of the array
 * @parent: The parent node
 *
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node = NULL;
	int mid = 0;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->n = array[mid];
	new_node->parent = parent;
	new_node->left = build_avl_tree(array, start, mid - 1, new_node);
	new_node->right = build_avl_tree(array, mid + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: The array to be converted
 * @size: Size of the array
 *
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array || size < 1)
		return (NULL);

	tree = build_avl_tree(array, 0, size - 1, NULL);
	return (tree);
}
