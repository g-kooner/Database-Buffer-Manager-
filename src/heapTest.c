#include "heap.h"
#include "file.h"
#include "heapTest.h"
#include "buffer.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main( int argc, char ** argv ) {
	srand(10);
	if (access("db_table0", F_OK) == 0) {
		printf("\ndb_table0 found in directory, testing on re-opened file...\n\n");

		printf("Starting tests...\n");

		//open a table then reopen to verify the same id is returned
		printf("Testing open_table... ");
		int table_id = open_table("db_table0");
		assert(open_table("db_table0") == table_id);
		printf("passed!\n");

		//initialize db with 10 buffer frames
		printf("Testing init_db... ");
		assert(init_db(10) == 0);
		printf("passed!\n");

		//find the records
		printf("Testing db_find on the existing records... ");
		char *tempChar = (char*)malloc(sizeof(int) + 13*sizeof(char));
		for (int i = 178/2; i < 178; i++){
			assert(db_find(table_id, (int64_t)i, tempChar, 0) == 0);
			valueRec_t value = {13, "lmnopqrstuvwx"};
			assert(strcmp((char*)&value, tempChar) == 0);
		}
		free(tempChar);
		printf("passed!\n");

		//flush/close table
		printf("Testing close_table... ");
		assert(close_table(table_id) == 0);
		printf("passed!\n");

		//shutdown the db
		printf("Testing shutdown_db... ");
		assert(shutdown_db() == 0);
		printf("passed!\n");
	} 
	else {
	    printf("\ndb_table0 does not exist in directory, testing on newly created file...\n\n");

	    printf("Starting tests...\n");

	    //open a table then reopen to verify the same id is returned
		printf("Testing open_table... ");
		int table_id = open_table("db_table0");
		assert(open_table("db_table0") == table_id);
		printf("passed!\n");

		//initialize db with 10 buffer frames
		printf("Testing init_db... ");
		assert(init_db(10) == 0);
		printf("passed!\n");

		//insert key+val with size greater than 4094
		printf("Testing db_insert with oversized record... ");
		valueRec_t largevalue = {5000, "N/A"};
		assert(db_insert(table_id, 1, (char*)&largevalue, 0) == -1);
		printf("passed!\n");

		//verify that the large record was not inserted
		printf("Testing db_find with oversized record... ");
		char *tempChar = (char*)malloc(sizeof(int) + 11*sizeof(char));
		assert(db_find(table_id, 1, tempChar, 0) == -1);
		printf("passed!\n");

		//insert enough keys/values to fill table
		printf("Testing db_insert with records to fill table... ");
		for (int i = 0; i < 178; i++){
			valueRec_t value = {11, "abcdefghijk"};
			assert(db_insert(table_id, (int64_t)i, (char*)&value, 0) == 0);
			assert(db_find(table_id, (int64_t)i, tempChar, 0) == 0);
			assert(strcmp((char*)&value, tempChar) == 0);
		}
		printf("passed!\n");

		//use db_find to find the keys
		printf("Testing db_find with full table... ");
		for (int i = 0; i < 10; i++){
			int randKey = rand() % 178;
			assert(db_find(table_id, (int64_t)randKey, tempChar, 0) == 0);
		}
		printf("passed!\n");

		//update the other half
		printf("Testing db_update with smaller values on the first half of the records... ");
		for (int i = 0; i < 178/2; i++){
			valueRec_t value = {9, "lmnopqrst"};
			assert(db_update(table_id, (int64_t)i, (char*)&value, 0) == 0);
			assert(db_find(table_id, (int64_t)i, tempChar, 0) == 0);
			assert(strcmp((char*)&value, tempChar) == 0);
		}
		printf("passed\n");

		//update the other half
		printf("Testing db_update with larger values on the latter half of the records... ");
		for (int i = 178/2; i < 178; i++){
			valueRec_t value = {13, "lmnopqrstuvwx"};
			assert(db_update(table_id, (int64_t)i, (char*)&value, 0) == 0);
			assert(db_find(table_id, (int64_t)i, tempChar, 0) == 0);
			assert(strcmp((char*)&value, tempChar) == 0);
		}
		printf("passed!\n");

		//delete half the keys
		printf("Testing db_delete on half the records... ");
		for (int i = 0; i < 178/2; i++){
			assert(db_delete(table_id, i, 0) == 0);
			assert(db_find(table_id, (int64_t)i, tempChar, 0) == -1);
		}
		free(tempChar);
		printf("passed!\n");

		//flush/close table
		printf("Testing close_table... ");
		assert(close_table(table_id) == 0);
		printf("passed!\n");

		//shutdown the db
		printf("Testing shutdown_db... ");
		assert(shutdown_db() == 0);
		printf("passed!\n");
	}
}
