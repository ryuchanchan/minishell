/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:41:20 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/06 19:41:33 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_head;
	t_list	*mapped;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped_head = NULL;
	while (lst != NULL)
	{
		mapped = ft_lstnew(f(lst->content));
		if (mapped == NULL)
		{
			ft_lstclear(&mapped_head, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_head, mapped);
		lst = lst->next;
	}
	return (mapped_head);
}
