#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <fcntl.h> 

# include "quotes.h"
# include "token.h"

typedef struct s_lexer {
    char            *start;
    t_status_quotes status;
} t_lexer;

t_list  *lexer(char *input);

#endif
