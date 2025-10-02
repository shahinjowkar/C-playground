#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char *val;
    struct node *next;
} node;

node *
addToEnd(node *root, char *val){
    node *dummy= root;
    while(dummy->next){
        dummy = dummy->next;
    }
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->val = strdup(val);   
    dummy->next = newNode;
    return root;
}

void
printNode(node *root){
    node *dummy = root;
    while(dummy){
        if(dummy != root){
            printf("->%s",dummy->val);
        }
        dummy = dummy->next;
    }
    printf("\n");
}

void *
reverse(node* root){
    node *prev = root;
    node *curr = root->next;
    while(curr){
        node *dummy = curr->next;
        // printf("%s\n",dummy->val);
        curr->next = prev;
        // printf("%s\n",curr->next->val);
        prev = curr;
        // printf("%s\n",prev->val);
        curr = dummy;
        // printf("%s\n",curr->val);
    }
    return curr;
}

int
main(int argc, char *argv[]){
    node *root = malloc(sizeof(node));
    root->val = NULL;
    root->next = NULL;
    addToEnd(root, "node1");
    addToEnd(root, "node2");
    addToEnd(root, "node3");
    printNode(root);
    root = reverse(root);
    printf("%s\n",root->next->val);
    printNode(root);

}