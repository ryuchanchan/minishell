#include "lexer.h"

//変数inputの文字を一つ一つ構造体の変数contentsに入れる。

static t_node *make_node()
{
    t_node *data;

    data = malloc(sizeof(t_node));
    if (!data)
    {
        exit(1);
    }
    data->commands = NULL;
    data->filenames = NULL;
    data->next = NULL;
    data->label = COMMAND;
    return (data);
}

static int	is_redirection(const char *s)
{
	size_t len;
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len == 2)
	{
		if (ft_strncmp(s, "<<", 2) == 0)
			return (1);
		if (ft_strncmp(s, ">>", 2) == 0)
			return (1);
	}
	if (len == 1)
	{
		if (ft_strncmp(s, ">", 1) == 0)
			return (1);
		if (ft_strncmp(s, "<", 1) == 0)
			return (1);
	}
    return (0);
}

static t_redirection *make_redirection(t_list *now, t_list **next_p)
{
    t_redirection *data;

    data = malloc(sizeof(t_redirection));
    if (!data)
    {
        exit(1);
    }
    if (ft_strncmp(now->content, "<<", 2) == 0)
    {
        data->type = HEREDOC_INPUT;
    }
    else if (ft_strncmp(now->content, ">>", 2) == 0)
    {
        data->type = APPEND_OUTPUT;
    }
    else if (ft_strncmp(now->content, ">", 1) == 0)
    {
        data->type = OUTPUT;
    }
    else if (ft_strncmp(now->content, "<", 1) == 0)
    {
        data->type = INPUT;
    }
    if (*next_p != NULL && !is_redirection((*next_p)->content))
    {  
        // (*next_p)->contentがリダイレクションの場合syntax errになるべき
        data->filename = (*next_p)->content;
		*next_p = (*next_p)->next;
	}
	return (data);
}

t_node *parser(t_list *tokens)
{
    t_list *next;
    t_list *now;
    t_node *node;
    t_node *head;

    now = tokens;
    //whileに入る前にノードを作る必要がある
    //リストに入ってる文字列comands filenames null
    head = make_node();
    node = head;
    while (now != NULL)
    {
        next = now->next;
        now->next = NULL;
        //nowがパイプラインだったとき新しくノードを作って元に戻る必要ある
        if (ft_strncmp((const char *)now->content, "|", 1) == 0)
        {
            node->next = make_node();
            node = node->next;
        }        
        else if (is_redirection((const char *)now->content))
        {
            ft_lstadd_back(&node->filenames, ft_lstnew(make_redirection(now, &next)));
        }
        else
        {
            ft_lstadd_back(&node->commands, now);
        }
        now = next;
    }
    return (head);
}