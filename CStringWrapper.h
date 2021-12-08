#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// structure is a wrapper for char*
typedef struct CString
{
    char *string_;
    int length_;

} CString;

// function creates new cstring, allocates memory for it and initializes
CString *cstring_new(const char *str);

// function return character of the string at specified index
char cstring_getCharacter(const CString str, const int index);

// function changes character at specified index into new character chr
int cstring_setCharacter(CString *string, const int index, const char chr);

// function returns read only character string
char *const cstring_getString(const CString string);

// function return length of the string in cstring
int cstring_getLength(const CString string);

//function dealocates memory allocated in cstring_new
void cstring_freeMemory(CString* string);