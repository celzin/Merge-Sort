#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para intercalar dois subarrays de arr[]
void merge(int arr[], int left, int middle, int right){
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Cria arrays temporários
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	// Copia dados para os arrays temporários L[] e R[]
	for(i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	// Intercala os arrays temporários de volta para arr[]
	i = 0; // Índice inicial do primeiro subarray
	j = 0; // Índice inicial do segundo subarray
	k = left; // Índice inicial do subarray intercalado
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		} else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copia os elementos restantes de L[], se houver algum
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copia os elementos restantes de R[], se houver algum
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}

	// Libera a memória alocada para os arrays temporários
	free(L);
	free(R);
}

// Função principal que implementa o Merge Sort
void mergeSort(int arr[], int left, int right){
	if(left < right){
		// Encontra o ponto médio
		int middle = left + (right - left) / 2;

		// Ordena a metade esquerda
		mergeSort(arr, left, middle);
		// Ordena a metade direita
		mergeSort(arr, middle + 1, right);

		// Combina as duas metades ordenadas
		merge(arr, left, middle, right);
	}
}

// Função para imprimir o array
void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
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

	// Calcula o tempo antes de executar o Merge Sort
	clock_t begin = clock();

	// Executa o Merge Sort
	mergeSort(arr, 0, size - 1);

	// Calcula o tempo após executar o Merge Sort
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nArray ordenado:\n");
	printArray(arr, size);

	printf("\nTempo gasto: %.6f segundos\n", time_spent);

	// Libera a memória alocada para o array
	free(arr);

	return 0;
}