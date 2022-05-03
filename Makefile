.SUFFIXES: .c .o

CC=gcc

SRCDIR=src/
INC=include/
LIBS=lib/

# main source file
TARGET_SRC:=$(SRCDIR)heapTest.c
TARGET_OBJ:=$(SRCDIR)heapTest.o

# Include more files if you write another source file.
SRCS_FOR_LIB:=$(SRCDIR)heap.c $(SRCDIR)file.c $(SRCDIR)buffer.c
OBJS_FOR_LIB:=$(SRCS_FOR_LIB:.c=.o)

CFLAGS+= -g -fPIC -I $(INC)

TARGET=heapTest.out
	
all: $(TARGET)
$(TARGET): $(TARGET_OBJ)
	make static_library
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBS) -ldbBM

clean:
	rm -f $(TARGET) $(TARGET).exe $(TARGET_OBJ) $(OBJS_FOR_LIB) $(LIBS)*.a db_table*

library:
	gcc -shared -Wl,-soname,libdbBM.so -o $(LIBS)libdbBM.so $(OBJS_FOR_LIB)

static_library: $(OBJS_FOR_LIB)
	ar cr $(LIBS)libdbBM.a $(OBJS_FOR_LIB)