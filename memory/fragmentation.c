#include <stdio.h>

int main() {
  int totalMemory, allocated, internal, external;

  printf("Enter total memory: ");
  scanf("%d", &totalMemory);

  printf("Enter allocated memory: ");
  scanf("%d", &allocated);

  internal = allocated * 0.1; // example assumption
  external = totalMemory - allocated;

  printf("Internal Fragmentation = %d\n", internal);
  printf("External Fragmentation = %d\n", external);

  return 0;
}
