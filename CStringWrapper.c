
/* Zaprojektuj CString. Ma być to tylko wrapper na char*.
Pobranie długości ma być w czasie O(1)
Pobranie dowolnego znaku ma być w czasie O(1)
Zmiana dowolnego znaku ma być w czasie O(1)
Pobranie całego ciągu znaków również ma być w czasie O(1). 
Ale mamy uniemożliwić zmianę znaków po pobraniu go. (zmieniamy tylko za pomocą funkcji z punktu powyżej) */

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
CString *cstring_new(const char *str)
{
    int len = strlen(str);
    CString *tmp = malloc((len + 1) + sizeof(int));
    tmp->string_ = malloc(len + 1);
    memcpy(tmp->string_, str, len);
    tmp->length_ = len;
    return tmp;
}

// function return character of the string at specified index
char cstring_getCharacter(const CString str, const int index)
{
    if (index < str.length_)
        return str.string_[index];
    else
        return 0;
}

// function changes character at specified index into new character chr
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

// function returns read only character string
char *const cstring_getString(const CString string)
{
    char *const tmp = string.string_;
    return tmp;
}

// function return length of the string in cstring
int cstring_getLength(const CString string)
{
    return string.length_;
}

int main(void)
{
    CString *test_string;
    test_string = cstring_new("test"); // new test string to test all functions

    // testing function cstring_new
    assert(strcmp(test_string->string_, "test") == 0);
    assert(test_string->length_ == strlen("test"));

    //testing function cstring_getCharacter
    assert(cstring_getCharacter(*test_string, 0) == 't');
    assert(cstring_getCharacter(*test_string, 1) == 'e');
    assert(cstring_getCharacter(*test_string, 2) == 's');
    assert(cstring_getCharacter(*test_string, 3) == 't');
    assert(cstring_getCharacter(*test_string, 8) == 0);

    //testing function cstring_setCharacter
    cstring_setCharacter(test_string, 0, 'a');
    assert(strcmp(test_string->string_, "aest") == 0);

    //testing function cstring_getLength
    assert(cstring_getLength(*test_string) == 4);

    //testing function cstring_getString
    char *const str = cstring_getString(*test_string);
    assert(strcmp(str, test_string->string_) == 0);
    // now trying to change character
    str[2] = 'H'; //should take no effect because str is read only
    assert(strcmp(str, test_string->string_) == 0);
}