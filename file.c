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
FILE_OBJECT* open_write_file(const char* filename);
FILE_OBJECT* open_readonly_file(const char* filename);
FILE_OBJECT* open_file(const char* filename, const char* access);
BOOL delete(FILE_OBJECT* file);

// FILE_OBJECT interface
void write_int(int content, FILE_OBJECT* file);
void write_string(const char* content, FILE_OBJECT* file);
int read_int(FILE_OBJECT* file);
const char* read_string(FILE_OBJECT* file);

void change_access(FILE_OBJECT* file);

void close(FILE_OBJECT* file);

int main(int argc, char** argv) {
    FILE_OBJECT* name_file = open_write_file("name_file.txt");
    int value = 20;

    write_string("CollectionMan", name_file);
    printf("File size: %ld\n", name_file->_size);
    close(name_file);

    // FILE_OBJECT* file = open_readonly_file("value.txt");
    name_file = open_readonly_file("name_file.txt");
    // write_int(value, file);

    // change_access(name_file);

    printf("Content: %s\n", read_string(name_file));
    close(name_file);

    delete(name_file);

    return 0;
}

FILE_OBJECT* open_write_file(const char* filename) {
    return open_file(filename, "w");
}

FILE_OBJECT* open_readonly_file(const char* filename) {
    return open_file(filename, "r");
}

FILE_OBJECT* open_file(const char* filename, const char* access_flag) {
    FILE_OBJECT* file = (FILE_OBJECT*) malloc(sizeof(FILE_OBJECT));
    file->_file_access.readonly = !(file->_file_access.write = access_flag == "w" ? YES : NO);    

    FILE* _created_file = fopen(filename, access_flag);
    file->_filename = filename;
    file->_file = _created_file;

    return file;
}

void close(FILE_OBJECT* file) {
    if (file->_file) {
        fclose(file->_file);
    }
}

void write_int(int content, FILE_OBJECT* file) {
    if (file->_file_access.write) {
        fwrite(&content, sizeof(int), 1, file->_file);
        file->_size = ftell(file->_file);
        printf("Saved\n");
    }
}

void write_string(const char* content, FILE_OBJECT* file) {
    if (file->_file_access.write) {
        fwrite(content, sizeof(content), 2, file->_file);
        file->_size = ftell(file->_file);
        printf("Saved\n");
    }
}

int read_int(FILE_OBJECT* file) {
    int buffer;
    if (file->_file_access.readonly) {
        fread(&buffer, file->_size, 1, file->_file);
        printf("Readed!\n");
    }

    return buffer;
}

const char* read_string(FILE_OBJECT* file) {
    char* buffer = malloc(file->_size);
    if (file->_file_access.readonly) {
        fread(buffer, file->_size, 1, file->_file);
        printf("Readed!\n");
    }

    return buffer;
}

void change_access(FILE_OBJECT* file) {
    file->_file_access.readonly = file->_file_access.write;
    file->_file_access.write = !file->_file_access.readonly; 
}

BOOL delete(FILE_OBJECT* file) {
    BOOL success = NO;
    if (remove(file->_filename) == 0) {
        printf("File \"%s\" removed\n", file->_filename);

        file->_file = NULL;
        file = NULL;

        success = YES;
    }

    return success;
}