#ifndef STRING_ARRAY_H
# define STRING_ARRAY_H

# include <stdlib.h>
# include "../libft/include/libft.h"

void	sa_print(const char **sa, size_t begin);
void	sa_free(char **sa);
size_t	sa_size(const char **sa);
char	**sa_clone(const char **sa);
char	**sa_from_list(t_list *list);

#endif
