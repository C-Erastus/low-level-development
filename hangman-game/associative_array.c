#include <stdio.h>
#include <stdlib.h>
#include "associative_array.h"

struct node {
	Item key; 
	struct node *left;
	struct node *right; 
	int height; 
	int key_count;
};

struct node *insert_node(struct node *Node, Item key)
{
	int balance; 

	if(Node == NULL)
		return (new_node(key));

	if((my_string_compare(key, Node->key) == -1))
		Node->left = insert_node(Node->left, key);
	else if ((my_string_compare(key, Node->key) == 1))
		Node->right = insert_node(Node->right, key);
	else{
		Node->key_count+=1;
		return Node; 
	}

	/* Update the balnce factor */
	Node->height = 1 + max(height(Node->left), height(Node->right));

	balance = get_balance(Node);
	if (balance > 1 && (my_string_compare(key, Node->left->key)) == -1)
		return right_rotate(Node);

	if (balance < -1 && (my_string_compare(key, Node->right->key)) == 1)
		return left_rotate(Node);

	if (balance > 1 && (my_string_compare(key, Node->left->key)) == 1){
		Node->left = left_rotate(Node->left);
		return right_rotate(Node);
	}

	if (balance < -1 && (my_string_compare(key, Node->right->key)) == -1){
		Node->right = right_rotate(Node->right);
		return left_rotate(Node);
	}

	return Node;
}

struct node *new_node(Item key)
{
	struct node *Node = (struct node *)malloc(sizeof(struct node));
	
	Node->key = key; 
	Node->left = NULL;
	Node->right = NULL; 
	Node->height = 1; 
	Node->key_count = 1;

	return (Node);
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
	struct node *x = y->left; 
	struct node *T2 = x->right;

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

void print_preorder(struct node *root)
{
	if(root != NULL){
		printf("%s %d", my_string_c_str(root->key), root->key_count);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}