#include <lst.h>

void	*push_front(t_lst *lst, t_lst *elem)
{
	elem->next = lst;
	lst = elem;
	return (lst);
}

void	*push_back(t_lst *lst, t_lst *elem)
{
	t_lst	*tmp;

	if (!(tmp = lst))
		return (elem);
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (lst);
}
