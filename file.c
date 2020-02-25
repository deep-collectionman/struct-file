#include <stdio.h>
#include <string.h>
#include <file_object.h>

// FILE_OBJECT Test
void test_create_functions(void);
void test_write_functions(void);
void test_read_functions(void);
void test_change_access_function(void);
void test_delete_function(void);

int main(int argc, char** argv) {
    test_create_functions();
    test_write_functions();
    test_read_functions();
    test_change_access_function();
    test_delete_function();

    return 0;
}

void test_create_functions(void) {
    printf("test_create_functions running ...\n");

    char filename[20];

    printf("Create a file with name: "); 
    scanf("%s", filename);

    FILE_OBJECT* file = open_write_file(filename);

    if (file) {
        printf("File \"%s\" was successfully created\n", file->_filename);
    } else {
        printf("File creation fails\n");
    }

    delete(file);

    printf("test_create_functions end\n\n");
}

void test_write_functions(void) {
    printf("test_write_functions running ...\n");

    FILE_OBJECT* file = open_write_file("test-file.txt");

    char content[140];
    printf("Write the content of the file: "); 
    scanf("%s", content);

    write_string_to(file, content);

    delete(file);

    printf("test_write_functions end\n\n");
}

void test_read_functions(void) {
    printf("test_read_functions running ...\n");

    FILE_OBJECT* file = open_write_file("test-file.txt");

    write_string_to(file, "CollectionMan");

    close(file);

    file = open_readonly_file("test-file.txt");

    if (strcmp(read_string_from(file), "CollectionMan") == 0) printf("Equals!\n");

    delete(file);

    printf("test_read_functions end\n\n");
}

void test_change_access_function(void) {
    printf("test_change_access_function running ...\n");

    FILE_OBJECT* file = open_write_file("test-file.txt");
    change_access(file);

    if (file->_file_access.readonly == YES && file->_file_access.write == NO) printf("Readonly access\n");

    change_access(file);

    if (file->_file_access.readonly == NO && file->_file_access.write == YES) printf("Write access\n");

    delete(file);

    printf("test_change_access_function end\n\n");
}

void test_delete_function(void) {
    printf("test_delete_function running ...\n");

    FILE_OBJECT* file = open_write_file("test-file.txt");

    if (delete(file)) printf("Deleted\n");

    printf("test_delete_function end\n\n"); 
}