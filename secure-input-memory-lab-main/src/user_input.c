#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user_input.h"

/*
 * Ownership: the returned string is heap-allocated and owned by the caller,
 * who must free() it exactly once. Returns NULL on EOF, empty input,
 * input longer than USERNAME_MAX characters, or allocation failure.
 */
char *read_username(void)
{
    char buffer[USERNAME_MAX + 1];
    char *username = NULL;
    int next;

    /* Width = buffer size - 1, leaving room for the NUL terminator. */
    if (scanf("%" USERNAME_MAX_STR "s", buffer) != 1)
        return NULL;

    /*
     * A longer token would be cut off by the width above, with the rest
     * left in stdin. Reject it instead of silently truncating a username.
     */
    next = getchar();
    if (next != EOF && !isspace(next))
        return NULL;

    username = malloc(strlen(buffer) + 1);
    if (username == NULL)
        return NULL;

    strcpy(username, buffer);
    return username;
}
