
#include <iostream>

int main(int ac, char **av)
{
	std::string upper_str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int y = 1; y < ac; y++)
	{
		upper_str = upper_str + " " + av[y];
		if (y < ac)
			upper_str + " ";
	}
	for (size_t i = 0; i < upper_str.size(); i++)
	{
		if (upper_str[i] >= 'a' && upper_str[i] <= 'z')
			upper_str[i] = std::toupper(upper_str[i]);
		std::cout << upper_str[i];
	}
	std::cout << std::endl;
	return (0);
}