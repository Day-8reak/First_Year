#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char lol[] = "FOOBAR";
	char resultss[4];
	int len1 = strlen(lol);
    sprintf(resultss, "%c%c%c", lol[0], lol[1], lol[2]);

	printf("%s %zu %d \n", lol, sizeof(len2), len1);
	
}
