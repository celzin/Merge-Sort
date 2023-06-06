#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos de posição
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Função para selecionar o pivô e particionar o array
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);

	for(int j = low; j <= high - 1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// Função principal que implementa o Quick Sort
void quickSort(int arr[], int low, int high){
	if(low < high){
		int pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
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

	// Calcula o tempo antes de executar o Quick Sort
	clock_t begin = clock();

	// Executa o Quick Sort
	quickSort(arr, 0, size - 1);

	// Calcula o tempo após executar o Quick Sort
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nArray ordenado:\n");
	printArray(arr, size);

	printf("\nTempo gasto: %.6f segundos\n", time_spent);

	// Libera a memória alocada para o array
	free(arr);

	return 0;
}