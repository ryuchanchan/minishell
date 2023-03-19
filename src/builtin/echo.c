#include "ms_builtin.h"

static void	print_array(char **splitted, const size_t begin)
{
	size_t	i;

	i = begin;
	while (splitted[i])
	{
		ft_printf("%s", splitted[i]);
		if (splitted[i + 1])
			ft_printf(" ");
		i++;
	}
}

int	builtin_echo(char **args, char ***envp_p)
{
	(void)envp_p;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		print_array(args, 2);
		return (0);
	}
	print_array(args, 1);
	ft_printf("\n");
	return (0);
}
