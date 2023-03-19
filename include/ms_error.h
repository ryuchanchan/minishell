#ifndef MS_ERROR_H
# define MS_ERROR_H

# include <stdio.h>

# include "../libft/include/libft.h"

# define STAT_FATAL_ERR 1

# define MSG_SYNTAX_ERR_QUOTE "syntax error: quotation isn't closed"
# define MSG_SYNTAX_ERR_PREFIX "syntax error near unexpected token `"
# define MSG_SYNTAX_ERR_SUFFIX "'"
# define STAT_SYNTAX_ERR 258

# define MSG_IS_DIRECTORY ": is a directory"
# define MSG_CMD_NOT_FOUND ": command not found"
# define STAT_IS_DIRECTORY 126
# define STAT_CMD_NOT_FOUND 127

void	fatal_error(char *str);
void	print_quote_error(void);
void	print_syntax_error(char *str);

#endif
