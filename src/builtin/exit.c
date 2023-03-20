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

void exec_exit(char **splitted, char *line)
{
    int status;

    printf("exit\n");
    if (!splitted[1])
        exit(0);
    if (!is_numerical(splitted[1]))
    {
        printf("exit: %s: numeric argument required\n", splitted[1]);
        exit(255);
        return ;
    }
    if (splitted[2])
    {
        printf("exit: too many arguments\n");//どいう条件か？
        return ;
    }
    status = ft_atoi(splitted[1]);
    sa_free(splitted);
    free(line);
    exit(status);
}