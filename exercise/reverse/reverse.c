#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char *val;
    struct Node *next;
} Node;

Node addNode(Node *root, char *val){
    Node *curr = root;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = malloc(sizeof(Node));
    curr=curr->next;
    curr->val = strdu(*val);
    curr->next = NULL;




}
int
main(int argc, char *argv[]){
    if(argc>3){
        fprintf(stderr, "too many arguments\n");
        exit(1);
    }
    char *line = NULL;   // buffer managed by getline
    size_t len = 0;      // capacity, managed by getline
    ssize_t nread;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        printf("Read line (%zd chars): %s", nread, line);
    }
    printf("%s", line);
    free(line);  // only once, at the end
    printf("%s", line);
    printf("done");
    return 0;
}
