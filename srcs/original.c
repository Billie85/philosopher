#include "../philo.h"

int	my_strcmp(char *s, char *s1)
{
	int i;

	i = 0;
	while(s[i] == s1[i] && s[i] != '\0' && s1[i] != '\0')
	{
		i++;
	}
		return(s[i] - s1[i]);
}
