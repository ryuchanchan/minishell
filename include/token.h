#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

# include "../libft/include/libft.h"

typedef enum e_token_type {
    T_WORD,
    T_PIPE,
	T_REDIRECT_OUT_TRUNC,
	T_REDIRECT_OUT_APPEND,
	T_REDIRECT_IN,
	T_REDIRECT_HEREDOC
} t_token_type;

typedef struct s_token {
	char			*str;
	t_token_type	type;
} t_token;

t_token	*construct_token(char *str);
void	destruct_token(void *content);
bool	is_redirection(t_token_type type);

#endif
