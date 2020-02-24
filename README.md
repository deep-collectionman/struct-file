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

- ```void write_int(int content, FILE_OBJECT* file);```
- ```void write_string(const char* content, FILE_OBJECT* file);```
- ```int read_int(FILE_OBJECT* file);```
- ```const char* read_string(FILE_OBJECT* file);```

- ```void change_access(FILE_OBJECT* file);```

- ```void close(FILE_OBJECT* file);```
