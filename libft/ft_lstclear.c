/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:15:59 by faydin            #+#    #+#             */
/*   Updated: 2022/01/30 14:13:49 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = 0;
}
/*
void	del(void *content)
{
	content = 0;
}

#include <stdio.h>
int main()
{
    t_list *ilk;
    char dizi[] = "ilk content";
    t_list *iki;
    char dizi2[] = "ikinci content";
    ilk = ft_lstnew(dizi);
	iki = ft_lstnew(dizi2);
	ft_lstclear(&ilk,del);
    //printf("%s",(ilk)->content);
}*/
