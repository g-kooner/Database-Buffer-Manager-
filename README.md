# Database-Buffer-Manager

This project contains a buffer manager system that keeps pages in buffer and replaces them according to a replacement policy (LRU/Clock) from main storage (disk memory). Allows a program to efficiently fetch data and limit expensive calls to disk as much as possible. The table data is stored as heap files (sequential storage). Also are test cases to ensure that buffer manager is correctly accessing files under various scenarios

## Notes
 - Makefile 
 - include/buffer.h 
 - include/heap.h
 - include/file.h
 - src/file.c
 - src/buffer.c
 - src/heap.c
 - src/heapTest.c 
 - src/heapTest.h    
