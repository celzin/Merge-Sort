#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos de posição
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Função principal que implementa o Bubble Sort
void bubbleSort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

// Função para imprimir o array
void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	system("clear");
	// Tamanho do array
	int size;
	printf("Digite a quantidade de números aleatórios a serem ordenados: ");
	scanf("%d", &size);

	// Aloca memória para o array
	int *arr = (int *)malloc(size * sizeof(int));

	// Preenche o array com números aleatórios
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		arr[i] = rand() % 100000; // Números aleatórios entre 0 99999
	}

	printf("Array original:\n");
	printArray(arr, size);

	// Calcula o tempo antes de executar o Bubble Sort
	clock_t begin = clock();

	// Executa o Bubble Sort
	bubbleSort(arr, size);

	// Calcula o tempo após executar o Bubble Sort
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nArray ordenado:\n");
	printArray(arr, size);

	printf("\nTempo gasto: %.6f segundos\n", time_spent);

	// Libera a memória alocada para o array
	free(arr);

	return 0;
}