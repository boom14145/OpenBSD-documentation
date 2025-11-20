#include <stdio.h>
#include <stdlib.h>
#include<sys/mman.h>

int
main()
{
	void *ptr = malloc(4096);
	if (ptr == NULL) {
		printf("MEMORY allocation failed\n");
		return 1;
	}
	if (madvise(ptr, 4096, MADV_RANDOM) != 0) {
		printf("madvise failed!\n");
		free(ptr);
		return 1;
	}
	printf("madvise call was successful!\n");
	free(ptr);
	return 0;
}
