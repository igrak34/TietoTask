#include <CStringWrapper.h>

// in main test are being done
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

    printf("ALL TESTS PASSED\n");    
    cstring_freeMemory(test_string);
}