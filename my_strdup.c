#include <stdlib.h>
#include <string.h>

/**
* my_strdup - duplicate string
*
* @str:input
* Return:duplicated string
*/
char *my_strdup(const char *str)
{
size_t len = strlen(str);
char *dup_str = malloc(len + 1);
if (dup_str != NULL)
{
strcpy(dup_str, str);
}
return dup_str;
}
