#include <stdio.h>
#include <stdlib.h>

int main () {
  int *array, *array2;
  int n;
  
  printf("¿Cuantos elementos tiene el conjunto?\n");
  scanf("%d", &n);
  
  array = (int*)malloc(n * sizeof(int));
  
  if (array != NULL) {
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");

    array2 = (int*)realloc(array, (n * 2) * sizeof(int));

     if (array2 != NULL) {
        for(int i = n; i < n * 2; i++) {
            array2[i] = i + 1;
        }

        printf("[ ");
        for(int i = 0; i < n * 2; i++) {
            printf("%d ", array2[i]);
        }
        printf("]\n");
        
        free(array2);
      } else {
          free(array);
      }
  }
  return 0;
}
