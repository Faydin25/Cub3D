/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:16:32 by faydin            #+#    #+#             */
/*   Updated: 2022/01/29 18:31:43 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
    t_list *ilk;
    char dizi[] = "ilk content";
    t_list *iki;
    char dizi2[] = "ikinci content";
    ilk = ft_lstnew(dizi);
    iki = ft_lstnew(dizi2)
	printf("%s",ft_lstlast(&ilk)->content);   
}*/
