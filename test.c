#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd) {
	static t_list *list = NULL;
	char *buffer;
	char *result = NULL;
	ssize_t bytes_read;
	t_list *new_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
		buffer[bytes_read] = '\0';
		new_node = ft_lstnew(ft_strdup(buffer));
		if (!new_node) {
			free(buffer);
			ft_lstclear(&list);
			return NULL;
		}
		ft_lstadd_back(&list, new_node);

		if (ft_strchr(buffer, '\n'))
			break;
	}

	free(buffer);  

	if (bytes_read < 0 || (bytes_read == 0 && !list))
		return NULL;

	result = join_list_contents(list);
	ft_lstclear(&list);

	return result;
}





------------------------------------------------------------------------
t_list *ft_lstnew(void *content) {
        t_list *node1;

        node1 = malloc(sizeof(t_list));
        if (!node1)
                return (NULL);
        node1->content = content;
        node1->next = NULL;
        return (node1);
}

void ft_lstclear(t_list **lst) {
        t_list *temp;
        while (*lst) {
                temp = (*lst)->next;
                free((*lst)->content);
                free(*lst);
                *lst = temp;
        }
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *last;

        if (lst == NULL || new == NULL)
                return ;
        if (!*lst)
        {
                *lst = new;
                return ;
        }
        last = ft_lstlast(*lst);
        last->next = new;
}

char *join_list_contents(t_list *list) {
        size_t total_length = 0;
        t_list *temp = list;
        while (temp) {
                total_length += ft_strlen(temp->content);
                temp = temp->next;
        }

        char *result = malloc(total_length + 1);
        if (!result)
                return NULL;

        result[0] = '\0';
        while (list) {
                strcat(result, list->content);
                list = list->next;
        }

        return result;
}