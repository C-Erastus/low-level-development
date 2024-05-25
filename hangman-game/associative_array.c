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
}
