#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *fname : function name
 *argc  : number of WORD size arguments
 **/
void print_stack(char * fname, int argc){
  /* Function for printing calling functions stack frame */
  unsigned int * base_p;
  unsigned int * saved_p;
  unsigned int * stack_p;
  unsigned int * cur;

  //embedded ASM to retrieve base pointer and saved base pointer
  __asm__ __volatile__ ("mov %%ebp, %[base_p]" : 
                        [base_p] "=r" (base_p));
  __asm__ __volatile__ ("mov 0(%%ebp), %[saved_p]" : 
                        [saved_p] "=r" (saved_p));

  //set stack frame info to calling stack frame
  stack_p = base_p;
  base_p = saved_p;

  //output information
  printf("--- STACK %s ---\n",fname);
  for(cur = base_p+argc+1; cur >= stack_p; cur--){
    if (cur == base_p){
      printf("%p <ebp>: %08x\n", cur, *cur);
    }else if (cur <= base_p){
      printf("%p <ebp-0x%x>: %08x\n", cur, 
             (unsigned int) (base_p-cur) * 4, *cur);
    }else{
      printf("%p <ebp+0x%x>: %08x\n", cur, 
             (unsigned int) (cur-base_p) * 4, *cur);
    }
  } 

}

