/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MAIN <MAIN@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:21:05 by mde-lang          #+#    #+#             */
/*   Updated: 2023/04/17 16:10:45 by MAIN             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

# ifndef CHUNKS
#  define CHUNKS 10
# endif

typedef struct s_element
{
	long long int	value;
	int				rank;
	int				pack;
}					t_element;

typedef struct s_lst
{
	t_element		*content;
	struct s_lst	*next;
}					t_lst;

typedef struct s_xtrem
{
	int	rank_high;
	int	rank_low;
	int	spot_high;
	int	spot_low;
}					t_xtrem;

size_t			ft_strlen(const char *str);
int				ft_isdigit(int d);
char			*ft_strrchr(const char *string, int searchedChar);
void			ft_bzero(void *pointer_s, size_t n);
int				ft_isalnum(int i);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int d);
int				ft_isprint(int p);
void			*ft_memcpy(void *destination, const void *source, size_t size);
void			*ft_memset(void *pointer, int value, size_t count);
char			*ft_strchr(const char *string, int searchedChar);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memmove(void *dst, const void *src, size_t len);
long long int	ft_atoi(const char *str);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(
					const char *first, const char *second, size_t length);
void			*ft_memchr(
					const void *memoryBlock, int searchedChar, size_t size);
int				ft_memcmp(
					const void *pointer1, const void *pointer2, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_split(char const *s, char c);
t_lst			*ft_lstnew(void *content);
void			ft_lstadd_front(t_lst **lst, t_lst *new);
int				ft_lstsize(t_lst *lst);
t_lst			*ft_lstlast(t_lst *lst);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
void			ft_lstdelone(t_lst *lst, void (*del)(void*));
void			ft_lstclear(t_lst **lst, void (*del)(void*));
void			ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst			*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));

#endif
