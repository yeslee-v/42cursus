#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
/*
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
*/
# define BUFFER_SIZE 512

ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *s);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int		strlen_test(char *str)
{
	int 	ret1;
	int 	ret2;

	if (str == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("str: %s|\n👉 strlen : %d / ft_strlen : %d\n\n", str, ret1, ret2);
/*	if (ret1 == ret2)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	return (1);
}

int		strcpy_test(char *src)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	if (src == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}
	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	printf("strcpy : %s| / ft_strcpy : %s|\n\n", dest1, dest2);
/*	if (!strcmp(dest1, dest2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	int 	ret1;
	int 	ret2;

	if (s1 == NULL || s2 == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}
	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	printf("strcmp : %d / ft_strcmp : %d\n\n", ret1, ret2);
/*	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 == 0))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	return (1);
}

int		write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

/*	if (str == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}*/
	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("write : %s| / ft_write : %s|\n\n", buf, str);
/*	if (!strcmp(buf, str))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (1);
}

int		read_test(char *str)
{
	int		ft_read_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

/*	if (str == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}*/
	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_read_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_read_pipe[1], str, strlen(str));
	ret = ft_read(ft_read_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("read : %s| / ft_read : %s|\n\n", buf, str);
/*	if (!strcmp(buf, str))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	close(ft_read_pipe[1]);
	close(ft_read_pipe[0]);
	return (1);
}

int		strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	if (str == NULL)
	{
		printf("this is error: NULL\n");
		exit(0);
	}
	str1 = ft_strdup(str);
	str2 = strdup(str);
	printf("strdup: %s| / ft_strdup : %s|\n\n", str1, str2);
/*	if (!strcmp(str1, str2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");*/
	free(str1);
	free(str2);
	return (1);
}

int		main(void)
{
	
	// FT_STRLEN

	printf("%s", "\n------[ ft_strlen.s ]------\n\n");
	strlen_test("yeslee");
	strlen_test("");
	strlen_test("hello world");
	strlen_test("42 \0 seoul");
	strlen_test("I'm on the edge of glory, And I'm hanging on a moment of truth");
	strlen_test("        ");
	printf("\n---------------------------");
	printf("\n\n");


	// FT_STRCPY

	printf("%s", "\n------[ ft_strcpy.s ]-----\n\n");
	strcpy_test("assembly");
	strcpy_test("");
	strcpy_test("hello world");
	strcpy_test("42 \0 seoul");
	strcpy_test("this is ft_strcpy");
	strcpy_test("I'm on the edge of glory, And I'm hanging on a moment of truth");
	strcpy_test("        ");
	printf("\n---------------------------");
	printf("\n\n");


	// FT_STRCMP

	printf("%s", "\n------[ ft_strcmp.s ]------\n\n");
	strcmp_test("ji-kim", "ji-kim");
	strcmp_test("abcdef", "zcdef");
	strcmp_test("", "wtf");
	strcmp_test("this is ft_strcmp", "   ");
	strcmp_test("", "");
	strcmp_test("42seoul", "");
	strcmp_test("ai\0", "\0");
	strcmp_test("\xff\xff", "\xff\xff");
	strcmp_test("\xff\x80", "\xff\x00");
	strcmp_test("\xff\xfe", "\xff");
	strcmp_test("I'm on the edge of glory, And I'm hanging on a moment of truth", "I'm on the edge of glory, And I'm hanging on a moment of truth");
	printf("\n---------------------------");
	printf("\n\n");


	// FT_WRITE

	printf("%s", "\n------[ ft_write.s ]------\n\n");
	write_test("");
	write_test("test");
	write_test("test ft_write");
	write_test("test 42 \0 seoul");
	printf("\n---------------------------");
	printf("\n\n");


	// FT_READ

	printf("%s", "\n------[ ft_read.s ]------\n\n");
	read_test("hello");
	read_test("nice to meet you");
	read_test("nice \0 to meet you");
	read_test("");
	read_test("I'm on the edge of glory, And I'm hanging on a moment of truth");
	printf("\n---------------------------");
	printf("\n\n");


	// FT_STRDUP

	printf("%s", "\n------[ ft_strdup.s ]------\n\n");
//	strdup_test(NULL);
	strdup_test("hola");
	strdup_test("hi hello");
	strdup_test("");
	strdup_test("42 \0 seoul");
	strdup_test("I'm on the edge of glory, And I'm hanging on a moment of truth");
	printf("\n---------------------------");
	printf("\n");

}
