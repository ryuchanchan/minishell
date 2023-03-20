/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:13:12 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:13:19 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_redirect.h"

static void	update_fd(int *fd_p, int fd_new, char *filename)
{
	if (fd_new < 0)
		perror(filename);
	close(*fd_p);
	*fd_p = fd_new;
}

static void	redirect_input(t_list *rs, int *fdin, int tmpin, int tmpout)
{
	int				fd;
	t_list			*redirection;
	t_redirection	*r_p;

	redirection = rs;
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
		update_fd(fdin, fd, r_p->filename);
		if (fd < 0 || get_flag() == SF_SIGINT)
			return ;
		redirection = redirection->next;
	}
}

static void	redirect_output(t_list *rs, int *fdout)
{
	int				fd;
	t_list			*redirection;
	t_redirection	*r_p;

	redirection = rs;
	while (redirection)
	{
		r_p = (t_redirection *)redirection->content;
		if (r_p->type == T_REDIRECT_OUT_TRUNC)
			fd = open(r_p->filename, O_RDWR | O_CREAT | O_TRUNC, PERMISSION_NEW);
		else if (r_p->type == T_REDIRECT_OUT_APPEND)
			fd = open(r_p->filename, O_RDWR | O_CREAT | O_APPEND, PERMISSION_NEW);
		else
		{
			redirection = redirection->next;
			continue ;
		}
		update_fd(fdout, fd, r_p->filename);
		if (fd < 0)
			return ;
		redirection = redirection->next;
	}
}

bool	do_redirect(t_list *command, int fdin, int tmpin, int tmpout)
{
	int			fdout;
	int			pipe_fd[2];
	t_command	*c_p;

	c_p = command->content;
	redirect_input(c_p->redirections, &fdin, tmpin, tmpout);
	if (fdin < 0 || get_flag() == SF_SIGINT)
		return (true);
	if (dup2(fdin, STDIN_FILENO) < 0)
		fatal_error("executor");
	close(fdin);
	if (command->next)
	{
		pipe(pipe_fd);
		fdout = pipe_fd[1];
		fdin = pipe_fd[0];
	}
	else
		fdout = dup(tmpout);
	redirect_output(c_p->redirections, &fdout);
	if (fdout < 0)
		return (true);
	if (dup2(fdout, STDOUT_FILENO) < 0)
		fatal_error("executor");
	close(fdout);
	return (false);
}
