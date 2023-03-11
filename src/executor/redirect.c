#include "lexer.h"

void redirect_input(t_list *filenames, int *fdin)
{
    int             fd;
    t_redirection   *redirection;

    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        if (redirection->type == INPUT)
            fd = open((char *)redirection->filename, O_RDONLY);
        else if (redirection->type == HEREDOC_INPUT)
            fd = do_heredoc(redirection->filename);
        else
        {
            filenames = filenames->next;
            continue ;
        }
        if (fd < 0)
            perror("minishell");
        else
        {
            close(*fdin);
            *fdin = fd;
        }
        filenames = filenames->next;
    }
}

void redirect_output(t_list *filenames, int *fdout)
{
    // int             fd_pipe[2];
    int             fd;
    t_redirection   *redirection;

    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        if (redirection->type == OUTPUT)
            fd = open((char *)redirection->filename, O_RDWR|O_CREAT|O_TRUNC, 0777);
        else if (redirection->type == APPEND_OUTPUT)
            fd = open((char *)redirection->filename, O_RDWR|O_APPEND|O_CREAT, 0777);
        else
        {
            filenames = filenames->next;
            continue ;
        }
        if (fd < 0)
            perror("minishell");
        else
        {
            close(*fdout);
            *fdout = fd;
        }
        filenames = filenames->next;
    }
}

char    **list_to_array(t_list *list)
{
    size_t  i;
    size_t  len;
    char    **arr;

    len = (size_t)ft_lstsize(list);
    arr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!arr)
    {
        perror("list_to_array");
        exit(1);
    }
    i = 0;
    while (list != NULL)
    {
        arr[i++] = (char *)list->content;
        list = list->next;
    }
    arr[i] = NULL;
    return (arr);
}