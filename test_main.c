#include "hsh.h"

int main(int ac, char *argv, char **env)
{

        char **test_path = get_path_arr(env);

       		int i = 0; 
		for (i = 0; test_path[i] != NULL; i++)
		{		
		       	printf("%s\n", test_path[i]);
			free(test_path[i]);
		}
		free(test_path[i]);
		free(test_path);
       
        return (0);
}

