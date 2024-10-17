#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourceFileName[100], destFileName[100];
    char ch;

    
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);
    
    printf("Enter the destination file name: ");
    scanf("%s", destFileName);

    
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

  
    destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return EXIT_FAILURE;
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("Contents copied from %s to %s successfully.\n", sourceFileName, destFileName);

  
    fclose(sourceFile);
    fclose(destFile);

    return EXIT_SUCCESS;
}
