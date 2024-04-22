char* extractTextFromFile(char filePath[]){
    FILE *file = fopen(filePath, "r");
    char *buffer = NULL;
    long fileContentLength;

    if (file == NULL) {
        printf("File does not exist.\n");
        return NULL;
    }

    // Determine the length of the file
    fseek(file, 0, SEEK_END);
    fileContentLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *)malloc(fileContentLength + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, fileContentLength, 1, file);
    buffer[fileContentLength] = '\0'; 
    fclose(file);

    return buffer;
}

int searchWord(const char *str, const char *word) {
    int i, j;
    int strLength = strlen(str);
    int wordLength = strlen(word);

    for (i = 0; i <= strLength - wordLength; i++) {
        // printf("Checking starting at index %d:\n", i);
        for (j = 0; j < wordLength; j++) {
            // printf("  Comparing '%c' from word with '%c' from string\n", word[j], str[i + j]);
            if (str[i + j] != word[j]) {
                // printf("  Characters don't match. Moving to next starting index.\n");
                break;
            }
        }
        if (j == wordLength) {
            // printf("  Found '%s' starting at index %d.\n", word, i);
            return i; // Word found starting at index i
        }
    }
    // printf("Word not found in the string.\n");
    return -1; // Word not found
}

void findAndReplace(char *str, const char *target, const char *replacement, const char *filePath, int replaceAll) {
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);

    int index = searchWord(str, target);
    do 
    {
    	memmove(str + index + replacementLen, str + index + targetLen, strlen(str + index + targetLen) + 1);
        memcpy(str + index, replacement, replacementLen);
        index = searchWord(str, target);
    }
    while (index != -1 && replaceAll == 1);

    FILE *file = fopen(filePath, "w");

    // Check if file was opened successfully
    if (file != NULL) {
        fprintf(file, "%s", str);
        fclose(file);
        printf("String written to file successfully.\n");
    } else {
        printf("Failed to open file for writing.\n");
    }
}