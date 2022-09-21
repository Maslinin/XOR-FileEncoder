#include "cstmio.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int check_path(const char* path, const char* fileMode);

char* s_gets(char* str, int len)
{
    char* res, *symb;
    res = fgets(str, len, stdin);

    if (res != NULL)
    {
        symb = strchr(res, '\n');
        if (symb != NULL)
            *symb = '\0';
        else
            clear_stdin_buff();
    }

    return res;
}

void clear_stdin_buff(void)
{
    clear_buff(stdin);
}

void clear_buff(FILE* stream)
{
    int pos, ch;

    fseek(stream, 0, SEEK_END);
    pos = ftell(stream);

    if (pos)
    {
        ch = getchar();
        while (ch != '\n' || ch != EOF)
        {
            ch = getchar();
        }
    }
}

char* get_path(char* forPath, int keyLength, const char* fileMode)
{
    FILE* fs = NULL;

    s_gets(forPath, keyLength);
    remove_spaces(forPath);

    if (check_path(forPath, fileMode) == EXIT_FAILURE)
    {
        return NULL;
    }

    return forPath;
}

static int check_path(const char* path, const char* fileMode)
{
    if (strcmp(fileMode, "rb") == 0 && file_exists_check(path) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    if (strcmp(fileMode, "wb") == 0 && check_file_path_availability(path) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int file_exists_check(const char* filePath)
{
    FILE* fs = fopen(filePath, "rb");

    return (fs != NULL && fclose(fs) != EOF) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int check_file_path_availability(const char* filePath)
{
    FILE* fs = fopen(filePath, "wb");

    return (fs != NULL && fclose(fs) != EOF && remove(filePath) == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
