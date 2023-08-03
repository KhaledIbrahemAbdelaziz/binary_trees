#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node
 * as the left-child of another node.
 * @parent: a pointer to the node to insert the left-child in.
 * @value: the value to store in the new node.
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);
	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	if (parent->left == NULL)
	{
		parent->left = newnode;
		newnode->right = NULL;
		newnode->left = NULL;
		newnode->parent = parent;
		newnode->n = value;
	}
	else if (parent->left != NULL)
	{
		newnode->left = parent->left;
		parent->left = newnode;
		newnode->right = NULL;
		newnode->parent = parent;
		newnode->left->parent = newnode;
		newnode->n = value;
	}
	return (newnode);
}
