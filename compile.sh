# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:40:33 by dgerard           #+#    #+#              #
#    Updated: 2017/10/27 21:01:26 by dgerard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -o listen listen.c libft/get_next_line.c libft/ft_memdel.c libft/ft_memalloc.c\
	libft/ft_strchr.c libft/ft_strjoini.c libft/ft_bzero.c libft/ft_strjoin.c\
	libft/ft_strlen.c libft/ft_strncmp.c\
    -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
    `pkg-config --cflags --libs pocketsphinx sphinxbase`
