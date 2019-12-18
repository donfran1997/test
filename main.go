package main

/*
#cgo linux CFLAGS: -fplugin=./trust.so

void echo() {
        printf("RWAR");
}
*/
import "C"

func main() {
        C.echo()
        return
}
