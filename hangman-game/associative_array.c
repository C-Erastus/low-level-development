#include <stdio.h>
#include <stdlib.h>
#include "associative_array.h"

/*struct node {
	Item key = my_string_init_default(); 
	struct node *left;
	struct node *right; 
	int height; 
	int key_count;
};*/

struct node *insert_node(struct node *Node, Item key, Item My_string)
{
	int balance; 

	if(Node == NULL)
		return (new_node(key, My_string));

	if((my_string_compare(key, Node->key) < 0))
		Node->left = insert_node(Node->left, key, My_string);
	else if ((my_string_compare(key, Node->key) > 0))
		Node->right = insert_node(Node->right, key, My_string);
	else{
		Node->key_count++;
		generic_vector_push_back(Node->ar_vector, My_string);
		return Node; 
	}

	/* Update the balance factor */
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

struct node *new_node(Item key, Item My_string)
{
	struct node *Node = (struct node *)malloc(sizeof(struct node));

	Node->key = NULL;
	my_string_assignment(&Node->key, key);
	Node->ar_vector = generic_vector_init_default(
		my_string_assignment,
		my_string_destroy
	);
	generic_vector_push_back(Node->ar_vector, My_string);

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

	x->right = y;
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
		
		print_preorder(root->left);
		printf("%s %d\n", my_string_c_str(root->key), root->key_count);
		print_preorder(root->right);
	}
}

struct node* get_common_word_family(struct node *root)
{

	if(root == NULL)
		return NULL; 
	struct node *max_node = root; 
	struct node *left_max = get_common_word_family(root->left);
	struct node *right_max = get_common_word_family(root->right);

	if(left_max != NULL && left_max->key_count > max_node->key_count)
		max_node = left_max; 
	if(right_max != NULL && right_max->key_count > max_node->key_count)
		max_node = right_max; 

	return max_node;
}