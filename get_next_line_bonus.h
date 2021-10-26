#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define OPEN_MAX 20	// TO DELETE!!!

typedef struct s_buff
{
	char	arr[BUFFER_SIZE];
	size_t	next_char_idx;
	ssize_t	readed_left;
}	t_buff;

typedef struct s_list
{
	char			arr[BUFFER_SIZE];
	size_t			len;
	struct s_list	*next;
}	t_list;

typedef struct s_result
{
	char	*arr;
	size_t	size;
}	t_result;

t_list	*new_list(void);
void	free_list_elem(t_list *elem);
t_list	*push_back_list(t_list *elem);
void	free_list(t_list **list);
char	*get_next_line(int fd);

#endif