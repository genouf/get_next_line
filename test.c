# include "get_next_line.h"

int	ft_find_line(char *buff, int buff_size)
{
	int i;

	i = 0;
	while (buff[i] && i < buff_size)
	{
		if (buff[i] == '\n')
		{
			return (i);
		}	
		i++;
	}
	return (-1);
}

int	main(void)
{
	char str[] = "lolmdrlolmd\n";
	
	printf("%d", ft_find_line(str, 12));
	//printf("%s", ft_substr(str, 7, 5));
	return (0);
}