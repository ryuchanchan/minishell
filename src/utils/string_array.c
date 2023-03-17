#include "string_array.h"

void	sa_print(const char **sa, size_t begin)
{
	size_t	i;

	i = begin;
	if (!sa)
		return ;
	while (sa[i])
		ft_printf("%s\n",sa[i++]);
}

void	sa_free(char **sa)
{
	size_t	i;

	i = 0;
	if (!sa)
		return ;
	while (sa[i])
		free(sa[i++]);
	free(sa);
}

size_t	sa_size(const char **sa)
{
	size_t	i;

	if (!sa)
		return (0);
	i = 0;
	while (sa[i])
		i++;
	return (i + 1);
}

char	**sa_clone(const char **sa)
{
	size_t	i;
	size_t	size;
	char	**clone;

	if (!sa)
		return (NULL);
	size = sa_size(sa);
	clone = malloc(sizeof(char *) * size);
	if (!clone)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		clone[i] = ft_strdup(sa[i]);
		if (!clone[i])
		{
			while(i-- != 0)
				free(clone[i]);
			free(clone);
			return (NULL);
		}
		i++;
	}
	clone[size - 1] = NULL;
	return (clone);
}

char	**sa_from_list(t_list *list)
{
    size_t  i;
    size_t  len;
    char    **arr;

    len = (size_t)ft_lstsize(list);
    arr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!arr)
		return (NULL);
	i = 0;
    while (list != NULL)
    {
        arr[i++] = (char *)list->content;
        list = list->next;
    }
    arr[i] = NULL;
    return (arr);
}
