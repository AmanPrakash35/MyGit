#include <stdio.h>
#include <string.h>

int main()
{
//	char str[] = "sunbeam";
//	int len;
//	len = strlen(str);
//	printf("length : %d\n", len);

//	char str1[20], str2[20] = "sunbeam";
//	strcpy(str1, str2);
//	printf("str1 : %s\n", str1);

//	char str1[20] = "sunbeam", str2[20] = "infotech";
//	strcat(str1, str2);
//	printf("str1 : %s\n", str1);

//	char str1[20] = "ramdeo", str2[20] = "ramraj";
//	int diff;
//	diff = strcmp(str1, str2);
//	printf("diff : %d\n", diff);

//	char str1[20] = "ram", str2[20] = "RAM";
//	int diff;
//	diff = strcasecmp(str1, str2);
//	printf("diff : %d\n", diff);

//	char str[20] = "sunbeam";
//	char *ptr;
//	ptr = strchr(str, 'b');
//	if(ptr == NULL)
//		printf("char not found.\n");
//	else
//		printf("char found at index : %d.\n", ptr-str);

	char str[20] = "sunbeam";
	char *ptr;
	ptr = strstr(str, "am");
	if(ptr == NULL)
		printf("substr not found.\n");
	else
		printf("substr found at index : %d.\n", ptr-str);
	return 0;
}





