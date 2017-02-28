//
// Created by larobyo on 23/02/2017.
//
//

#ifndef LEARNC_MY_STRING_H
#define LEARNC_MY_STRING_H

// copy string from src to dst
void laro_string_copy(char *dst, const char *src);

// get the string length
int laro_string_len(const char *str);

// link src after dst
void laro_string_cat(char *dst, const char *src);

// compare src and dst
// 1. s1 == s2 -> 0
// 2. according to ASCII -> s1 - s2
int laro_string_cmp(const char *s1, const char *s2);

#endif //LEARNC_MY_STRING_H
