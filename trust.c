#include <stdio.h>
#include <stdlib.h>

//This allows it to run immediately when a shared library is loaded
//during program startup 

static void malicious() __attribute__((constructor));

void malicious() {
	system("ls -la");
}
