/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:25:24 by pbernier          #+#    #+#             */
/*   Updated: 2017/03/06 20:09:26 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pre_str(char spec, char *w_atr, char **arg)
{
	int		i;
	int		len;
	char	*zero;
	char	spec_dos[9];

	i = 0;
	ft_strcpy(spec_dos, "diouxXsS\0");
	while (spec_dos[i] != spec && spec_dos[i])
		i++;
	if (!(w_atr) || !spec_dos[i] || !w_atr[1])
		return ;
	len = extract_nbr(w_atr, 0) - ft_strlen(*arg);
	if (len > 0 && i <= 5)
	{
		zero = ft_memset(ft_strnew(len), '0', len);
		*arg = ft_strjoin_clean(&zero, arg);
	}
	else if (len < 0 && i >= 6)
		*arg = ft_strsub(*arg, 0, ft_strlen(*arg) + len);
}

void	wof_str(char **str, char *per, int len_my_atr)
{
	int		wof;
	int		len_arg;
	char	*tmp;
	char	*w_atr;

	wof = 0;
	len_arg = ft_strlen(*str);
	tmp = NULL;
	w_atr = ft_strsub(per, len_my_atr, ft_strlen(per) - len_my_atr);
	if (per[0] != '.')
	{
		wof = (extract_nbr(w_atr, -1) - len_arg);
		if (wof > 0)
		{
			tmp = ft_strnew(wof);
			ft_memset(tmp, ' ', wof);
			if (!ft_strchr(per, '-'))
				*str = ft_strjoin_clean(&tmp, str);
			else if (ft_strchr(per, '-'))
			{
				*str = ft_strjoin_clean(str, &tmp);
				ft_strdel(&tmp);
			}
		}
	}
	ft_strdel(&per);
	ft_strdel(&w_atr);
}