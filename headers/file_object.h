#ifndef file_object_h
#define file_object_h

#include <stdio.h>
#include <stdlib.h>

typedef enum {NO = 0, YES = 1} BOOL;

// Definition of FILE_OBJECT
typedef struct {
    struct {
        unsigned int write : 1;
        unsigned int readonly : 1;
    } _file_access;

    FILE* _file;
    const char* _filename;
    long int _size;
} FILE_OBJECT;

// Initialization and destruction functions
extern FILE_OBJECT* open_write_file(const char* filename);
extern FILE_OBJECT* open_readonly_file(const char* filename);
extern BOOL delete(FILE_OBJECT* file);

// FILE_OBJECT interface
extern void write_int_to(FILE_OBJECT* file, int content);
extern void write_string_to(FILE_OBJECT* file, const char* content);
extern int read_int_from(FILE_OBJECT* file);
extern const char* read_string_from(FILE_OBJECT* file);

extern void change_access(FILE_OBJECT* file);

extern void close(FILE_OBJECT* file);

#endif /* file_object_h */