/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:59:38 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/24 12:07:36 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "pushswap.h"
// get_next_line_utils.c
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin_n_free(char *s1, char *s2);
char	*ft_strchr(const char *s, char c);
// get_next_line.c
char	*get_next_line(int fd);
// checker_utils.c
int		ft_execpush(t_stack *a, t_stack *b, char *action);
int		ft_execrotate(t_stack *a, t_stack *b, char *action);
int		ft_execswap(t_stack *a, t_stack *b, char *action);
#endif
