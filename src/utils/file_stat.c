#include "file_stat.h"

bool	is_directory(char *filepath)
{
	struct stat	buf;

	if (lstat(filepath, &buf) != 0)
		return (false);
	return (S_ISDIR(buf.st_mode));
}

bool	is_regular_file(char *filepath)
{
	struct stat	buf;

	if (lstat(filepath, &buf) != 0)
		return (false);
	return (S_ISREG(buf.st_mode));
}
