#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char word[31];
    char definition[1025];
    struct node * next;
}node;

node * create_node(){
    node * new_node = NULL;
    new_node = malloc(sizeof(node));
    if(new_node==NULL){
        printf("Memory allocation: ERROR\n");
        return NULL;
    }

    printf("Enter word and definition (separated by a comma): ");
    scanf("%[^,],%[^\n]", new_node->word, new_node->definition);
    getchar();

    new_node->next = NULL;
    printf("Node created: %s = %s\n", new_node->word, new_node->definition);
    return new_node;
}

node * add_node_at_begining(node * head){
    printf("Adding a new node at the beginning.\n");
    node * new_node = create_node();
    new_node->next = head;
    printf("Node added at the beginning: %s = %s\n", new_node->word, new_node->definition);
    return new_node;
}

void display(node * head){
    printf("Displaying dictionary:\n");
    while(head!=NULL){
        printf("%s = %s\n", head->word, head->definition);
        head = head -> next;
    }
}

char * find_definition(node * head, char * key){
    while(head != NULL){
        if(strcmp(head->word, key) == 0){
            printf("Found definition for '%s': %s\n", key, head->definition);
            return head->definition;
        }
        head = head->next;
    }
    printf("Definition for '%s' not found.\n", key);
    return "-";
}

int main(){

    int nr_cuvinte;
    printf("Enter the number of words: ");
    scanf("%d", &nr_cuvinte);
    getchar(); // Consume newline character after integer input

    node * dictionary = NULL;
    for(int i = 0; i < nr_cuvinte; i++){
        dictionary = add_node_at_begining(dictionary);
    }

    char word_search[31];
    printf("You have to close the program manually.\n");
    while(scanf("%s", word_search) != EOF){
        printf("%s: %s\n", word_search, find_definition(dictionary, word_search));
    }

    return 0;
}

