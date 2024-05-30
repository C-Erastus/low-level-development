#include <stdio.h>
#include <stdlib.h>
#include "associative_array.h"

struct node {
	Item key; 
	struct node *left;
	struct node *right; 
	int height; 
};

struct node *insert_node(struct node *Node, Item key)
{
	int balance; 

	if(Node == NULL)
		return (new_node(key));

	if(my_string_compare(key, node->key) == -1)
		node->left = insert_node(node->left, key);
	else if ((my_string_compare(key > node-Key)) == 1)
		node->right = insert_node(node->right, key);
	else
		return node; 

	/* Update the balnce factor */
	Node->right = 1 + max(height(Node->left), height(Node->right));

	balance = getBallance(Node);
	if (balance > 1 && (my_string_compare(key, Node->left->key)) == -1)
		return right_rotate(Node);

	if (balance < -1 && (my_string_compare(key, Node->right->key)) == 1)
		return left_rotate(Node);

	if (balance > 1 && (my_string_compare(key, Node->left->key)) == 1){
		Node->left = left_rotate(Node->left);
		return right_rotate(Node);
	}

	if (balance < -1 && (my_string_compare(key, Node->right->key)) == -1){
		node->right = right_rotate(Node->right);
		return left_rotate(Node);
	}

	return Node;
}

struct node *new_node(Item key)
{
	struct node *Node = (struct node *)malloc(sizeof(struct node));
	
	Node->key = key; 
	Node->left = NULL: 
	Node->right = NULL; 
	node->height = 1; 

	return (node);
}

int height(struct node *Node)
{
	if(Node == NULL)
		return 0; 
	return Node->height; 	
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int get_balance(struct node *Node)
{
	if (Node == NULL)
		return 0;
	return height(Node->left) - height(Node->right);
}

struct node *right_rotate(struct node *y)
{
	struct Node *x = y->left; 
	struct Node *T2 = x->right;

	y->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;	
}

struct node *left_rotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	y->left = x; 
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y; 
}