/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:27:08 by faydin            #+#    #+#             */
/*   Updated: 2022/01/30 14:27:01 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
/*
void	*f(void *c)
{
	c = "deneme";
	return (c);
}

void	del(void *con)
{
	con = NULL;
}
int main()
{
    t_list *ilk;
    t_list *iki;

	t_list *ikincilisteilkeleman;
    char dizi[] = "ilk kontent";
    char dizi2[] = "ikinci kontent";
    ilk = ft_lstnew(dizi);
    iki = ft_lstnew(dizi2);
    ft_lstadd_back(&ilk,iki);

	ikincilisteilkeleman = ft_lstmap(ilk,f,del);
    printf("%s", (ikincilisteilkeleman)->content);
    printf("%s", (ikincilisteilkeleman)->next->content);
}*/
