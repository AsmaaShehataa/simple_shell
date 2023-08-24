#include "hsh.h"

int __exit(char *user_input)
{
	free(user_input);
	return (0);
}
