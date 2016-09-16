#include<stdio.h>
#include<stdlib.h>

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	short int rightThread;
};
void insertLeft(threadedPointer s, threadedPointer r);
void inorder(threadedPointer tree);
threadedPointer insucc(threadedPointer tree);
threadedPointer makeTree();

int main() {
	char command,n;
	
	threadedPointer tree = makeTree();
	threadedPointer temp;

	while (1) {
		scanf("%c",&command);
		switch(command) {
			case 'i':
				scanf("%c",&n);
				printf("'%c'가 입력됩니다.\n",n);
				temp = makeTree();
				temp->data = n;
				insertLeft(tree, temp);
				break;
			
			case 'p':
				printf("출력합니다.(내림차순)\n");
				inorder(tree);
				printf("\n");
				break;
			
			case 'q':
				return 0;
				
		}
	}
	
}

threadedPointer insucc(threadedPointer tree) {

	threadedPointer temp;
	temp = tree->leftChild;
	if (!temp){
		while (!temp->rightThread)
			temp = temp->rightChild;
	}
	
	return temp;
		
}

void inorder(threadedPointer tree) {
	threadedPointer temp = tree;
	while (!temp->leftThread) {
		temp = temp->leftChild;
		printf("%3c", temp->data);
	}
}


void insertLeft(threadedPointer s, threadedPointer r) {
	threadedPointer temp;
	r->leftChild = s->leftChild;
	r->leftThread = s->leftThread;
	r->rightChild = s;
	r->rightThread = 1;
	s->leftChild = r;
	s->leftThread = 0;
	if (!r->leftThread) {
		temp = insucc(r);
		temp->rightChild = r;
	}
}

threadedPointer makeTree() {
	threadedPointer tree = (threadedPointer)malloc(sizeof(struct threadedTree));
	tree->leftThread = 1;
	tree->rightThread = 0;
	tree->leftChild = tree;
	tree->rightChild = tree;

	return tree;
}