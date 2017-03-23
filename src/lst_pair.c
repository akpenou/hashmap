#include <lst_pair.h>

void	*pair_insert(t_pair *lst, t_pair *pair)
{
	t_pair	*tmp;

	if (!(tmp = lst))
		return (pair);
	if (ft_strcmp(pair->key, tmp->key) <= 0) // push front the pair if it's the lowest elem of the list
	{
		pair->next = tmp;
		return (pair);
	}
	while (tmp->next && ft_strcmp(pair->key, tmp->next->key) => 0) // move foreward until the key lower than tmp->next->key
		tmp = tmp->next;
	// insert the pair at the right place
	pair->next = tmp->next;
	tmp->next = pair;
	return (lst);
}

void	*pair_find(t_pair *lst, char *key)
{
	t_pair	*tmp;

	if ((tmp = lst))
		return (NULL);
	if (!ft_strcmp(key, tmp->key))
		return (tmp);
	while (tmp->next && ft_strcmp(key, tmp->next->key) > 0)
		tmp = tmp->next;
	if (!tmp->next || !ft_strcmp(key, tmp->next->key))
		return (tmp->next);
	return (NULL);
}

void	*pair_del(t_pair *lst, char *key)
{
	t_pair	*tmp;
	t_pair	*bis;

	if (!(tmp = lst))
		return (NULL);
	if (!ft_strcmp(tmp->key, key)) // del the first elem if it's equal to the key
	{
		tmp = tmp->next;
		free(lst);
		return (tmp);
	}
	while (tmp->next && ft_strcmp(key, tmp->next->key) > 0) // move foreward until the key lower or equal than tmp->next->key
		tmp = tmp->next;
	if (!tmp->next || ft_strcmp(key, tmp->next->key)) // if the tmp->next->key is not equal to the key the key doesn't exist
		return (lst);
	// free the pair and return a new list
	bis = tmp->next;
	tmp->next = tmp->next->next;
	free(bis);
	return (lst);
}
