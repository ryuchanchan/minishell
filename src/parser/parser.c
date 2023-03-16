#include "parser.h"

static void parser_fatal_error(void)
{
    fatal_error("parser");
}

static void add_command(t_list **commands, t_list **command_p)
{
    t_command   *c_p;

    ft_lstadd_back(commands, *command_p);
    c_p = construct_command();
    if (!c_p)
        parser_fatal_error();
    *command_p = ft_lstnew(c_p);
    if (!*command_p)
        parser_fatal_error();
}

static void add_redirection(t_list **token_p, t_list *command)
{
    t_command       *c_p;
    t_token         *t_p;
    t_token         *next_p;
    t_redirection   *redirection;
    t_list          *list;

    c_p = command->content;
    t_p = (*token_p)->content;
    *token_p = (*token_p)->next;
    if (!*token_p)
        parser_fatal_error();
    next_p = (*token_p)->content;
    if (!t_p || !next_p)
        parser_fatal_error();
    redirection = construct_redirection(t_p, next_p);
    if (!redirection)
        parser_fatal_error();
    list = ft_lstnew(redirection);
    if (!list)
        parser_fatal_error();
    ft_lstadd_back(&(c_p->redirections), list);
}

static void add_arg(t_token *t_p, t_list *command)
{
    t_command   *c_p;
    char        *arg;
    t_list      *list;

    c_p = command->content;
    arg = ft_strdup(t_p->str);
    if (!arg)
        parser_fatal_error();
    list = ft_lstnew(arg);
    if (!list)
        parser_fatal_error();
    ft_lstadd_back(&(c_p->args), list);
}

t_list  *parser(t_list *tokens)
{
    t_list      *commands;
    t_list      *cmd;
    t_list      *tkn;
    t_token     *t_p;

    commands = NULL;
    cmd = NULL;
    add_command(&commands, &cmd);
    tkn = tokens;
    while (tkn)
    {
        t_p = tkn->content;
        if (t_p->type == T_PIPE)
            add_command(&commands, &cmd);
        if (is_redirection(t_p->type))
            add_redirection(&tkn, cmd);
        if (t_p->type == T_WORD)
            add_arg(t_p, cmd);
        tkn = tkn->next;
    }
    add_command(&commands, &cmd);
    ft_lstclear(&cmd, destruct_command);
    return (commands);
}
