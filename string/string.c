// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while(*source) {
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;
	for(i = 0; i < len && source[i] != '\0'; i++)
		destination[i] = source[i];
	while (i < len) {
        destination[i] = '\0';
        i++;
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	size_t dest_len = strlen(destination);
	size_t i;
	for(i = 0; source[i] != '\0'; i++)
		destination[dest_len + i] = source[i];
	destination[dest_len + i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t dest_len = strlen(destination);
	size_t i;
	for(i = 0; i < len && source[i] != '\0'; i++)
		destination[dest_len + i] = source[i];
	destination[dest_len + i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while(*str1 != '\0' && *str2 != '\0'){
		if (*str1 != *str2)
			return (*(const char *)str1 - *(const char *)str2 );
		str1++;
		str2++;
	}
	return (*(const char *)str1 - *(const char *)str2 );
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t k = 0, i;
	while(k == 0 && i < len){
		if (str1[i] < str2[i])
			k = -1;
		else if (str1[i] > str2[i])
			k = 1;
		i++;
	}
	return k;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == (char)c)
			return (char *)str + i;
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = 0;
	char *p = NULL;
	while(str[i] != '\0'){
		if(str[i] == (char)c)
			p = (char *)str + i;
		i++;
	}
	return p;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int i = 0, j, k;
	while(haystack[i] != '\0'){
		if(haystack[i] == *needle){
			j = i;
			k = 0;
			while(haystack[j] == needle[k]){
				j++;
				k++;
			}
			if(needle[k] == '\0')
				return (char *)haystack + i;
		}
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if ((!haystack) || (!needle)) {
        return NULL;
	}
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    if (needle_len == 0)
        return (char *)(haystack + haystack_len);
    if (needle_len > haystack_len)
        return NULL;
    const char *haystack_end = haystack + haystack_len - needle_len;
    while (haystack_end >= haystack) {
        size_t i;
        for (i = 0; i < needle_len; i++) {
            if (haystack_end[i] != needle[i])
                break;
        }
        if (i == needle_len)
            return (char *)haystack_end;
        haystack_end--;
    }
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned char *a = (unsigned char *)destination;
	unsigned char *b = (unsigned char *)source;
	for(size_t i = 0; i < num; i++)
		a[i] = b[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *a = (unsigned char *)destination;
	unsigned char *b = (unsigned char *)source;
	if (a < b){
		for(size_t i = 0; i < num; i++)
			a[i] = b[i];
	} else if (a > b) {
			for(size_t i = num; i > 0; i--)
				a[i - 1] = b[i - 1];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;
	for (size_t i = 0; i < num; i++){
        if (p1[i] < p2[i])
            return -1;
        else if (p1[i] > p2[i])
            return 1;
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *ptr = (unsigned char *)source;
	for(size_t i = 0; i < num; i++)
		ptr[i] = (char)value;
	return source;
}
