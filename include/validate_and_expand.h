#ifndef VALIDATE_AND_EXPAND_H
# define VALIDATE_AND_EXPAND_H

# include "expansion.h"

# define	MSG_SYNTAX_ERR_QUOTE "syntax error: quotation isn't closed"
# define	MSG_SYNTAX_ERR_PREFIX "syntax error near unexpected token `"
# define	MSG_SYNTAX_ERR_SUFFIX "'"

bool	validate_and_expand(t_list *tokens, bool is_quote_not_closed);

#endif
