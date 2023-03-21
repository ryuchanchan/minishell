#include "minishell.h"

void exit_error(char *msg)
{
    perror(msg);
    exit(1);
}

static bool is_numerical(char *s)
{
    size_t i;

    if (!ft_isdigit(s[0]) && s[0] != '+' && s[0] != '-')
        return (false);
    i = 1;
    while (s[i] != '\0')
        if (!ft_isdigit(s[i++]))
            return (false);
    return (true);
}

int	builtin_exit(char **args, char ***envp_p)
{
    int status;

    printf("exit\n");
    if (!args[1])
        exit(0);
    if (!is_numerical(args[1]))
    {
        printf("exit: %s: numeric argument required\n", args[1]);
        exit(255);
    }
    if (args[2])
    {
        printf("exit: too many arguments\n");//どいう条件か？
        return (1);
    }
    status = ft_atoi(args[1]);
    sa_free(args);
    free(envp_p);
    exit(status);

    return (0);
}