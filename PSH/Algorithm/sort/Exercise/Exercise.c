#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Point.h"

int	comparepoint(const void *_elem1, const void *_elem2)
{
	Point	*elem1 = (Point	*)_elem1;
	Point	*elem2 = (Point	*)_elem2;

	if (elem1->point > elem2->point)
		return (1);
	else if (elem1->point < elem2->point)
		return (-1);
	else
		return (0);
}

int	comparepointdescend(const void *_elem1, const void *_elem2)
{
	Point	*elem1 = (Point	*)_elem1;
	Point	*elem2 = (Point	*)_elem2;

	if (elem1->point > elem2->point)
		return (-1);
	else if (elem1->point < elem2->point)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int length = sizeof(DataSet) / sizeof(DataSet[0]);

	printf("%d\n", DataSet[14141].id);
	qsort((void *)DataSet, length, sizeof(Point), comparepointdescend);
	printf("%d\n", DataSet[14141].id);
	return (0);
}
