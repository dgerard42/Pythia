/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:05:14 by dgerard           #+#    #+#             */
/*   Updated: 2017/10/22 18:31:21 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pocketsphinx.h>

int				main(int argc, char **argv)
{
	ps_decoder_t 	*ps;
	cmd_ln_t 		*config;
	FILE			*fh;
	int				rv;
	int16			buf[512];
	const char		*hyp;
	int32			score;

	config = cmd_ln_init(NULL, ps_args(), TRUE,
		         "-hmm", MODELDIR "/en-us/en-us",
		         "-lm", MODELDIR "/en-us/en-us.lm.bin",
	    		 "-dict", MODELDIR "/en-us/cmudict-en-us.dict",
		         NULL);
	if (!config)
	{
		fprintf(stderr, "Failed to create config object, see log for details\n");
		return (-1);
	}
	ps = ps_init(config);
	if (!ps)
	{
		fprintf(stderr, "Failed to create recognizer, see log for details\n");
		return (-1);
	}
	fh = fopen("goforward.raw", "rb");
	if (fh == NULL)
	{
		fprintf(stderr, "Unable to open input file\n");
		return (-1);
	}
	rv = ps_start_utt(ps);
	while (!feof(fh))
	{
		size_t nsamp;
		nsamp = fread(buf, 2, 512, fh);
		rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
	}
	rv = ps_end_utt(ps);
	hyp = ps_get_hyp(ps, &score);
	printf("Recognized: %s\n", hyp);

	fclose(fh);
	ps_free(ps);
	cmd_ln_free_r(config);

	return (0);
}
