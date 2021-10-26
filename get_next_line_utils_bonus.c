#include "get_next_line.h"

t_list	*new_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->len = 0;
	new->next = NULL;
	return (new);
}

t_list	*push_back_list(t_list *elem)
{
	if (!elem)
		return (NULL);
	elem->next = new_list();
	return (elem->next);
}

void	free_list_elem(t_list *elem)
{
	if (!elem)
		return ;
	free(elem);
}

void	free_list(t_list **list)
{
	t_list	*current;
	t_list	*prev;

	if (!*list)
		return ;
	current = *list;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		free_list_elem(prev);
	}
	free_list_elem(current);
	*list = NULL;
}
