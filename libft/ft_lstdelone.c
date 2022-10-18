/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:16:16 by faydin            #+#    #+#             */
/*   Updated: 2022/01/30 14:12:58 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	content = NULL;
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
	
	
	ft_lstadd_back(&ilk,iki);
	printf("baglandı mı ?%s",(ilk)->next->content);
    
	
	ft_lstdelone(iki,del);
	ilk->next = NULL;

	printf("%s",(ilk)->content);
}*/
