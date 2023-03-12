#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "token.h"

typedef struct s_redirection {
	t_token_type	type;
	char			*filename;
} t_redirection;

t_redirection	*construct_redirection(t_token *token_p, t_token *next_p);
void			destruct_redirection(void *content);

#endif
