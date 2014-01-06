/*typedef int stackEle;

typedef struct stack {
  stackEle *contents; // pointer to the contents of the stack.
  int top; // address of the top element of this stack.
  int size; // size of the stack.
} stack;
*/
typedef struct stack_tag {
  int number;  
  struct list_tag *next; // Pointers to the previous and next elements in the list
} list_elt;


typedef struct commands{
  int pc; 
  char *com; //string representation of the instruction.
  struct commands *prev, *next;
}commands;


int CONST(int r, int value);
int isEmpty();
stack *PUSH (int r);
int POP (int r);
void PRINTNUM ();
stack *ADD();
stack *SUB();
stack *MPY();
stack *DIV();
stack *MOD();
commands *JUMP(int from, int to, commands *start);
commands *LABEL(char *temp, commands *label, int currentPC, commands *first);
