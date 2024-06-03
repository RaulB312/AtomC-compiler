#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "utils.h"

void err(const char *fmt,...){
    fprintf(stderr,"error: ");
    va_list va;
    va_start(va,fmt);
    vfprintf(stderr,fmt,va);
    va_end(va);
    fprintf(stderr,"\n");
    exit(EXIT_FAILURE);
}

void *safeAlloc(size_t nBytes){
    void *p=malloc(nBytes);
    if(!p)err("not enough memory");
    return p;
}

char* loadFile(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate buffer for file content
    char *buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Could not allocate memory");
        fclose(file);
        return NULL;
    }

    // Read file content into buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Could not read file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Null-terminate the buffer
    buffer[fileSize] = '\0';

    fclose(file);
    return buffer;
}