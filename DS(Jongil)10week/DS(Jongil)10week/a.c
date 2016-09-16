#include<stdio.h>
#include<stdlib.h>
typedef struct _TreeNode TreeNode;
struct _TreeNode {
	int data;
	TreeNode* leftChild;
	TreeNode* rightChild;
};
TreeNode* createTreeNode(int value);
void insertTreeNode(TreeNode** p, int value);
void preorder(TreeNode* tree);
void inorder(TreeNode* tree);
void postorder(TreeNode* tree);

int main() {
	TreeNode* tree = NULL;
	insertTreeNode(&tree, 4);
	insertTreeNode(&tree, 2);
	insertTreeNode(&tree, 6);
	insertTreeNode(&tree, 1);
	insertTreeNode(&tree, 3);
	insertTreeNode(&tree, 5);
	insertTreeNode(&tree, 7);
	printf("Preorder : \n");
	preorder(tree);
	printf("\n");

	printf("Inorder : \n");
	inorder(tree);
	printf("\n");

	printf("Postrder : \n");
	postorder(tree);
	printf("\n");
	return 0;
}

TreeNode* createTreeNode(int value) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = value;
	node->leftChild = NULL;
	node->rightChild = NULL;
	
	return node;
}

void insertTreeNode(TreeNode** p, int value) {
	if ((*p) == NULL) {
		(*p) = createTreeNode(value);
	}
	else if ((*p)->data > value) {
		insertTreeNode(&((*p)->leftChild), value);
	}
	else if ((*p)->data < value) {
		insertTreeNode(&((*p)->rightChild), value);
	}
}

void preorder(TreeNode* tree) {
	if (tree) {
		printf("%d ", tree->data);
		preorder(tree->leftChild);
		preorder(tree->rightChild);
	}
}

void inorder(TreeNode* tree) {
	if (tree) {
		inorder(tree->leftChild);
		printf("%d ", tree->data);
		inorder(tree->rightChild);
	}
}

void postorder(TreeNode* tree) {
	if (tree) {
		postorder(tree->leftChild);
		postorder(tree->rightChild);
		printf("%d ", tree->data);
	}
}