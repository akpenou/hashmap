#ifndef HASHMAP_H
# define HASHMAP_H

# define get16bits(d) (*((const short unsigned int *) (d)))

# include <stdlib.h>

typedef struct			s_pair
{
	struct s_pair		*next;
	char				*key;
	void				*value;
}						t_pair;

typedef struct			s_hashmap
{
	unsigned int		nb_elements;
	unsigned int		nb_buckets;
	unsigned int		shift;
	t_pair				*mem;
}						t_hashmap;

unsigned int superfasthash(char *key);

#endif
