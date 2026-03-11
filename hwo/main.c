#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ch;
    int count;
    struct Node *next;
} Node;

static void add_or_inc(Node **head, Node **tail, char c) {
    Node *cur = *head;

    // 找看看這個字元是否已存在
    while (cur != NULL) {
        if (cur->ch == c) {
            cur->count++;
            return;
        }
        cur = cur->next;
    }

    // 新字元：新增節點到尾端（保留出現順序）
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    new_node->ch = c;
    new_node->count = 1;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

static void print_list(const Node *head) {
    while (head != NULL) {
        printf("%c : %d\n", head->ch, head->count);
        head = head->next;
    }
}

static void free_list(Node *head) {
    while (head != NULL) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    Node *head = NULL, *tail = NULL;
    int c;

    // 讀到 EOF 為止；若不想統計換行可保留 if
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\r') continue;
        add_or_inc(&head, &tail, (char)c);
    }

    print_list(head);
    free_list(head);
    return 0;
}
