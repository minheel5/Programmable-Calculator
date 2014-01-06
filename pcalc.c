#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcalc.h"

int reg[8];
//stack *s;
commands *l;

int CONST (int r, int value){
	reg[r] = value;
	return reg[r];
}

int isEmpty(stack *first_elt){
	if((s) == NULL) return -1;
	else return 1;
}

stack *PUSH (stack *first_elt, int number)
{
  stack *elt;

  elt = malloc (sizeof(*elt));


  if (elt == NULL) {
    printf ("Couldn't allocate a new list element\n");
    exit (1);
  }
  elt->number = number;
  
  elt->prev = NULL;
  elt->next = first_elt;

  if (first_elt != NULL)
    first_elt->prev = elt;

  return elt;
}

stack *POP (stack *first_elt)
{
  stack *next;

  if (first_elt == NULL) return first_elt;

  next = first_elt->next;

  free (elt);
  return next;
}

void PRINTNUM (stack *first_elt){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	printf("top = %d", first_elt->number);
}

stack *ADD(){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	int first = POP(1);
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack has only one element.");
		exit(1);
	}
	int second = POP(2);
	int val = first + second;
	reg[3] = val;
	s = PUSH(3);
	return s;	
}

stack *SUB(){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	int first = POP(1);
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack has only one element.");
		exit(1);
	}
	int second = POP(2);
	int val = first - second;
	reg[3] = val;
	s = PUSH(3);
	return s;	
}

stack *MPY(){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	int first = POP(1);
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack has only one element.");
		exit(1);
	}
	int second = POP(2);
	int val = first * second;
	reg[3] = val;
	s = PUSH(3);
	return s;	
}

stack *DIV(){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	int first = POP(1);
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack has only one element.");
		exit(1);
	}
	int second = POP(2);
	int val = first / second;
	reg[3] = val;
	s = PUSH(3);
	return s;	
}

stack *MOD(){
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack is empty.");
		exit(1);
	}
	int first = POP(1);
	if(isEmpty() == -1) {
		 printf ("%s \n", "The stack has only one element.");
		exit(1);
	}
	int second = POP(2);
	int val = first % second;
	reg[3] = val;
	s = PUSH(3);
	return s;	
}

commands *JUMP(int from, int to, commands *start) {
  int diff;
  int i;
  int j;
  diff = from - to;
  if(diff < 0){
    diff = -1 * diff;
    for (i = 0; i < diff; i++){
	start = start->next;
    }
  }
  else{
    for (j = 0; j < diff; j++){
	start = start->prev;
    }	
  }
  return start;
}
								         		

commands *LABEL(char *temp, commands *label, int currentPC, commands *first){
  if(label == NULL){
    printf("%s\n", "No label to return to");
  }
  else{
    while(strcmp(label->com, temp) != 0){
      if(label == NULL){
	printf("%s\n", "No label to return to");
	break;
      }	
      if(strcmp(label->com, temp) == 0){
	first = JUMP(currentPC, label->pc, first);
      }
      label = label->next;
   }
  }
  return first;				
}



int main(){
	stack *first_elt = NULL;
	
	CONST(1,1);
	PUSH(first_elt, 1);
	PRINTNUM(first_elt);
	free(first_elt);
	
	return 0;
}

