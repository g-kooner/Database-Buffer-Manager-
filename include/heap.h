#ifndef __BPT_H__
#define __BPT_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file.h"
#include "buffer.h"

#define SUCCESS 0
#define FAIL -1

int open_table(char *pathname);
int init_db(int buf_num);
int close_table(int table_id);
int shutdown_db();
int db_insert(int table_id, int64_t key, char *val, int trn_id);
int db_find(int table_id, int64_t key, char *val, int trn_id);
int db_delete(int table_id, int64_t key, int trn_id);
int db_update(int table_id, int64_t key, char *val , int trn_id);

#endif /* __BPT_H__*/
