int		ft_isdigit(int a)
{
	return (a >= '0' && a <= '9');
}

int		ft_atoi(const char *str)
{
	int			num;
	int			m;

	num = 0;
	m = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
	{
		m = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		++str;
	}
	return (num * m);
}

void	*thread(void *phil)
{

}
