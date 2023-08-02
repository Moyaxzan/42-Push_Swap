/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:42:51 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/02 17:55:34 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	len_word(const char *beg_word, char separator)
{
	int	i;

	i = 0;
	while (beg_word[i] && beg_word[i] != separator)
		i++;
	return (i);
}

static int	count_words(int argc, char **argv, char separator)
{
	int	i;
	int	cpt;

	cpt = 0;
	while (argc-- - 1)
	{
		i = 0;
		if (ft_strchr(argv[argc], ' '))
			while (argv[argc][i])
			{
				while (argv[argc][i] && argv[argc][i] == separator)
					i++;
				if (argv[argc][i])
					cpt++;
				while (argv[argc][i] && argv[argc][i] != separator)
					i++;
			}
		else
			cpt++;
	}
	return (cpt);
}

static char	*fill_word(char const *beg_word, char separator)
{
	char	*word;
	int		size_word;
	int		i;

	i = 0;
	size_word = len_word(beg_word, separator);
	word = malloc(sizeof(char) * (size_word + 1));
	if (!word)
		return (NULL);
	while (beg_word[i] && beg_word[i] != separator)
	{
		word[i] = beg_word[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**free_split(char **splitted_tab)
{
	int	i;

	i = 0;
	while (splitted_tab && splitted_tab[i])
	{
		free(splitted_tab[i]);
		i++;
	}
	free(splitted_tab);
	return (0x0);
}

char	**new_split(int argc, char **argv)
{
	char	**splitted_tab;
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	splitted_tab = malloc(sizeof(char *) * (count_words(argc, argv, ' ') + 1));
	if (!splitted_tab)
		return (NULL);
	while (i++ < argc)
		while (argv[i] && *(argv[i]))
		{
			while (*(argv[i]) && *(argv[i]) == ' ')
				(argv[i])++;
			if (*(argv[i]))
			{
				splitted_tab[cpt] = fill_word(argv[i], ' ');
				if (!splitted_tab[cpt++])
					return (free_split(splitted_tab));
			}
			while (*(argv[i]) && *(argv[i]) != ' ')
				(argv[i])++;
		}
	i++;
	splitted_tab[cpt] = NULL;
	return (splitted_tab);
}
