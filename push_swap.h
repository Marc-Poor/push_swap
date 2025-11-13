/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:10:42 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/13 19:25:47 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				number;
	struct s_list	*next;
}					t_list;

int					error_output(char *base, int disaine);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
int					error_value(char **av, int y, int x);
int					compare(char **av, int ac);
int					in_order(char **av, int i, int ac);
void				radix_loop(t_list **list_a, t_list **list_b, int biggest);
char				*ft_itoa_base(long nbr, char *base);
void				do_pb(t_list **list_a, t_list **list_b);
void				do_pa(t_list **list_a, t_list **list_b);
void				do_ra(t_list **list_a);
t_list				*ft_lstnew(void *content, int number);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
