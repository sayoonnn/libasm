#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, const char *src);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char *		ft_strdup(const char *s1);

int main() {

	char *str = "Goodbye world!";

	fprintf(stdout, "=== ft_strlen ===\n");
	fprintf(stdout, "example: %s\n\n", str);
	fprintf(stdout, "ft_strlen: %ld\n", ft_strlen(str));
	fprintf(stdout, "strlen: %ld\n", strlen(str));

	char *str2 = "Gello world?";
	fprintf(stdout, "\n=== ft_strcmp ===\n");
	fprintf(stdout, "s1: %s\n", str);
	fprintf(stdout, "s2: %s\n", str2);

	fprintf(stdout, "ft_strcmp: %d\n", ft_strcmp(str, str2));
	fprintf(stdout, "strcmp: %d\n", strcmp(str, str2));

	fprintf(stdout, "\ns1: %s\n", str);
	fprintf(stdout, "s2: %s\n", str);
	fprintf(stdout, "ft_strcmp: %d\n", ft_strcmp(str, str));
	fprintf(stdout, "strcmp: %d\n", strcmp(str, str));


	char dst[42] = {0,};
	fprintf(stdout, "\n=== ft_strcpy ===\n");
	fprintf(stdout, "src: %s\n", str);
	fprintf(stdout, "dst: %s\n\n", dst);

	fprintf(stdout, "ft_strcpy: %s\n", ft_strcpy(dst, str));
	fprintf(stdout, "strcpy: %s\n", strcpy(dst, str));

	fprintf(stdout, "\n=== ft_write ===\n");
	fprintf(stdout, "-fd: 42-\n");

	int errcode = write(42, str, strlen(str)); write(STDOUT_FILENO, "\n", 1);
	fprintf(stdout, "write: %d errno: %d\n", errcode, errno);

	errno = 0;
	errcode = ft_write(42, str, strlen(str)); write(STDOUT_FILENO, "\n", 1);
	fprintf(stdout, "ft_write: %d errno: %d\n", errcode, errno);
	
	fprintf(stdout, "\n-fd: stdout-\n");
	errno = 0;
	errcode = write(STDOUT_FILENO, str, strlen(str)); write(STDOUT_FILENO, "\n", 1);
	fprintf(stdout, "write: %d errno: %d\n\n", errcode, errno);

	errno = 0;
	errcode =ft_write(STDOUT_FILENO, str, strlen(str)); write(STDOUT_FILENO, "\n", 1);
	fprintf(stdout, "ft_write: %d errno: %d\n\n", errcode, errno);
	
	
	fprintf(stdout, "\n=== ft_read ===\n");
	char buf[100] = {0,};
	read(STDIN_FILENO, buf, 100);
	fprintf(stdout, "read: %s\n", buf);
	read(STDIN_FILENO, buf, 100);
	fprintf(stdout, "ft_read: %s\n", buf);

	fprintf(stdout, "\n=== ft_read ===\n");

	char *tmp1 = strdup(str);
	fprintf(stdout, "strdup: %p %s\n", tmp1, tmp1);

	char *tmp2 = ft_strdup(str);
	fprintf(stdout, "ft_strdup: %p %s\n", tmp2, tmp2);

	free(tmp1);
	free(tmp2);

	return 0;
}