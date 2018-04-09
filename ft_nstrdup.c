#include "libftprintf.h"

char	*ft_nstrdup(const char *s, size_t n)
{
	size_t		i;
	char	*moc;

	i = 0;
	moc = (char*)malloc(sizeof(*moc) * (n + 1));
	if (!moc)
		return (NULL);
	while (i < n)
	{
		moc[i] = s[i];
		i++;
	}
	moc[i] = '\0';
	return (moc);
}
