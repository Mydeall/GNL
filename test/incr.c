/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:28:38 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/15 16:14:54 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *pp(void)
{
	static int *i;

	if (!i)
	{
		i = (int*)malloc(sizeof(int));
		*i = 0;
	}
	(*i)++;
	printf("in pp : %d\n", *i);

	return (i);
}

void decr(int **i)
{
	(**i)--;
}

int *incr(void)
{
	int **i;

	i = (int**)malloc(sizeof(int*));
	*i = pp();
	*i = pp();
	decr(i);
	printf("in incr : %d\n", **i);
	return (*i);
}
