/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:27:28 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:30:21 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>

# define MAX_FDS		12288
# define NT_SPACE	127
# define NT_LR		-2
# define NT_RR		-1

extern int	g_e_bash_errno;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_env_list
{
	struct s_env_list	*next;
	char				*value;
	t_bool				is_hidden;
}	t_env_list;

typedef struct s_cmd
{
	char	*cmd;
	char	*flags;
	char	*args;
	int		fd_in;
	int		fd_out;
	t_bool	is_empty_arg;
}	t_cmd;

size_t		ft_strlen(const char *string);
char		*ft_substr(char const *s, size_t start, size_t len);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
void		try_free(void *s);
t_bool		is_empty(const char *str);
t_bool		ft_isdigit(char c);
void		try_free2(void *s1, void *s2);
void		try_free3(void *s1, void *s2, void *s3);
void		try_free4(void *s1, void *s2, void *s3, void *s4);
char		*trim(char const *str);
size_t		ft_strlen_to_char(const char *string, char ch);
char		ft_tolower(char c);
void		str_tolower(char *str);
t_bool		str_contains(const char *str, const char *substr, t_bool
				is_after_space);
char		*str_get_word(char *s);
char		*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
void		try_close_fd(int fd);
void		ft_print_error(const char *s);
void		ft_print_str(const char *s);
void		is_system_error(void);
void		e_bash_strerror(int err, const char *prefix);
void		set_e_bash_errno(int err, const char *prefix);
t_bool		is_soft_error(const char *prefix);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
size_t		ft_arr_strlen(char **arr);
t_bool		ft_start_with(const char *input, const char *s, t_bool after_space);

char		**get_flat_env(t_env_list *env, t_bool copy);
char		*get_env_value(char *key, t_env_list *env);
void		print_environment(t_env_list *env);
t_env_list	*create_environment(char **env);

size_t		get_env_key_len(char *str);
char		*get_dollar_key(char *input);
void		add_new_env(char *input, t_env_list **env, t_bool is_concat,
				t_bool is_hidden);
t_bool		ft_str_is_alpha(char c);
t_bool		is_have_char(const char *input, char c);
void		del_env(char *key, t_env_list **env);
size_t		get_numlen(ssize_t sign_n);
char		*ft_itoa(ssize_t n);
int			ft_atoi(const char *str);
t_bool		is_number(const char *str);
long long	ft_atoll(const char *str);
t_bool		is_space(char c);
t_bool		ft_str_is_num(char c);
void		remove_nt_space(char *s);
t_bool		is_real_space(char c);

#endif
