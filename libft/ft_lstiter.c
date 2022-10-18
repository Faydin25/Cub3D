/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:18:06 by faydin            #+#    #+#             */
/*   Updated: 2022/01/29 18:36:42 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void	f(void *content)
{
	int	i = 0;
	char	*a = (char *)content;
	while (a[i])
	{
		a[i] -= 32;
		i++;
	}
}

int main()
{
    t_list *ilk;
    char dizi[] = "ilk content";
    t_list *iki;
    char dizi2[] = "ikinci content";
    ilk = ft_lstnew(dizi);
	iki = ft_lstnew(dizi2);
	ft_lstadd_back(&ilk,iki);
    ft_lstiter(&ilk,f);
    printf("%s",(ilk)->content);
	printf("%s",(ilk)->next->content);

}*/
