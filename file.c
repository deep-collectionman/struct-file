#include <file_object.h>

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

