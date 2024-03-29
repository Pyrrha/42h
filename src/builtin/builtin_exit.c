# include <stdlib.h>
# include <unistd.h>
# include <assert.h>
# include <stdio.h>
# include "builtin.h"
# define isinteractive() (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))

int builtin_exit(char *argv[])
{
    long i;
    char *endpointeur;

    assert(argv && argv[0]);
    if (!argv[2])
    {
        fprintf(stderr, "42sh : exit : too many arguments\n");
        return 1;
    }
    i = strtol(argv[1], &endpointeur, 10);
    if (isinteractive())
        fprintf(stderr, "exit\n");
    if (*endpointeur)
        fprintf(stderr, "42sh: exit: %s: numeric argument required\n", argv[1]);
    exit((!endpointeur) ? i : 255);
    return 1;
}
