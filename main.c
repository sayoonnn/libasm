#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);

int main() {

	char *str = "Goodbye world!";

	fprintf(stdout, "=== ft_strlen ===\n");
	fprintf(stdout, "example: %s\n\n", str);
	fprintf(stdout, "ft_strlen: %ld\n", ft_strlen(str));
	fprintf(stdout, "strlen: %ld\n", strlen(str));

	char *str2 = "Hello world?";
	fprintf(stdout, "\n=== ft_strcmp ===\n");
	fprintf(stdout, "s1: %s\n", str);
	fprintf(stdout, "s2: %s\n", str2);

	fprintf(stdout, "ft_strcmp: %d\n", ft_strcmp(str, str2));
	fprintf(stdout, "strcmp: %d\n", strcmp(str, str2));


	char dst[42] = {0,};
	fprintf(stdout, "\n=== ft_strcpy ===\n");
	fprintf(stdout, "src: %s\n", str);
	fprintf(stdout, "dst: %s\n\n", dst);

	fprintf(stdout, "ft_strcpy: %s\n", ft_strcpy(dst, str));
	fprintf(stdout, "strcpy: %s\n", strcpy(dst, str));


	return 0;
}