#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "make_log.h"
#include "hiredis.h"
#include "redis_op.h"

int main(int argc, char *argv[])
{

    redisContext *conn = NULL;
    char *ip = "127.0.0.1";
    char *port = "6379";
    conn = rop_connectdb_nopwd(ip, port);
    if(conn == NULL) {
        exit(1);
    }
    printf("connect succ\n");
    rop_redis_get(conn, "itcast");

    rop_disconnect(conn);

	return 0;
}
