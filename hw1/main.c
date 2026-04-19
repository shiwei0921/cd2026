#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 檢查是否為關鍵字並印出
void check_keyword_or_id(char *s) {
    if (strcmp(s, "int") == 0) printf("%s: TYPE_TOKEN\n", s);
    else if (strcmp(s, "main") == 0) printf("%s: MAIN_TOKEN\n", s);
    else if (strcmp(s, "if") == 0) printf("%s: IF_TOKEN\n", s);
    else if (strcmp(s, "else") == 0) printf("%s: ELSE_TOKEN\n", s);
    else if (strcmp(s, "while") == 0) printf("%s: WHILE_TOKEN\n", s);
    else printf("%s: ID_TOKEN\n", s);
}

void scanner(const char *input) {
    int i = 0;
    int n = strlen(input);
    while (i < n) {
        if (isspace(input[i])) { i++; continue; }

        if (isalpha(input[i])) {
            char s[100]; int k = 0;
            while (i < n && (isalnum(input[i]) || input[i] == '_')) s[k++] = input[i++];
            s[k] = '\0';
            check_keyword_or_id(s);
            continue;
        }

        if (isdigit(input[i])) {
            char s[100]; int k = 0;
            while (i < n && isdigit(input[i])) s[k++] = input[i++];
            s[k] = '\0';
            printf("%s: LITERAL_TOKEN\n", s);
            continue;
        }

        if (input[i] == '=' && input[i+1] == '=') { printf("==: EQUAL_TOKEN\n"); i += 2; continue; }
        if (input[i] == '>' && input[i+1] == '=') { printf(">=: GREATEREQUAL_TOKEN\n"); i += 2; continue; }
        if (input[i] == '<' && input[i+1] == '=') { printf("<=: LESSEQUAL_TOKEN\n"); i += 2; continue; }

        switch (input[i]) {
            case '=': printf("=: ASSIGN_TOKEN\n"); break;
            case '>': printf(">: GREATER_TOKEN\n"); break;
            case '<': printf("<: LESS_TOKEN\n"); break;
            case '+': printf("+: PLUS_TOKEN\n"); break;
            case '-': printf("-: MINUS_TOKEN\n"); break;
            case '(': printf("(: LEFTPAREN_TOKEN\n"); break;
            case ')': printf("): RIGHTPAREN_TOKEN\n"); break;
            case '{': printf("{: LEFTBRACE_TOKEN\n"); break;
            case '}': printf("}: RIGHTBRACE_TOKEN\n"); break;
            case ';': printf(";: SEMICOLON_TOKEN\n"); break;
        }
        i++;
    }
}

int main() {
    const char *code = "int main() { int cd2026 = 2026; if (cd2026 >= 0) { cd2026 = cd2026 + 1; } }";
    scanner(code);
    return 0;
}