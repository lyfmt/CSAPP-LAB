#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));

}
void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}
// main function to test the byte printing
int main() {
    int val = 305419896; // Example integer
    float fval = 3.14f; // Example float
    void *ptr = &val; // Example pointer
    printf("Bytes of integer %d:\n", val);
    show_int(val);
    printf("Bytes of float %f:\n", fval);
    show_float(fval);
    printf("Bytes of pointer %p:\n", ptr);
    show_pointer(ptr);
    return 0;
}