#include  "3-calc.h"

/**
 * get_op_func - selects the correct function
 * to perform the operation asked by the user
 * @s: operator paased as argument
 * Return: pointer to function
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int g = 0;

	while (g < 10)
	{
		if (s[0] == ops->op[g])
			break;
		g++;
	}

	return (ops[g / 2].f);
}
