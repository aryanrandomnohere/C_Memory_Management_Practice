#include <stdio.h> 

typedef struct stack {
int count;
int capacity;
void **data;

} stack_t;


stack_t *newStack(int capacity){
stack_t *s  = malloc(sizeof(stack_t));
s->capacity = capacity;
s->count = 0;
s->data = malloc(sizeof(void *) * capacity);
}

void push(stack_t*s, void* data){
    if(s->count == s->capacity) {
        printf("Stack OverFlow");
        return;
    }
    

}

int main(){
    printf("Hello World\n"); //Print_formatted
    stack_t *s = newStack(10);

    return 0;
}



 