#include <stdio.h>
#include <stdlib.h>

int *A;
int *B;
int *C;
int *D;

void decrement_reg(int *reg) {
  *reg -= 1;
}

void increment_reg(int *reg) {
  *reg += 1;
}

void add_a_to_c() {
  printf("\nAdding A to C\n");
  while(1 == 1) {
    if(A == 0) {
      break;
    } else {
      printf("C := %d | A := %d\n", C, A);
      increment_reg(&C);
      printf("C := %d | A := %d\n", C, A);
      decrement_reg(&A);
      printf("C := %d | A := %d\n", C, A);
    }
  }
}

void add_b_to_a_with_d() {
  printf("\nAdding B to A with D\n");
  set_0_to_reg('D', &D);
  
  while(1 == 1) {
    if(B == 0) {
      break;
    } else {
      printf("B := %d | A := %d | D := %d\n", B, A, D);
      increment_reg(&A);
      printf("B := %d | A := %d | D := %d\n", B, A, D);
      increment_reg(&D);
      printf("B := %d | A := %d | D := %d\n", B, A, D);
      decrement_reg(&B);
      printf("B := %d | A := %d | D := %d\n", B, A, D);
    }
  }

  while(1 == 1) {
    if(D == 0) {
      break;
    } else {
      increment_reg(&B);
      decrement_reg(&D);
    }
  }
}

void set_0_to_reg(char name, int *reg) {
  while(1 == 1) {
    if(*reg == 0) {
      break;
    } else {
      decrement_reg(&reg);
      if(*reg == 0) {
        break;
      }
    }
  }
}

void set_n_to_reg(char name, int *reg, int number) {
  printf("\nSetting %c to %d\n", name, number);
  set_0_to_reg(name, reg);
  
  int cont = number;
  
  if(number < 0) {
    *reg = 1;
  }
  
  while(1 == 1) {
    if(cont == 0) {
      break;
    } else {
      *reg += 1;
      printf("%c := %d\n", name, *reg);
      cont = cont - 1;
    }
  }
}

void mult_a_with_b_with_c_and_d() {
  printf("\nMult A with B with C and D");
  set_0_to_reg('C', &C);
  add_a_to_c(&A, &C);
  
  while(1 == 1) {
    if(C == 0) {
      break;
    } else {
      add_b_to_a_with_d();
      decrement_reg(&C);
      if(C == 0) {
        break;
      }
    }
  }
}

char* factorial(int number) {
  char* error_msg = "";

  if(number < 0) {
    error_msg = "Error: Instrução inválida";
    return error_msg;
  }

  printf("Calculando o fatorial de %d\n", number);
  if(number == 0) {
    set_n_to_reg('A', &A, 1);
    return ""; 
  }

  set_n_to_reg('B', &B, number);
  set_n_to_reg('A', &A, 1);
  
  while(1 == 1) {
    if(B == 0) {
      break;
    } else {
      mult_a_with_b_with_c_and_d();
      decrement_reg(&B);
    }
  }
  return "Terminado!";
}

int main(int argc, char *argv[]) {
  factorial(atoi(argv[1]));
  return 0;
}
