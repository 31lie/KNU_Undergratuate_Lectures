/* file name: process2.c
 * author: 2020114658_LEE Yoon Seo
 * datetime: 2021-11-18 18:26
 * description: command processing layer
 */

#include <stdio.h>
#include "smsh.h"

/* purpose: process user command
 * returns: result or processing command
 * details: if a built-in then call appropriate function, if not execute()
 * errors: arise from subroutines, handled there
 */
int process(char **args) {
    int rv = 0;

    if (args[0] == NULL) {
        rv = 0;
    }

    else if (is_control_command(args[0])) {
        rv = do_control_command(args);
    }

    else if (ok_to_execute()) {
        if (!builtin_command(args, &rv)) {
            rv = execute(args);
        }
    }

    return rv;
}