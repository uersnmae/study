#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	comparepoint(const void *_elem1, const void *_elem2)
{
	int	*elem1 = (int *)_elem1;
	int	*elem2 = (int *)_elem2;

	if (*elem1 > *elem2)
		return (1);
	else if (*elem1 < *elem2)
		return (-1);
	else
		return (0);
}

int	comparepointdescend(const void *_elem1, const void *_elem2)
{
	int	*elem1 = (int *)_elem1;
	int	*elem2 = (int *)_elem2;

	if (*elem1 > *elem2)
		return (-1);
	else if (*elem1 < *elem2)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int dataset[] = {6, 4, 2, 3, 1, 5};
	int length = sizeof(dataset) / sizeof(dataset[0]);
	int i = 0;

	qsort((void *)dataset, length, sizeof(int), comparepoint);
	for (i = 0; i < length; i++)
		printf("%d ", dataset[i]);
	printf("\n");
	qsort((void *)dataset, length, sizeof(int), comparepointdescend);
	for (i = 0; i < length; i++)
		printf("%d ", dataset[i]);
	printf("\n");
	return (0);
}
