#include "main.h"
#include <stdio.h>

int main(void)
{
	char xchar = 'H';
	char *ystring = "How are you?\n";
	
	printf("%c, %s\n", xchar, ystring);
	_printf("%c, %s", xchar, ystring);
	return (0);
}
