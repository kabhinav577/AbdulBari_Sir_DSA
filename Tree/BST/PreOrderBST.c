// A O(n) iterative program for construction of BST from preorder traversal
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
} Node;

typedef struct Stack
{
	int top;
	int capacity;
	Node* *array;
} Stack;

// A utility function to create a new tree node
Node* newNode( int data )
{
	Node* temp = (Node *)malloc( sizeof( Node ) );
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to create a stack of given capacity
Stack* createStack( int capacity )
{
	Stack* stack = (Stack *)malloc( sizeof( Stack ) );
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (Node **)malloc( stack->capacity * sizeof( Node* ) );
	return stack;
}

// A utility function to check if stack is full
int isFull( Stack* stack )
{
	return stack->top == stack->capacity - 1;
}

// A utility function to check if stack is empty
int isEmpty( Stack* stack )
{
	return stack->top == -1;
}

// A utility function to push an item to stack
void push( Stack* stack, Node* item )
{
	if( isFull( stack ) )
		return;
	stack->array[ ++stack->top ] = item;
}

// A utility function to remove an item from stack
Node* pop( Stack* stack )
{
	if( isEmpty( stack ) )
		return NULL;
	return stack->array[ stack->top-- ];
}

// A utility function to get top node of stack
Node* peek( Stack* stack )
{
	return stack->array[ stack->top ];
}

// constructs BST from pre[]
Node* constructTree ( int pre[], int size )
{
	Stack* stack = createStack( size );

	Node* root = newNode( pre[0] );

	push( stack, root );

	int i;
	Node* temp;

	// Iterate through rest of the size-1 items of given preorder array
	for ( i = 1; i < size; ++i )
	{
		temp = NULL;

		/* Keep on popping while the next value is greater than
		stack's top value. */
		while ( !isEmpty( stack ) && pre[i] > peek( stack )->data )
			temp = pop( stack );

		// Make this greater value as the right child
		// and push it to the stack
		if ( temp != NULL)
		{
			temp->right = newNode( pre[i] );
			push( stack, temp->right );
		}

		// If the next value is less than the stack's top
		// value, make this value as the left child of the
		// stack's top node. Push the new node to stack
		else
		{
			peek( stack )->left = newNode( pre[i] );
			push( stack, peek( stack )->left );
		}
	}

	return root;
}


// A utility function to print inorder traversal of a Binary Tree
void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
	int pre[] = {10, 5, 1, 7, 40, 50};
	int size = sizeof( pre ) / sizeof( pre[0] );

	Node *root = constructTree(pre, size);

	printf("Inorder traversal of the constructed tree: \n");
	printInorder(root);

	return 0;
}
