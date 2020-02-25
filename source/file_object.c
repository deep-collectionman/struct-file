#include <file_object.h>

FILE_OBJECT* open_file(const char* filename, const char* access_flag) {
    FILE_OBJECT* file = (FILE_OBJECT*) malloc(sizeof(FILE_OBJECT));
    file->_file_access.readonly = !(file->_file_access.write = access_flag == "w" ? YES : NO);    

    FILE* _created_file = fopen(filename, access_flag);
    file->_filename = filename;
    file->_file = _created_file;

    return file;
}

FILE_OBJECT* open_write_file(const char* filename) {
    return open_file(filename, "w");
}

FILE_OBJECT* open_readonly_file(const char* filename) {
    return open_file(filename, "r");
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
        fwrite(content, sizeof(content), sizeof(content), file->_file);
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