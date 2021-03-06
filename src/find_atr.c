/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_atr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:08:15 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:08:19 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	atr_sharp(char **per, char spec, char **prefix, char *arg)
{
	int		i;
	int		del;
	char	syn[3];
	char	rem[4];

	i = 0;
	del = 0;
	ft_strcpy(syn, "oxX\0");
	ft_strcpy(rem, "#+ \0");
	while (syn[i] && syn[i] != spec)
		i++;
	if (!syn[i])
		remove_char(*per, '#');
	if (syn[i] && spec == 'o' && arg[0] != '0')
		*(prefix[0]) = '0';
	else if (syn[i] && arg[0] != '0')
		ft_memcpy(*prefix, ((char[2]){'0', spec}), sizeof(char[2]));
	while (syn[i] && rem[del])
		remove_char(*per, rem[del++]);
}

void	atr_posit(char **per, char spec, char **prefix, char *arg)
{
	int		i;
	char	rem[3];
	char	syn[3];

	i = 0;
	ft_strcpy(syn, "di\0");
	ft_strcpy(rem, "+ \0");
	while (syn[i] && syn[i] != spec)
		i++;
	if (!(*(prefix[0])) && syn[i])
		*(prefix[0]) = '+';
	i = 0;
	arg += 0;
	spec += 0;
	while (rem[i])
		remove_char(*per, rem[i++]);
}

void	atr_negat(char **per, char spec, char **prefix, char *arg)
{
	int		i;
	char	rem[4];

	i = 0;
	ft_strcpy(rem, "0- \0");
	arg += 0;
	spec += 0;
	*prefix += 0;
	while (rem[i])
		remove_char(*per, rem[i++]);
}

void	atr_space(char **per, char spec, char **prefix, char *arg)
{
	int		i;
	char	syn[3];

	i = 0;
	ft_strcpy(syn, "di\0");
	while (syn[i] && syn[i] != spec)
		i++;
	if (syn[i] && !(*(prefix[0])))
		*(prefix[0]) = ' ';
	arg += 0;
	spec += 0;
	*prefix += 0;
	remove_char(*per, ' ');
}

void	atr_zero(char **per, char spec, char **prefix, char *arg)
{
	int		i;
	int		len;
	char	*zero;

	i = 0;
	while (*per && (*per)[i] != '0')
		i++;
	while (*per && (*per)[i] == 'R')
		i++;
	len = extract_nbr(*per, i) - (ft_strlen(*prefix) + ft_strlen(arg));
	if (len > 0)
	{
		zero = ft_memset(ft_strnew(len), '0', len);
		*prefix = ft_strjoin_clean(prefix, &zero);
	}
	spec += 0;
	if (len > 0)
		ft_strdel(&zero);
	remove_char(*per, '0');
}