/*
	commands *first = NULL;
	first = malloc(sizeof(*first));
	commands *label = NULL;
	label = malloc(sizeof(*first));

	FILE *fp;
	int index = 0;

	if((fp = fopen("test.rpn", "r")) == NULL){
  	  printf("%s \n", "Error opening file");
 	}

	  char line [20];
	  while ( fgets (line , 20 , fp) != NULL ){
    	   	puts (line);
		commands *c;
		c = malloc(sizeof(*c));
		c->com = malloc(strlen(line) + 1); 
		strcpy (c->com, line);
		c->pc = index;
		c->prev = NULL;
		c->next = first;
		if (first != NULL){
		  first->prev = c;
		}
		index = index + 1;
		
	  }
	fclose (fp);

	while(first->next != NULL){
		first = first->next;
		char *inst;
		inst = malloc(sizeof(*inst));
		int regValue;
		int constant;
		int PClabel;
		PClabel = -1;
		int currentPC;
		char *labelString;
		char *command = first->com;
		command = malloc(sizeof(*command));
		if(sscanf(command, "%s %*s", *inst) == 1){
	  	if(strcmp(inst,"CONST") == 0){
			if(sscanf(command, "i% i%", &regValue, &constant) == 2){
				CONST(regValue, constant);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		else if(strcmp(inst,"PUSH") == 0){
			if(sscanf(command, "i%", &regValue) == 1){
				PUSH(regValue);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		else if(strcmp(inst,"POP") == 0){
			if(sscanf(command, "i%", &regValue) == 1){
				POP(regValue);
			}
		}
		else if(strcmp(inst,"PRINTNUM") == 0){
			PRINTNUM();
		}
		else if(strcmp(inst,"ADD") == 0){
			ADD();
		}
		else if(strcmp(inst,"SUB") == 0){
			SUB();
		}
		else if(strcmp(inst,"MPY") == 0){
			MPY();
		}
		else if(strcmp(inst,"DIV") == 0){
			DIV();
		}
		else if(strcmp(inst,"MOD") == 0){
			MOD();
		}
		else if(strcmp(inst,"LABEL") == 0){
			labelString = malloc(sizeof(*labelString));
			if(sscanf(command, "%s", labelString) == 1){
				commands *c;
				c = malloc(sizeof(*c));
				c->com = malloc(strlen(line) + 1); 
				strcpy (c->com, labelString);
				c->pc = first->pc;
				c->prev = NULL;
				c->next = label;
				if (label != NULL){
				  first->prev = c;
				}
				free(c);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
			free(labelString);
		}
		else if(strcmp(inst,"JSR") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));

			if(sscanf(command, "%s", temp) == 1){
				currentPC = first->pc;
				first = LABEL(temp, label, currentPC, first);		
			}
			else{
				printf("%s\n", "Not a valid command");
			}
			free(temp);
		}

		else if(strcmp(inst,"JMPR") == 0){
			if(sscanf(command, "i%", &regValue) == 1){
				int newPC;
				newPC = reg[regValue];
				if(newPC < 0 || newPC > 200){
				  printf("%s\n", "Out of bounds PC value.");
				}
				else{
				  first = JUMP(first->pc, newPC, first);
				}			
			}
		}
		else if(strcmp(inst,"BRANCHn") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));
			if (sscanf(command, "%i/%S", &regValue, temp) == 2 && regValue > -1 && regValue < 8){
			  int val;
			  val = reg[regValue];
			  if (val < 0){
			    currentPC = first->pc;
			    first = LABEL(temp, label, currentPC, first);
			  }
			  free(temp);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}

		else if(strcmp(inst,"BRANCHz") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));
			if (sscanf(command, "%i/%S", &regValue, temp) == 2 && regValue > -1 && regValue < 8){
			  int val;
			  val = reg[regValue];
			  if (val == 0){
			    currentPC = first->pc;
			    first = LABEL(temp, label, currentPC, first);
			  }
			  free(temp);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		else if(strcmp(inst,"BRANCHp") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));
			if (sscanf(command, "%i/%S", &regValue, temp) == 2 && regValue > -1 && regValue < 8){
			  int val;
			  val = reg[regValue];
			  if (val > 0){
			    currentPC = first->pc;
			    first = LABEL(temp, label, currentPC, first);
			  }
			  free(temp);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		else if(strcmp(inst,"BRANCHnz") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));
			if (sscanf(command, "%i/%S", &regValue, temp) == 2 && regValue > -1 && regValue < 8){
			  int val;
			  val = reg[regValue];
			  if (val <= 0){
			    currentPC = first->pc;
			    first = LABEL(temp, label, currentPC, first);
			  }
			  free(temp);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		else if(strcmp(inst,"BRANCHzp") == 0){
			char *temp;
			temp = malloc(sizeof(*temp));
			if (sscanf(command, "%i/%S", &regValue, temp) == 2 && regValue > -1 && regValue < 8){
			  int val;
			  val = reg[regValue];
			  if (val >= 0){
			    currentPC = first->pc;
			    first = LABEL(temp, label, currentPC, first);
			  }
			  free(temp);
			}
			else{
				printf("%s\n", "Not a valid command");
			}
		}
		
		}
	free(command);
	free(inst);	
	}
	free(first);
	free(label);
	return 0;


return 0;
}*/
