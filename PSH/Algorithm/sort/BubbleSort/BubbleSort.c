#include <stdio.h>

int BubbleSort(int DataSet[], int Length)
{
	int i = 0;
	int end = Length -1;
	int temp = 0;
	int count = 0;
	int	lastSwap;

	while (end > 0)
	{
		lastSwap = 0;
		for (i = 0; i < Length - 1; i++)
		{
			++count;
			if (DataSet[i] > DataSet[i + 1])
			{
				temp = DataSet[i];
				DataSet[i] = DataSet[i + 1];
				DataSet[i + 1] = temp;
				lastSwap = i;
			}
		}
		if (lastSwap == 0)
			break ;
		end = lastSwap;
	}
	return count;
}

int main(void)
{
	int DataSet[] = {1, 2, 3, 4, 5, 6};
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	int count = BubbleSort(DataSet, Length);
	printf("count: %d\n", count);
	for (i = 0; i < Length; i++)
		printf("%d ", DataSet[i]);
	printf("\n");
	return (0);
}
