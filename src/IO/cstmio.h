#ifndef _CSTMIO_H
#define _CSTMIO_H

#include <stdio.h>

#define CLEAR_STDIN clear_buff(stdin)

char* s_gets(char* str, int len);
void clear_buff(FILE* stream);
char* get_path(char* forPath, int keyLength, const char* file_mode);
int file_exists_check(const char* filePath);
int check_file_path_availability(const char* filePath);

#endif // _CSTMIO_H