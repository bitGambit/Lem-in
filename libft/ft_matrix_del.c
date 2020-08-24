/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:06:43 by gartanis          #+#    #+#             */
/*   Updated: 2020/08/24 14:06:46 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        ft_matrix_del(void **src)
{
    while (*src != NULL)
    {
        free(*src);
        src += 1;
    }
}
