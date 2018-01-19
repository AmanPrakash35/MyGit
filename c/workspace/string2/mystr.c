#include <stdio.h>
#include "mystr.h"

size_t astrlen(const char s[])
{
	int cnt=0, i;
	for(i=0; s[i]!='\0'; i++)
		cnt++;
	return cnt;
}
size_t pstrlen(const char *s)
{
	int cnt = 0;
	char *p = s;
	while(*p != '\0')
	{
		cnt++;
		p++;
	}
	return cnt;
}
char* pstrcpy(char *d, const char *s)
{
	char *p = d;
	while(*s != '\0')
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return p;
}
char* pstrcat(char *d, const char *s)
{
	char *p = d;
	while(*d != '\0')
		d++;
	pstrcpy(d, s);
	return p;
}
int pstrcmp(const char *s1, const char *s2)
{
	while(*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
int pstrcasecmp(const char *s1, const char *s2)
{
	while(LWR(*s1) == LWR(*s2) && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (LWR(*s1) - LWR(*s2));
}
char* pstrchr(const char *s, int ch)
{
	while(*s != '\0')
	{
		if(*s == ch)
			return s;
		s++;
	}
	return NULL;
}
int pstrncmp(const char *s1, const char *s2, int n)
{
	int i=0;
	while(i < n && *s1 == *s2 && *s1 != '\0')
	{
		i++;
		s1++;
		s2++;
	}
	return i==n ? 0 : (*s1 - *s2);
}
char* pstrstr(const char *s, const char *f)
{
	int diff, len = pstrlen(f);
	while(*s != '\0')
	{
		diff = pstrncmp(s, f, len);
		if(diff == 0)
			return s;
		s++;
	}
	return NULL;
}










