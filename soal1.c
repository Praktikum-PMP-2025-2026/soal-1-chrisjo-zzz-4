#include <stdio.h>
#include <string.h>
#define MAX 100

int main (){
    char input[MAX];
    char stack[MAX];
    int top = -1;
    scanf("%s", input);
    if (input == "a"||"b"||"c"||"d"||"e"||"f"||"g"||"h"||"j"||"k"||"l"||"m"||"n"||
    "o"||"p"||"q"||"r"||"s"||"t"||"u"||"v"||"w"||"x"||"y"||"z"||
    "(" && ")" || input == "[" && "]" || input == "{" && "}"){
        printf ("VALID");
    } else {
        printf ("INVALID");
    }
    return 0;
}
