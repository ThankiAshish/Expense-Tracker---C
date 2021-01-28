#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int Incomes[MAX];
int totalIncome = 0;
int Expenses[MAX];
int totalExpense = 0;
char description[MAX];

void storeData(char type[], int numericalData, char descriptionData[]) {
  time_t t;
  time(&t);
  FILE *fptr;
  fptr = fopen("data.txt","a");

  if(fptr == NULL) {
    printf("\nERROR!");
    exit(1);
  }

  fprintf(fptr,"%s%s: $%d - %s",ctime(&t),type,numericalData,descriptionData);
  fclose(fptr);
}

int getIncome(int eI) {
  printf("\nEnter your income: $");
  scanf("%d",&Incomes[eI]);
  printf("\nEnter description: ");
  scanf(" %[^\n]s",description);
  totalIncome += Incomes[eI];
  printf("\nTotal Income: $%d\n",totalIncome);
  storeData("Income",Incomes[eI],description);
  return totalIncome;
}

int getExpense(int eE) {
  printf("\nEnter your expense: $");
  scanf("%d",&Expenses[eE]);
  printf("\nEnter description: ");
  scanf(" %[^\n]s",description);
  totalExpense += Expenses[eE];
  printf("\nTotal Expense: $%d\n",totalExpense);
  storeData("Expense",Expenses[eE],description);
  return totalExpense;
}

void getSavings(int income, int expense) {
  int totalSavings = 0;
  if(expense == 0) {
    totalSavings = income;
  }else {
    totalSavings = income - expense;
  }
  printf("\nYour Savings Will Be $%d.",totalSavings);
}

void addData(void) {
  int entryIncome = 0;
  int entryExpense = 0;
  int income = 0;
  int expense = 0;
  int choice;

  do {
    printf("\nSelect Your Choice From Below:");
    printf("\n\t1. Add Income");
    printf("\n\t2. Add Expense");
    printf("\n\tPress Any Other Key to Exit!");
    printf("\n\nEnter Your Choice: ");
    scanf("%d",&choice);

    if(choice == 1) {
      income = getIncome(entryIncome);
      entryIncome++;
    }else if(choice == 2) {
      expense = getExpense(entryExpense);
      entryExpense++;
    }else {
      break;
    }
  }while((choice >= 1 && choice <= 2));
  getSavings(income, expense);
}

int main() {
  addData();
  return 0;
}
