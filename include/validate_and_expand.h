#ifndef VALIDATE_AND_EXPAND_H
# define VALIDATE_AND_EXPAND_H

# include "expansion.h"

# define	MSG_SYNTAX_ERR_PREFIX "minishell: syntax error near unexpected token `"
# define	MSG_SYNTAX_ERR_SUFFIX "'"

bool	validate_and_expand(t_list *tokens);

#endif
