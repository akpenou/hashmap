#ifndef LST_H
# define LST_H

typedef struct			s_lst
{
	struct s_lst		*next;
}						t_lst;

void	*push_front(t_lst *lst, t_lst *elem);
void	*push_back(t_lst *lst, t_lst *elem);

#endif
