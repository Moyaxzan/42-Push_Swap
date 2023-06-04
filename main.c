#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = 0x0;
	stack_b = 0x0;
	while (i < argc)
	{
		node = malloc(sizeof(t_list));
		node->content = argv[i];
		node->next = 0x0;
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	node = stack_a;
	while (node)
	{
		printf("%s ", (char *)node->content);
		node = node->next;
	}
	return (0);
}
