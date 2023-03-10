#include "lexer.h"

static void	add_token(char *s, char *start, t_list **list)
{
    t_token *token_p;
    size_t  n;
    if (s == start)
        return ;
    n = (s - start) / sizeof(char);
    token_p = construct_token(ft_strndup(start, n));
    if (!token_p)
        exit(1);
    ft_lstadd_back(list, ft_lstnew(token_p));
}

static void extract(char *line, size_t *i_p, char **start_p, t_list **tokens_p)
{
    add_token(&line[*i_p], *start_p, tokens_p);
    *start_p = &line[*i_p + 1];
    if (line[*i_p] == ' ')
    {
        (*i_p)++;
        return ;
    }
    if (ft_strncmp(&line[*i_p], "<<", 2) == 0 \
        || ft_strncmp(&line[*i_p], ">>", 2) == 0)
    {
        add_token(&line[*i_p + 2], &line[*i_p], tokens_p);
        *start_p = &line[*i_p + 2];
        *i_p += 2;
        return ;
    }
    add_token(&line[*i_p + 1], &line[*i_p], tokens_p);
    (*i_p)++;
}

static int	is_separator(char c)
{
    return ((c == ' ' || c == '|' || c == '<' || c == '>'));
}

static void initialize_lexier(t_lexier *lexier_p, char *line)
{
    lexier_p->start = line;
    lexier_p->status = NONE;
}

t_list *lexier(char *line)
{
    size_t      i;
    t_lexier    lexier;
    t_list      *tokens;

    initialize_lexier(&lexier, line);
    tokens = NULL;
    i = 0;
    while (line[i] != '\0')
    {
        if (is_single_quote_begin(lexier.status, line, i))
            update_status(&lexier.status, IN_SINGLE_QUOTE, &i);
        else if (is_double_quote_begin(lexier.status, line, i))
            update_status(&lexier.status, IN_DOUBLE_QUOTE, &i);
        else if (is_quote_end(lexier.status, line, i))
			update_status(&lexier.status, NONE, &i);
        else if (is_separator(line[i]) && lexier.status == NONE)
            extract(line, &i, &lexier.start, &tokens);
        else
            i++;
    }
    add_token(&line[i], lexier.start, &tokens);
    if (lexier.status != NONE)
        ft_printf("warning: unquote!!!!!\n");
    return (tokens);
}
