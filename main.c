#include "push_swap.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%s", (char *)stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf(" ");
		if (stack_b)
		{
			printf("\t%s", (char *)stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
}

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
	print_stacks(stack_a, stack_b);
	push(&stack_a, &stack_b);
	printf("\npb\n");
	push(&stack_a, &stack_b);
	printf("pb\n");
	swap(&stack_a);
	printf("sa\n");
	revert(&stack_a);
	printf("ra\n");
	push(&stack_b, &stack_a);
	printf("pa\n");
	revert(&stack_a);
	printf("ra\n");
	push(&stack_b, &stack_a);
	printf("pa\n");
	print_stacks(stack_a, stack_b);
	return (0);
}
