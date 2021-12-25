#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < ac; i++)
		{
			for (j = 0; av[i][j]; j++)
			{
				c = std::toupper(av[i][j]);
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
