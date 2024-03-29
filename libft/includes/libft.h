/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:43:15 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:52:14 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H

#include <stddef.h>

typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

int ft_atoi(const char *str);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
char *ft_itoa(int n);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lst_at(t_list *lst, unsigned int k);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
				  void (*del)(void *));
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(char *s, int fd);
char **ft_split(char const *s, char c);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlcat(char *dest, const char *src, size_t size);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
size_t ft_strlen(const char *s);
char *ft_strmapi(char const *s,
				 char (*f)(unsigned int, char));
char *ft_strnstr(const char *haystack,
				 const char *needle, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strrchr(const char *s, int c);
char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);
float ft_atof(const char *str);
int get_next_line(int fd, char **line);

#	endif
