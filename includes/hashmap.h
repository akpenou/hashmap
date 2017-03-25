#ifndef HASHMAP_H
# define HASHMAP_H

# define get16bits(d) (*((const short unsigned int *) (d)))

# include <stdlib.h>
# include <stdio.h>

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
	t_pair				**mem;
}						t_hashmap;

typedef struct			s_lst
{
	struct s_lst		*next;
}						t_lst;

// HASH
unsigned int superfasthash(char *key);

// LIST
void	*push_front(t_lst *lst, t_lst *elem);
void	*push_back(t_lst *lst, t_lst *elem);

// HASHMAP
t_hashmap	*hashmap_init(void);
t_hashmap	*hashmap_add(t_hashmap *hashmap, t_pair *pair);
t_hashmap	*hashmap_del(t_hashmap *hashmap, t_pair *pair);


t_pair		*hashmap_find(t_hashmap *hashmap, char *key);

// TOOLS
int		ft_strcmp(char *a, char *b);


// PAIR
void	*pair_insert(t_pair *lst, t_pair *pair);
void	*pair_find(t_pair *lst, char *key);
void	*pair_del(t_pair *lst, char *key);

#endif
