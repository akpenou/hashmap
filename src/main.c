#include <hashmap.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	while (++i < ac)
		printf("%X\n", superfasthash(av[i]) >> (32 - 5));
	return (0);
}
