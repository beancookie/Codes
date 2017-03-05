//
// Created by larobyo on 23/02/2017.
//

#include <stdio.h>

// copy string from src to dst
void laro_string_copy(char *dst, const char *src)
{
    while (*dst++ = *src++)
        ;
}

// get the string length
int laro_string_len(const char *str)
{
    int index = 0;
    while (*str++)
        index++;
    return index;
}

// link src after dst
void laro_string_cat(char *dst, const char *src)
{
    while (*++dst)
        ;
    while (*dst++ = *src)
        *src++;
}

// compare src and dst
// 1. s1 == s2 -> 0
// 2. according to ASCII -> s1 - s2
int laro_string_cmp(const char *s1, const char *s2)
{
    while (*s1++ != "\0" && *s1 == *s2++)
        ;
    if (*s1)
        return *s1 - *s2;
    else
        return 0;
}