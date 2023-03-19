#ifndef FILE_STAT_H
# define FILE_STAT_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>

bool	is_directory(char *filepath);
bool	is_regular_file(char *filepath);

#endif
