#include "executor.h"

void    redirect_input(t_list *redirections, int *fdin, int tmpin, int tmpout)
{
    int             fd;
    t_list          *redirection;
    t_redirection   *r_p;

    redirection = redirections;
    while (redirection)
    {
        r_p = (t_redirection *)redirection->content;
        if (r_p->type == T_REDIRECT_IN)
            fd = open(r_p->filename, O_RDONLY);
        else if (r_p->type == T_REDIRECT_HEREDOC)
            fd = do_heredoc(r_p->filename, tmpin, tmpout);
        else
        {
            redirection = redirection->next;
            continue ;
        }
        if (fd < 0)
            perror(r_p->filename);
        else
        {
            close(*fdin);
            *fdin = fd;
        }
        redirection = redirection->next;
    }
}

void    redirect_output(t_list *redirections, int *fdout)
{
    int             fd;
    t_list          *redirection;
    t_redirection   *r_p;

    redirection = redirections;
    while (redirection)
    {
        r_p = (t_redirection *)redirection->content;
        if (r_p->type == T_REDIRECT_OUT_TRUNC)
            fd = open(r_p->filename, O_RDWR|O_CREAT|O_TRUNC, 0644);
        else if (r_p->type == T_REDIRECT_OUT_APPEND)
            fd = open(r_p->filename, O_RDWR|O_CREAT|O_APPEND, 0644);
        else
        {
            redirection = redirection->next;
            continue ;
        }
        if (fd < 0)
            perror(r_p->filename);
        else
        {
            close(*fdout);
            *fdout = fd;
        }
        redirection = redirection->next;
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
