/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:52:20 by youssama          #+#    #+#             */
/*   Updated: 2021/12/12 20:47:09 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s1, char c);
char	*ft_strjoin(char*s1, char*s2);

#endif
