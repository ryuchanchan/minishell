#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <fcntl.h>

# include "quotes.h"
# include "token.h"
# include "ms_error.h"

typedef struct s_lexer
{
    char            *start;
    t_q_status status;
}   t_lexer;

t_list  *lexer(char *input, bool *is_quote_not_closed_p);

#endif
