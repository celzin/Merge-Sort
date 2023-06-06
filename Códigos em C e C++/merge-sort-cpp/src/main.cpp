#include <iostream>
#include <cstdlib>
#include <ctime>

class MergeSort{
public:
	MergeSort(int size);
	~MergeSort();
	void sort();
	void printArray();

private:
	void merge(int arr[], int left, int middle, int right);
	void mergeSortRecursive(int arr[], int left, int right);

	int *array;
	int size;
};

MergeSort::MergeSort(int size){
	this->size = size;
	array = new int[size];

	// Preenche o array com números aleatórios
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		array[i] = rand() % 100000; // Números aleatórios entre 0 99999
	}
}

MergeSort::~MergeSort(){
	delete[] array;
}

void MergeSort::sort(){
	mergeSortRecursive(array, 0, size - 1);
}

void MergeSort::merge(int arr[], int left, int middle, int right){
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Cria arrays temporários
	int *L = new int[n1];
	int *R = new int[n2];

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
	delete[] L;
	delete[] R;
}

void MergeSort::mergeSortRecursive(int arr[], int left, int right){
	if(left < right){
		// Encontra o ponto médio
		int middle = left + (right - left) / 2;

		// Ordena a metade esquerda
		mergeSortRecursive(arr, left, middle);
		// Ordena a metade direita
		mergeSortRecursive(arr, middle + 1, right);

		// Combina as duas metades ordenadas
		merge(arr, left, middle, right);
	}
}

void MergeSort::printArray(){
	for(int i = 0; i < size; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main(){
	system("clear");
	int size;
	std::cout << "Digite a quantidade de numeros aleatorios a serem ordenados: ";
	std::cin >> size;

	MergeSort mergeSort(size);

	std::cout << "Array original:\n";
	mergeSort.printArray();

	// Calcula o tempo antes de executar o Merge Sort
	clock_t begin = clock();

	// Executa o Merge Sort
	mergeSort.sort();

	// Calcula o tempo após executar o Merge Sort
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	std::cout << "\nArray ordenado:\n";
	mergeSort.printArray();

	std::cout << "\nTempo gasto: " << time_spent << " segundos\n";

	return 0;
}