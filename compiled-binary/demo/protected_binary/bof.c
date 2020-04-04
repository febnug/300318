#include <string.h>
#include <stdio.h>

int main (int argc, char **argv) { 
        char bof[90];
	printf("eip di fungsi main() pada stack frame ada pada alamat %p\n", bof+2);
	if (argc > 1) {
		strcpy(bof, argv[1]);
		printf("kamu mengatakan : %s\n", bof);
	}
	return(0);
}
