/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:23:07 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/23 21:18:06 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_BONUS_H
# define    GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include	<stdio.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>

char	*get_next_line(int fd);
int		check_str(char *str);
char	*ft_read(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getafterline(char *str, int len);
char	*ft_getline(char *str, int *len);
char	*ft_memcpy(char *src, char *dst);
int		ft_countline(char *str);
int		ft_strlen(char *string);

#endif