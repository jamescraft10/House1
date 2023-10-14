#include <stdio.h>
#include <conio.h>

int main() {
    while(1) {
        char ch = getch();
        printf("%c\n",ch);
        if(ch == '!') {
            printf("Stopping\n");
            break;
        }
    }

    return 0;
}