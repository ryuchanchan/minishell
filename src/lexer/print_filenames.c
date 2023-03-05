#include "lexer.h"

void print_filenames(t_list *filenames, int *fdout)
{
    int             fd_pipe[2];
    t_redirection   *redirection;

    while (filenames != NULL)
    {
        redirection = (t_redirection *)filenames->content;
        if (redirection->type == INPUT)
        {
            int fd = open((char *)redirection->filename, O_RDONLY);
            if (fd == -1)
            {
                printf("minishell: %s: No such file or directory\n", (char *)redirection->filename);
                break ;
            }
        }
        if (redirection->type == OUTPUT)
        {
            int fd = open((char *)redirection->filename, O_RDWR|O_CREAT|O_TRUNC, 0777);
            close(*fdout);
            *fdout = fd;
        }
        if (redirection->type == APPEND_OUTPUT)
        {
            int fd = open((char *)redirection->filename, O_RDWR|O_APPEND|O_CREAT, 0777);
            close(*fdout);
            *fdout = fd;
        }
        if (redirection->type == HEREDOC_INPUT)
        {
            int fd = open((char *)redirection->filename, O_RDONLY);
            close(*fdout);
            *fdout = fd;
            pipe(&fd_pipe[2]);
            while (*fdout)
            {
                if (fd_pipe[1])
                {
                    write(fd_pipe[1], fdout, 1);
                }
            }
            dup2(fd_pipe[0], 0);
            printf("HEREDOC_INPUT");
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