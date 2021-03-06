/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:10:08 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 16:10:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		init_pstr(int i[2], char **arg, char *w_atr, char *my_atr)
{
	int		len;

	if (i[0] <= 5 && (*arg)[0] == '0' && extract_nbr(w_atr, 0) == 0
		&& !(i[0] == 2 && ft_strchr(my_atr, 'D')))
	{
		ft_strreset(arg, ft_strnew(0));
		return (i[1]);
	}
	len = extract_nbr(w_atr, 0) - ft_strlen(*arg);
	return (len);
}

int		init_wstr(char **per, int *wof, int *len_arg, char **str)
{
	int		ret;

	ret = -1;
	if (*per)
		ret = ret_pw(*per);
	*wof = 0;
	*len_arg = ft_strlen(*str);
	return (ret);
}
