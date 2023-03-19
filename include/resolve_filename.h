#ifndef RESOLVE_FILENAME_H
# define RESOLVE_FILENAME_H

# include "ms_error.h"
# include "ms_env.h"
# include "file_stat.h"
# include "string_array.h"
# include "key_value.h"

# define STAT_IS_DIRECTORY 126
# define STAT_CMD_NOT_FOUND 127
# define MSG_IS_DIRECTORY ": is a directory"
# define MSG_CMD_NOT_FOUND ": command not found"

char	*resolve_filename(char *arg_0, char ***envp_p);

#endif
