#ifndef HASHMAP_FUNC_H
# define HASHMAP_FUNC_H

t_hashmap	*hashmap_init(void);
t_hashmap	*hashmap_add(t_hashmap *hashmap, t_pair *pair);
t_hashmap	*hashmap_del(t_hashmap *hashmap, t_pair *pair);

t_pair		*hashmap_find(t_hashmap *hashmap, char *key);

#endif
