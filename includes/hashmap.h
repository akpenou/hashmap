#ifndef HASHMAP_H
# define HASHMAP_H

typedef struct			s_pair
{
	char				*key;
	void				*value;
	struct s_pair		*next;
}						t_pair;

#endif
