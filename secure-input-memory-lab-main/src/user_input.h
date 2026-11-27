#ifndef USER_INPUT_H
#define USER_INPUT_H

/* Longest accepted username, in characters (the NUL is extra). */
#define USERNAME_MAX 31
#define USERNAME_MAX_STR "31" /* must equal USERNAME_MAX */

/* Caller owns the returned string and must free() it. NULL on failure. */
char *read_username(void);

#endif
