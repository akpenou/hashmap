#include <hashmap.h>
#include <hashmap_func.h>

t_hashmap	*hashmap_init(void)
{
	t_hashmap	*hashmap;

	if (!(hashmap = (t_hashmap *)malloc(sizeof(t_hashmap))))
		return (NULL);
	hashmap->nb_elements = 0;
	hashmap->shift = (32 - 8);
	hashmap->nb_buckets = ((1 << 33) - 1) >> hashmap->shift;
	if (!(hashmap->mem = (t_hashmap *)malloc(sizeof(t_pair) * hashmap->nb_buckets)))
	{
		free(hashmap);
		return (0);
	}
	return (hashmap);
}

t_hashmap	*hashmap_add_elem(t_hashmap *hashmap, t_pair *pair)
{
	hashmap->nb_elements++;
	if ((hashmap->nb_elements >> 2) >= hashmap->nb_buckets && hashmap->shift > 0)
	{
		hashmap->shift -= 8;
		hashmap->nb_buckets = ((1 << 33) - 1) >> hashmap->shift;
		if (!(hashmap->mem = (t_hashmap *)realloc(sizeof(t_pair) * hashmap->nb_buckets)))
			return (NULL);
	}
	index = superfasthash(pair->key) >> hashmap->shift;
	hashmap->mem[index] = pair_insert(hashmap->mem[index], pair);
	return (hashmap);
}

t_hashmap	*hashmap_del_elem(t_hashmap *hashmap, t_pair *pair)
{
	hashmap->nb_elements--;
	index = superfasthash(pair->key) >> hashmap->shift;
	hashmap->mem[index] = pair_del(hashmap->mem[index], pair);
	return (hashmap);
}

t_pair		*hashmap_find(t_hashmap *hashmap, char *key)
{
	index = superfasthash(pair->key) >> hashmap->shift;
	return (pair_find(hashmap->mem[index], pair));
}
