# struct-file
A struct encapsulating the C type FILE and also provide an interface functionality in the header file.

FILE_OBJECT (_FILE_ACCESS, _FILE, _FILENAME, _SIZE)

- ```struct _file_access```
- ```FILE* _file```
- ```const char* _filename```
- ```long int _size```

-------------------------------------------------------------------------------------------------------------------------------

- ```FILE_OBJECT* open_write_file(const char* filename);```
- ```FILE_OBJECT* open_readonly_file(const char* filename);```
- ```FILE_OBJECT* open_file(const char* filename, const char* access);```
- ```BOOL delete(FILE_OBJECT* file);```

- ```void write_int_to(FILE_OBJECT* file, int content);```
- ```void write_string_to(FILE_OBJECT* file, const char* content);```
- ```int read_int_from(FILE_OBJECT* file);```
- ```const char* read_string_from(FILE_OBJECT* file);```

- ```void change_access(FILE_OBJECT* file);```

- ```void close(FILE_OBJECT* file);```
