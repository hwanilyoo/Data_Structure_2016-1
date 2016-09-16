#include<stdio.h>
#include<stdlib.h>
void MSort(int A[], int TmpArray[], int Left, int Right);
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd);
int main() {

	int a[12], b[12];
	int i;
	printf("Before Sorting : ");
	for (i = 0; i < 12; i++) {
		scanf("%d",&a[i]);
	}

	MSort(a, b, 0, 11);
	printf("After Sorting : ");
	for (i = 0; i < 12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void MSort(int A[], int TmpArray[], int Left, int Right) {
	int center;
	if (Left < Right) {
		center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, center);
		MSort(A, TmpArray, center+1, Right);
		Merge(A, TmpArray, Left, center + 1, Right);
	}
}

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElement, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElement = RightEnd - Lpos + 1;

	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];

	while (Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	for (i = 0; i < NumElement; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];
}