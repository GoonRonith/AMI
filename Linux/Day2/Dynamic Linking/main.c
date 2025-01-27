#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add)(int, int);
    int (*subtract)(int, int);
    char *error;

    // Load the shared library dynamically
    handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Load the add function
    add = (int (*)(int, int)) dlsym(handle, "add");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Load the subtract function
    subtract = (int (*)(int, int)) dlsym(handle, "subtract");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    // Use the dynamically loaded functions
    printf("Addition: %d\n", add(5, 3));
    printf("Subtraction: %d\n", subtract(5, 3));

    // Close the library
    dlclose(handle);
    return 0;
}
