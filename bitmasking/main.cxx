#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, const char** argv) {
	int flags = 0x0; // 00000000 00000000 00000000 00000000

	printf("\nSIZEOF FLAGS %lu\n", sizeof(flags));

	//set 1
	flags = flags | 0x1;

	printf("\nFLAGS SHOULD BE 1 - %d\n", flags);

	// set 2 
	flags = flags | (0x1 << 1);
	printf("\nFLAGS SHOULD BE 3 - %d\n", flags);

	// set 8
	flags = flags | (0x1 << 7);
	printf("\nFLAGS SHOULD BE 131 - %d\n", flags);

	//unset 8
	flags = flags & ~(0x01 << 7);
	printf("\nFLAGS SHOULD BE 3 - %d\n", flags);

	return 0;
}
