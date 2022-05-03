#include "heap.h"
#include "buffer.h"

tablePaths* paths = NULL;
int numOfPaths = 0;

/*
Opens a table at the given path and returns the table id, if the table is already open then return the same id.

Arguments:
	pathname: the path to the table file

Returns:
	The table id as a positive integer if successful, -1 otherwise.

*/
int open_table(char *pathname) {
	//TO DO
} 

/*
Initializes the buffer pool and allocates the buffer frames.

Arguments:
	buf_num: the number of buffer frames

Returns:
	0 if successful, -1 if not.

*/
int init_db(int buf_num) {
    //TO DO
}

/*
Writes any dirty frames to disk, and unpins frames.

Arguments:
	table_id: the id of the table to write and close.

Returns:
	0 if successful, -1 if not.

*/
int close_table(int table_id) {
	//TO DO
}

/*
Shuts down the buffer manager.

Returns:
	0 if successful, -1 if not.

*/
int shutdown_db() {
	//TO DO
}

/*
Inserts a key value pair into the table if it does not exist already.

Arguments:
	table_id: the id of the table to write to
	key: the key being inserted
	val: the value being inserted, this includes the first 4 bytes representing the size

Returns:
	0 if successful, -1 if not.

*/
int db_insert(int table_id, int64_t key, char *val, int trn_id){
	//TO DO
}

/*
Finds a key within the table and stores the value in the given char*

Arguments:
	table_id: the id of the table to write to
	key: the key being searched for
	val: a char pointer to store the found key's value in
	trn_id: can be ignored

Returns:
	0 if successful, -1 if not.

*/
int db_find(int table_id, int64_t key, char *val, int trn_id){
	//TO DO
}

/*
Deletes a record in the table matching the key

Arguments:
	table_id: the id of the table to write to
	key: the key of the record being deleted
	trn_id: can be ignored

Returns:
	0 if successful, -1 if not.

*/
int db_delete(int table_id, int64_t key, int trn_id){
	//TO DO
} 

/*
Updates a record in place

Arguments:
	table_id: the id of the table to write to
	key: the key of the record being deleted
	trn_id: can be ignored

Returns:
	0 if successful, -1 if not.

*/
int db_update(int table_id, int64_t key, char *val , int trn_id){
	//TO DO
} 
