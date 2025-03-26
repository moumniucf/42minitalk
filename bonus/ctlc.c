static int how_much(int c)
{
    if (c == 12)
        return (2);
    else if (c == 14)
        return (3);
    else if (c == 15) 
        return (4);
    return (1);
}


static int	handle_out(unsigned char c, int flush)
{
	static unsigned char	prnt[5];
	static int				bits;
	static int				i;

	if (flush == 1)
	{
		write(1, prnt, i);
		bzero((char *)prnt, sizeof(prnt));
		i = 0;
		bits = 0;
	}
	else
	{
		if (!bits)
		{
			bits = how_much(c >> 4);
			if (i > 0)
			{
				write(1, prnt, i);
				bzero((char *)prnt, sizeof(prnt));
			}
			i = 0;
		}
		prnt[i] = c;
		i++;
		bits--;
	}

	return 1;
}


static void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n",1);
	handle_out('\0', 1);
	exit(1);
}