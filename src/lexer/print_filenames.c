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