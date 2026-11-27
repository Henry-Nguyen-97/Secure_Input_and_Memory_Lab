#ifndef SESSION_H
#define SESSION_H

/*
 * Ownership rules:
 *  - session_create() stores its own copy of username. The caller keeps
 *    ownership of the string it passed in and must free it itself.
 *  - The session owns its copy (session->user) and the session_t itself.
 *    session_destroy() frees both, and is the only function that does.
 */
typedef struct session
{
    char *user;
    int access_level;
} session_t;

/* Returns NULL on failure (NULL username or allocation failure). */
session_t *session_create(const char *username);
void session_print(session_t *session);
void session_destroy(session_t *session);

#endif
