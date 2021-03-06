#ifndef __FILE_H_
#define __FILE_H_

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
// disable byte padding
#pragma pack(push, 1)

#define PAGESIZE 4096
#define HEADERPAGENUM 0

extern int fd;

typedef uint64_t pagenum_t;

//header
typedef struct headerPage_t {
// points the first free page (head of free page list)
// - 0, if there is no free page left.
    pagenum_t freePageNum;
    pagenum_t firstPageNum;
    uint64_t numOfPages;
    char headerPageReserved[PAGESIZE - 24];
} headerPage_t;

typedef struct freePage_t {
//     points the next free page.
//  0, if end of the free page list.
    pagenum_t nextFreePageNum;
    char freePageReserved[PAGESIZE - 8];
} freePage_t;

typedef struct page_t {
    char reserved[PAGESIZE];
} page_t;

// if file already exists, open : return 1 
// if file doesn't exist, create: return 0
int file_open_table(char *pathname);
// Allocate an on-disk page from the free page list
pagenum_t file_alloc_page();
// Free an on-disk page to the free page list
void file_free_page(pagenum_t pagenum);
// Read an on-disk page into the in-memory page structure(dest)
void file_read_page(pagenum_t pagenum, page_t *dest);
// Write an in-memory page(src) to the on-disk page
void file_write_page(pagenum_t pagenum, const page_t *src);

#pragma pack(pop)
#endif /* __FILE_H_*/