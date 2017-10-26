/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:39:03 by dgerard           #+#    #+#             */
/*   Updated: 2017/10/24 16:39:08 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "listen.h"

int				main(void)
{
	system("pocketsphinx_continuous -inmic yes -logfn /dev/null \
		-lm support/en-us.lm.bin -dict support/cmudict-en-us.dict");
	// -inmic yes : listen through mic input
	// -logfn /dev/null : silence log output onto terminal
}
