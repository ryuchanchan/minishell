#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <fcntl.h> 

# include "quotes.h"
# include "token.h"

typedef struct s_lexier {
    char            *start;
    t_status_quotes status;
} t_lexier;

t_list  *lexier(char *input);

#endif
