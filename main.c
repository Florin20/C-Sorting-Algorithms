#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BS_comparison, BS_assignments;
int IS_comparison, IS_assignments;
int SS_comparison, SS_assignments;

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void BubbleSort(int arr[], int n){
    int i, end;
    int array[n];
    for(i = 0; i < n; i++){ //copy the array
        array[i] = arr[i];
    }

    do{
        end  = 1; // suppose it is the last iteration
        for(i = 0; i <= n-2; i++){
            BS_comparison++;
            if (array[i] > array[i+1]){
                BS_assignments+=3;
                swap(&array[i], &array[i+1]);
                end = 0;
            }

        }
    }while(!end);


   printArray(array, n);
}

void InsertionSort(int arr[], int n){
    int i, key, j;
    int array[n];

    for(i = 0; i < n; i++){ //copy the array
        array[i] = arr[i];
    }

    for(i = 1; i < n; i++){
        IS_assignments++;
        key = array[i];
        j = i - 1;
        IS_comparison++;
        while (j >= 0 && array[j] > key){
            array[j+1] = array[j];
            IS_assignments++;
            j = j - 1;
        }
        array[j+1] = key;
        IS_assignments++;
    }

   printArray(array, n);
}

void SelectionSort(int arr[], int n){
    int i, j, index;
    int array[n];

    for(i = 0; i < n; i++){ //copy the array
        array[i] = arr[i];
    }

    for(i = 0; i < n-1; i++){
        index = i;
        for(j = i + 1; j < n; j++){
            SS_comparison++;
            if(array[j] < array[index]){
                index = j;
            }
        }
        swap(&array[i], &array[index]);
        SS_assignments+=3;
    }

    printArray(array, n);

}

int *generateRandomArray(int n){
    int *v = malloc(n*sizeof(int));
    int  i, r;
    srand(time(NULL));
    for (i = 0; i < n; i++){
        r = rand();
        v[i] = r;
    }
    return v;
}

int *generateReverseArray(int n){
    int *v = malloc(n*sizeof(int));
    int i, temp;
    temp = 0;
    srand(time(NULL));
    for(i = n-1; i >=  0; i--){
        v[i] = temp + rand();
        temp = v[i];
    }
    return v;

}

int *generateSortedArray(int n){
        int *v = malloc(n*sizeof(int));
        int i, temp = 0;
        srand(time(NULL));
        for(i = 0; i < n; i++){
            v[i] = temp + rand();
            temp = v[i];
        }
        return v;
}

void printArray(int *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

}


int main()
{


   int *arr;
   int i;

   arr = generateRandomArray(10);


   for(i = 0; i < 10; i++){
    printf("%d ", arr[i]);
   }
   printf("\n");

   printf("\n");
   BubbleSort(arr, 10);
   printf("\n");
   InsertionSort(arr, 10);
   printf("\n");
   SelectionSort(arr, 10);


   /*FILE *a = fopen("assignmentsBestCase.csv", "a");
   FILE *b = fopen("comparisonBestCase.csv", "a");
   FILE *c = fopen("a+cBestCase.csv", "a");

    int i = 100;

    for(i = 100; i < 10000; i+=200){
        arr = generateSortedArray(i);
        BubbleSort(arr, i);
        InsertionSort(arr, i);
        SelectionSort(arr, i);
        fprintf(a, "%d;%d;%d;%d\n", i, BS_assignments, IS_assignments, SS_assignments);
        fprintf(b, "%d;%d;%d;%d\n", i, BS_comparison, IS_comparison, SS_comparison);
        fprintf(c, "%d;%d;%d;%d\n", i, BS_assignments+BS_comparison, IS_assignments+IS_comparison, SS_assignments+SS_comparison);

        BS_assignments = 0;
        IS_assignments = 0;
        SS_assignments = 0;

        BS_comparison = 0;
        IS_comparison = 0;
        SS_comparison = 0;


    }
    fclose(a);
    fclose(b);
    fclose(c);

    a = fopen("assignmentsAverageCase.csv", "a");
    b = fopen("comparisonAverageCase.csv", "a");
    c = fopen("a+cAverageCase.csv", "a");

    free(arr);

    for(i = 100; i < 10000; i+=250){
        arr = generateRandomArray(i);
        BubbleSort(arr, i);
        InsertionSort(arr, i);
        SelectionSort(arr, i);
        fprintf(b, "%d;%d;%d;%d\n", i, BS_comparison, IS_comparison, SS_comparison);
        fprintf(a, "%d;%d;%d;%d\n", i, BS_assignments, IS_assignments, SS_assignments);
        fprintf(c, "%d;%d;%d;%d\n", i, BS_assignments+BS_assignments, IS_assignments+IS_comparison, SS_assignments+SS_comparison);

        BS_assignments = 0;
        IS_assignments = 0;
        SS_assignments = 0;

        BS_comparison = 0;
        IS_comparison = 0;
        SS_comparison = 0;
    }
    fclose(a);
    fclose(b);
    fclose(c);

    a = fopen("assignmentsWorstCase.csv", "a");
    b = fopen("comparisonWorstCase.csv", "a");
    c = fopen("a+cWorstCase.csv", "a");


    free(arr);

    for(i = 100; i < 10000; i+=250){
        arr = generateReverseArray(i);
        BubbleSort(arr, i);
        InsertionSort(arr, i);
        SelectionSort(arr, i);
        fprintf(b, "%d;%d;%d;%d\n", i, BS_comparison, IS_comparison, SS_comparison);
        fprintf(a, "%d;%d;%d;%d\n", i, BS_assignments, IS_assignments, SS_assignments);
        fprintf(c, "%d;%d;%d;%d\n", i, BS_assignments+BS_assignments, IS_assignments+IS_comparison, SS_assignments+SS_comparison);

        BS_assignments = 0;
        IS_assignments = 0;
        SS_assignments = 0;

        BS_comparison = 0;
        IS_comparison = 0;
        SS_comparison = 0;
    }

    fclose(a);
    fclose(b);
    fclose(c);*/


    return 0;
}

/*În urma generãrii graficelor, concluziile sunt urmãtoarele:

- În cazul în care vectorul este deja sortat(best case), cel mai eficient algoritm est Bubble Sort. Numarul de asignari este zero, iar numarul de
comparatii creste liniar în funcție de numărul de elemente. Selection Sort este cel mai putin eficient deoarece face mai multe parcurgeri.

-în cazul mediu statistic, algoritmul Bubble Sort este cel mai putin eficient, algoritmul Insertion Sort este cel mai eficiet.

-În cazul în care vectorul este sortat invers(worst case), Bubble Sort este cel mai ineficient. Insertion Sort face cele mai putine comparatii, dar Selection Sort
face cele mai puține asginari.

În general, Bubble Sort trebuie evitat, excepția sunt cazurile în care sunt putin elemente pentru care trebuie făcut swap(Best Case).*/

