#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRY_H

#include "my_string.h"

struct node *insert_node( struct node *Node, Item key);

struct node *new_node(Item key);

int height(struct node *Node);

int max(int a, int b);

struct node *new_node(Item key);

int get_balance(struct node *Node);

struct node *right_rotate(struct node *y);

struct node *left_rotate(struct node *x);

void print_preorder(struct node* root);
/*struct node *min_value_node(struct node *node);

struct node *delete_node(struct node *root, Item key);*/

#endif
