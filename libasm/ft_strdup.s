/*char *ft_strdup(char *s)
{
	int	i;
	char *res;

	if (!s)
		return (NULL);
	if (!(res = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}*/

section	.text
	global	_ft_strdup

extern malloc
extern free

_ft_strdup:
	mov rdi, 
