#include<stdio.h>
#include<string.h>

int main() {
    char str[] = "abchsjdhsk";
    char toRemove[] = "abc";
    int lenToRemove = strlen(toRemove); // calcutlate the length of string that need to be moved 
    char *p = str; // pointer to the original string
    char *q = str; // a pointer to build the final string
    int found;

    while (*p != '\0') {
        found = 1;
        for (int i = 0; i < lenToRemove; i++) {
            if (p[i] != toRemove[i]) {
                found = 0;
                break;
            }
        }

        if (found) {
            p += lenToRemove; // if find the target, then skip it 
        } else {
            *q = *p; // otherwise, copy the string to a new location
            q++;
            p++;
        }
    }
    *q = '\0'; // make sure the new string ends with a null char

    printf("%s\n", str); // print the final string
    return 0;
}
