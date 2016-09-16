#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



typedef int MAX_SIZE;
MAX_SIZE Max_SIZE = 4096;
typedef enum { Head, Entry } tagField;

typedef struct matrixNode *matrixPtr;

typedef struct entryNode
{
	int row;
	int col;
	int value;
}entryNode;

typedef struct matrixNode
{
	matrixPtr down;
	matrixPtr right;
	tagField tag;
	union
	{
		matrixPtr next;
		entryNode entry;
	}u;
}matrixNode;

matrixPtr Hn[4096];

matrixPtr mread(void)
{
	int numRows, numCols, numTerms, numHeads, i;
	int row, col, value, current_row;
	matrixPtr temp, last, node;

	printf("Enter the number of rows, columns and number of nonzero terms : ");
	scanf("%d%d%d", &numRows, &numCols, &numTerms);
	numHeads = (numCols > numRows) ? numCols : numRows;
	node = (matrixPtr)malloc(sizeof(matrixNode));
	node->tag = Entry; // entryNode
	node->u.entry.row = numRows;
	node->u.entry.col = numCols;

	if (!numHeads) node->right = node;
	else {
		for (i = 0; i<numHeads; i++)
		{
			temp = (matrixPtr)malloc(sizeof(matrixNode));
			Hn[i] = temp; Hn[i]->tag = Head;
			Hn[i]->right = temp; Hn[i]->u.next = temp;
		}
	}
	current_row = 0;

	last = Hn[0];

	for (i = 0; i < numTerms; i++)
	{
		printf("Enter row, column and value : ");
		scanf("%d%d%d", &row, &col, &value);
		if (row > current_row) {
			last->right = Hn[current_row];
			current_row = row; last = Hn[row];
		}
		temp = (matrixPtr)malloc(sizeof(matrixNode));

		temp->tag = Entry;
		temp->u.entry.row = row;
		temp->u.entry.col = col;
		temp->u.entry.value = value;

		last->right = temp;
		last = temp;

		Hn[col]->u.next->down = temp;
		Hn[col]->u.next = temp;
	}

	last->right = Hn[current_row];
	for (i = 0; i<numHeads - 1; i++)
	{
		Hn[i]->u.next = Hn[i + 1];
		Hn[numHeads - 1]->u.next = node;
		node->right = Hn[0];
	}
	return node;
}
void merase(matrixPtr node)
{
	matrixPtr x, y, head = (node)->right;
	int i;
	for (i = 0; i< (node)->u.entry.row; i++)
	{
		y = head->right;
		while (y != head)
		{
			x = y, y = y->right; free(x);
		}
		x = head; head = head->u.next; free(x);
	}

	y = head;
	while (y != node) {
		x = y; y = y->u.next; free(x);
	}
	free(node); node = NULL;
}


void mwrite(matrixPtr node)
{
	int i;
	if (node != NULL) {
		matrixPtr temp, head = node->right;

		printf("\n num_rows = %d, num columns = %d\n", node->u.entry.row, node->u.entry.col);
		printf("The Matrix by row, column, and value: \n\n");
		temp = (matrixPtr)malloc(sizeof(matrixNode));

		for (i = 0; i<node->u.entry.row; i++)
		{
			for (temp = head->right; temp != head; temp = temp->right)
			{
				printf("%5d %5d %5d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
			}
			head = head->u.next;
		}
	}
	else printf("NULL Matrix !!\n");

}

int main()
{
	matrixPtr node;
	node = (matrixPtr)malloc(sizeof(matrixNode));
	int command = 0;

	while (command != 4)
	{
		puts("===============================================");
		puts("1. Insert Matrix");
		puts("2. Print Matrix");
		puts("3. Erase Matrix");
		puts("4. Exit Program");
		puts("===============================================");

		puts("==== Select Menu ? ");
		scanf("%d", &command);

		switch (command)
		{
		case 1:
			node = mread();
			break;
		case 2:
			mwrite(node);
			break;
		case 3:
			merase(node);
			break;
		case 4:
			break;
		}
	}
}











