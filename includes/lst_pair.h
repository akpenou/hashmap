#ifndef LST_PAIR_H
# define LST_PAIR_H

# include <stdlib.h>

typedef struct			s_pair
{
	struct s_pair		*next;
	char				*key;
	void				*value;
}						t_pair;

void	*pair_insert(t_pair *lst, t_pair *pair);
void	*pair_find(t_pair *lst, char *key);
void	*pair_del(t_pair *lst, char *key);

#endif
