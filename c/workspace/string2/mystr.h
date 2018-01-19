#ifndef MYSTR_H_
#define MYSTR_H_

#define LWR(c) (c>='A' && c<='Z' ? c+32 : c)

size_t astrlen(const char s[]);
size_t pstrlen(const char *s);
char* pstrcpy(char *d, const char *s);
char* pstrcat(char *d, const char *s);
int pstrcmp(const char *s1, const char *s2);
int pstrcasecmp(const char *s1, const char *s2);
char* pstrchr(const char *s, int ch);
char* pstrstr(const char *s, const char *f);
#endif /* MYSTR_H_ */

