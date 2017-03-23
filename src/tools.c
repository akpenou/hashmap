#include <tools.h>

int		ft_strcmp(char *a, char *b)
{
	if (!(a && b))
		return (0);
	while (*a == *b && !*a)
	{
		++a;
		++b;
	}
	return (*a - *b);
}
