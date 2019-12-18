#include <stdio.h>
#include <malloc.h>
#include <time.h>


typedef struct
{
    int can_1 = 0;
    int *data;
    size_t size;
    size_t CAP;
    int hash;
    int can_2 = 0;
} stack;



stack* CONSTRUCTOR(size_t capacity);
void PUSH(stack* current_stack,int value);
int POP(stack* current_stack,int *value);
void DESTRUCTOR(stack* current_stack);
int HASH(stack* current_stack);
int GENERATOR();
void CHECK_CAN(stack* current_stack);
void CHECK_HASH(stack* current_stack);
void DUMP(stack* current_stack);


const int can_1 = GENERATOR();
const int can_2 = GENERATOR();
const int can_3 = GENERATOR();
const int can_4 = GENERATOR();

void mistakes(int i)
{
    char* mistakes[8] = {NULL};

    mistakes[0] = "The try to create new stack was failure!\n";
    mistakes[1] = "The stack was succesfully created\n";
    mistakes[2] = "SUCCESS\n";
    mistakes[3] = "Nothing is in stack!\n";
    mistakes[4] = "Stack was changed!\n";
    mistakes[5] = "Stack is full\n";
    mistakes[6] = "All is OK!\n";
    mistakes[7] = "Stack was deleted!\n";
    mistakes[8] = "Null pointer to stack!";

    printf("%s",mistakes[i]);
}

stack* CONSTRUCTOR(size_t capacity)
{
    stack* new_stack=(stack*)calloc(1,sizeof(stack));

    if (new_stack == NULL)
    {
        mistakes (0);
        return NULL;
    }

    new_stack -> can_1 = can_1;
    new_stack -> can_2 = can_2;

    new_stack->CAP = capacity;
    new_stack->size = 0;
    new_stack->data = (int*)calloc(capacity+2,sizeof(int));

    if (new_stack->data == NULL)
    {
        mistakes(0);
        return NULL;
    }

    new_stack->hash = HASH (new_stack);

    new_stack->data[0] = can_3;
    new_stack->data[capacity + 1] = can_4;

    mistakes(1);
    return new_stack;
}

void DESTRUCTOR(stack* current_stack)
{
    free(current_stack->data);
    free(current_stack);
    mistakes(7);
}

void PUSH(stack* current_stack,int value)
{
    if(current_stack == NULL)
    {
        mistakes(8);
        return;
    }

    if ((current_stack->size)>=(current_stack->CAP))
        mistakes(5);
    else
    {
        current_stack->data[current_stack->size+1] = value;
        current_stack->size = current_stack->size+1;
        mistakes(2);
    }
}

int POP(stack* current_stack)
{
    if(current_stack == NULL)
    {
        mistakes(8);
        return NULL;
    }

    if (current_stack->size == 0)
    {
        mistakes(3);
        return NULL;
    }

    else
    {
        int value = current_stack->data[current_stack->size-- ];
        mistakes(2);
        return value;
    }
}

int HASH(stack* current_stack)
{
    int *data_1 = current_stack->data;
    int cap = current_stack->CAP;
    return (int)data_1*29%7 + ((int)cap-6)*721;
}

int GENERATOR()
{
    int rand_can = rand()*36 + (rand_can*712)%19 + 6;
    return rand_can;
}

void CHECK_CAN(stack* current_stack)
{

    int i = 0;

    if (current_stack->can_1 != can_1)
        i = 1;
    if (current_stack->can_2 != can_2)
        i = 1;
    if (current_stack->data[0] != can_3)
        i = 1;
    if (current_stack->data[current_stack->CAP + 1] != can_4)
        i = 1;

    if (i == 1)
    {
        mistakes(4);
        DESTRUCTOR(current_stack);
    }
    else
        mistakes(6);
}

void CHECK_HASH(stack* current_stack)
{
    if (HASH(current_stack) == current_stack -> hash)
        mistakes(6);
     else
    {
        mistakes(4);
        DESTRUCTOR(current_stack);
    }
}

void DUMP(stack* current_stack)
{
    FILE* pf = fopen("dump.txt","wt");

    for (int i = 0; i < current_stack -> CAP + 2; ++i)
        fprintf(pf, "%i\t", current_stack->data[i]);
}

int main()
{
stack* stack_1 = CONSTRUCTOR(10);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
PUSH(stack_1,17);
DUMP(stack_1);
CHECK_HASH(stack_1);
}

