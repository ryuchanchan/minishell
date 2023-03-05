#include "lexer.h"

static void	extract(char *s, char *start, t_list **list)
{
    char *c;
    size_t n;

    if (s == start)
    {
        return ;
    }
    
    n = (s - start) / sizeof(char);
    c = ft_strndup(start, n);
    // printf("%s\n", c);
    ft_lstadd_back(list, ft_lstnew(c));
}

static int	istoken(char c)
{
    return ((c == ' ' || c == '|' || c == '<' || c == '>'));
}

//文字列を分割する
t_list *tokenizer(char *input)
{
    int     i;
    char *start;
    int     indquote;
    int     insquote;
    t_list  *list;

    list = NULL;
    
    indquote = 0;
    insquote = 0;
    start = input;
    i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '"' && !insquote)
        {
            indquote = !indquote;
        }
        if (input[i] == '\'' && !indquote)
        {
            insquote = !insquote;
        }
        if (istoken(input[i]) && !indquote && !insquote)
        {
            extract(&input[i], start, &list);
            start = &input[i+1];
            if (input[i] != ' ')
            {
                if (input[i] != '|' && input[i] == input[i+1])
                {
                    extract(&input[i+2], &input[i], &list);
                    start = &input[i+2];
                    i++;   
                }
                else
                    extract(&input[i+1], &input[i], &list);       
            }    
        }
        i++;
    }
    extract(&input[i], start, &list);
    return (list);
}