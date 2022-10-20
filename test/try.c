#include <unistd.h>
#include <string.h>

int main(void)
{
	char *s;
	
	s = "How are you?\n";
	write(1, s, strlen(s));
	return (0);
}
