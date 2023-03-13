#include "lexer.h"

static void add_token(char *s, char *start, t_list **list_p)
{
    t_token *token_p;
    t_list  *list;
    size_t  n;

    if (s == start)
        return ;
    n = (s - start) / sizeof(char);
    token_p = construct_token(ft_strndup(start, n));
    if (!token_p)
        exit(1);
    list = ft_lstnew(token_p);
    if (!list)
        exit(1);
    ft_lstadd_back(list_p, list);
}

static void extract(char *line, size_t *i_p, char **start_p, t_list **tokens_p)
{
    add_token(&line[*i_p], *start_p, tokens_p);
    *start_p = &line[*i_p + 1];
    if (line[*i_p] == ' ' || line[*i_p] == '\t')
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

static bool is_separator(char c)
{
    if (c == ' ' || c == '\t')
        return (true);
    return (c == '|' || c == '<' || c == '>');
}

static void initialize_lexer(t_lexer *lexer_p, char *line)
{
    lexer_p->start = line;
    lexer_p->status = NONE;
}

t_list  *lexer(char *line)
{
    size_t  i;
    t_lexer lexer;
    t_list  *tokens;

    initialize_lexer(&lexer, line);
    tokens = NULL;
    i = 0;
    while (line[i] != '\0')
    {
        if (is_single_quote_begin(lexer.status, line, i))
            update_status(&lexer.status, IN_SINGLE_QUOTE, &i);
        else if (is_double_quote_begin(lexer.status, line, i))
            update_status(&lexer.status, IN_DOUBLE_QUOTE, &i);
        else if (is_quote_end(lexer.status, line, i))
			update_status(&lexer.status, NONE, &i);
        else if (is_separator(line[i]) && lexer.status == NONE)
            extract(line, &i, &lexer.start, &tokens);
        else
            i++;
    }
    add_token(&line[i], lexer.start, &tokens);
    if (lexer.status != NONE)
        ft_printf("warning: unquote!!!!!\n");
    return (tokens);
}
