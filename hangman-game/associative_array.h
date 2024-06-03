#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRY_H

#include "my_string.h"
#include "generic_vector.h"
struct node {
	Item key;
	GENERIC_VECTOR ar_vector;
	struct node *left;
	struct node *right; 
	int height; 
	int key_count;
};


struct node *insert_node( struct node *Node, Item key, Item My_string);

struct node *new_node(Item key, Item My_string);

int height(struct node *Node);

int max(int a, int b);

//struct node *new_node(Item key);

int get_balance(struct node *Node);

struct node *right_rotate(struct node *y);

struct node *left_rotate(struct node *x);

void print_preorder(struct node* root);

struct node* get_common_word_family(struct node *root);



/*struct node *min_value_node(struct node *node);

struct node *delete_node(struct node *root, Item key);*/

#endif
