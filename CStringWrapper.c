#include "CStringWrapper.h"

CString *cstring_new(const char *str)
{
    int len = strlen(str);
    CString *tmp= (CString*) malloc((len + 1));
    tmp->string_ = (char*) malloc(len + 1);
    memcpy(tmp->string_, str, len);
    tmp->length_ = len;
    return tmp;
}

char cstring_getCharacter(const CString str, const int index)
{
    if (index < str.length_)
        return str.string_[index];
    else
        return 0;
}

int cstring_setCharacter(CString *string, const int index, const char chr)
{
    if (index > string->length_)
        return -1;
    else
    {
        string->string_[index] = chr;
        return 1;
    }
}

char *const cstring_getString(const CString string)
{
    char *const tmp = string.string_;
    return tmp;
}

int cstring_getLength(const CString string)
{
    return string.length_;
}

void cstring_freeMemory(CString *string)
{
    free(string);
}
