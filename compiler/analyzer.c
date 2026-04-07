#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char *keywords[] = {"int",   "float", "char",   "if",  "else",
                    "while", "for",   "return", "void"};
int num_keywords = 9;

int isKeyword(char *word) {
  for (int i = 0; i < num_keywords; i++) {
    if (strcmp(word, keywords[i]) == 0)
      return 1;
  }
  return 0;
}

int main() {
  char input[MAX];
  int i = 0;

  printf("Enter a line of code:\n");
  fgets(input, MAX, stdin);

  while (input[i] != '\0') {

    if (isspace(input[i])) {
      i++;
      continue;
    }

    if (isalpha(input[i])) {
      char word[MAX];
      int j = 0;

      while (isalnum(input[i])) {
        word[j++] = input[i++];
      }
      word[j] = '\0';

      if (isKeyword(word))
        printf("%s -> Keyword\n", word);
      else
        printf("%s -> Identifier\n", word);
    }

    else if (isdigit(input[i])) {
      char num[MAX];
      int j = 0;

      while (isdigit(input[i])) {
        num[j++] = input[i++];
      }
      num[j] = '\0';

      printf("%s -> Number\n", num);
    }

    else if (strchr("+-*/=%", input[i])) {
      printf("%c -> Operator\n", input[i]);
      i++;
    }

    else if (strchr("();{}[],", input[i])) {
      printf("%c -> Special Symbol\n", input[i]);
      i++;
    }

    else {
      printf("%c -> Unknown\n", input[i]);
      i++;
    }
  }

  return 0;
}
