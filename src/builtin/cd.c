#include "minishell.h"

int	builtin_cd(char **args, char ***envp_p)
{
    char *home;
    (void)envp_p;
    
    if (!chdir(args[1]))
    {
        return (-1);
    }
    if (args[1] == 0 || ft_strcmp(args[1], "~"))
    {
        home = getenv("HOME");
        chdir(home);
    }
    else
    {
        printf("cd: %s: No such file or directory\n", args[1]);
        return (1);
    }
    return (0);
}