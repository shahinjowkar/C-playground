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
printNode(node *root, FILE *output){
    node *dummy = root;
    while(dummy){
        if(dummy != root){
            fprintf(output,"%s",dummy->val);
        }
        dummy = dummy->next;
    }
    fprintf(output, "\n");
}

void
reverse(node* root){
    node *prev = NULL;
    node *curr = root->next;
    while(curr){
        node *dummy = curr->next;
        curr->next = prev;
        prev = curr;
        curr = dummy;
    }
    root->next = prev;
}

int
main(int argc, char *argv[]){

    FILE *input;
    FILE *output;
    
    if(argc > 3){
        fprintf(stderr, "Too many arguments");
        exit(1);
    }
    
    else if(argc == 1){
        input = stdin;
        output = stdout;
    }
    
    else if(argc == 3){
        input = fopen(argv[1],"r");
        if(!input){
            fprintf(stderr,"file does not exists!");
            fclose(input);
            exit(1);
        }
        output = fopen(argv[2], "w");
    }
    else{
        fprintf(stderr, "missing argument");
        exit(1);
    }
    
    node *root = malloc(sizeof(node));
    root->next = NULL;
    root->val = NULL;
    char *buff = NULL;
    size_t size = 0;
    
    while(getline(&buff,&size,input) != -1){
        if(strcmp(buff,"0\n") == 0){
            break;
        }
        addToEnd(root,buff);
    }
    
    free(buff);
    reverse(root);
    printNode(root, output);
    
    if (input  && input  != stdin)  fclose(input);
    if (output && output != stdout) fclose(output);
    
    return 0;
    
}