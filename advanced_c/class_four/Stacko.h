
//--------------STACKO.H   OWNER--------------------------------------------------
typedef struct Box {
  struct Box *next;
  char val[i];
} Box;

typedef struct {
  Box * head;
  int eltSize;
} Stack;

Stack *createStack(int eltSize); // returns a pointer so its good
void destroyStack(Stack *s);
void pop(Stack *s);
int top(Stack *s);
void push(Stack *s, int element);
