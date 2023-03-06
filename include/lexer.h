#ifndef LEXER_H
# define LEXER_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h> 

typedef enum e_label {
    COMMAND,
    PIPE,
} t_label;

typedef struct s_node {
    // struct s_node   *left;
    // struct s_node   *right;
    // struct s_node   *parent;
    struct s_node   *next;
    t_label         label;
    t_list          *commands;
    t_list          *filenames;
} t_node;

typedef enum e_redirect_type {
    INPUT,
    OUTPUT,
    APPEND_OUTPUT,
    HEREDOC_INPUT,
} t_redirect_type;

typedef struct s_redirection {
    t_redirect_type type;
    char            *filename;

} t_redirection;

typedef struct s_pid {
    int pids;
} t_pid;

char	*ft_strndup(char const *s1, size_t n);
t_list	*tokenizer(char *input);
t_node	*parser(t_list *tokens);
void    print_filenames(t_list *filenames, int *fdout);
char    **list_to_array(t_list *list);
void redirect_input(t_list *filenames, int *fdin);

#endif