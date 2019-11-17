#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int can_1;
    int *data;
    int can_2;
    size_t size;
    size_t CAP;
    int hash;
} stack;

stack* CONSTRUCTOR(size_t capacity);
void PUSH(stack* current_stack,int value);
int POP(stack* current_stack,int *value);
void DESTRUCTOR(stack* current_stack);
int HASH(stack* current_stack);
int GENERATOR();


stack* CONSTRUCTOR(size_t capacity)
{
    stack* new_stack=(stack*)calloc(1,sizeof(stack));
    if (new_stack == NULL)
    {
        printf("The try to create new stack was failure!/n");
        return NULL;
    }
    new_stack->CAP = capacity;
    new_stack->can_1 = GENERATOR();
    new_stack->can_2 = GENERATOR();
    new_stack->data = (int*)calloc(capacity,sizeof(int));
    if (new_stack->data == NULL)
    {
        printf("The try to create new stack was failure!/n");
        return NULL;
    }
    new_stack->CAP = capacity;
    new_stack->data = (int*)calloc(capacity,sizeof(int));
    new_stack->size = 0;
    new_stack->hash = HASH(new_stack);
    return new_stack;
}

void DESTRUCTOR(stack* current_stack)
{
    free(current_stack->data);
    free(current_stack);
}

void PUSH(stack* current_stack,int value)
{
    if ((current_stack->size)>=(current_stack->CAP))
        printf ("Stack is Full!\n");
    if (HASH(current_stack) != current_stack->hash)
        printf("Unknown changing of stack was discovered!");
    current_stack->data[current_stack->size]=value;
    current_stack->size=current_stack->size+1;
    printf ("SUCCCESS!\n");

}

int POP(stack* current_stack,int *value)
{
    if (current_stack->size!=0)
    {
        printf("Nothing is in stack!\n");
        return NULL;
    }
    else
    {
        if (HASH(current_stack) != current_stack->hash)
            printf("Unknown changing of stack was discovered!");
        *value=current_stack->data[current_stack->size--];
        printf("SUCCCESS\n");
    }
}

int HASH(stack* current_stack)
{
    int *data_1 = current_stack->data;
    int can_1 = current_stack->can_1;
    int can_2 = current_stack->can_2;
    int cap = current_stack->CAP;
    int size = current_stack->size;
    return (int)can_1*712+((int)can_2+2)%19+(int)size*24+((int)cap-6)%4+int(data_1);
}

int GENERATOR()
{
    static int rand_can;
    rand_can = (rand_can*712)%19 + 6;
}

