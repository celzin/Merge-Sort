function Heap() {
    c_delay = 0;

    heap_sort(0, array_size - 1);

    enable_buttons();
}

function heapify(n, i) {
    var largest = i; // Inicializa o maior como raiz
    var left = 2 * i + 1; // Filho esquerdo do nó atual
    var right = 2 * i + 2; // Filho direito do nó atual

    // Se o filho esquerdo é maior que a raiz
    if (left < n && div_sizes[left] > div_sizes[largest])
        largest = left;

    // Se o filho direito é maior que o maior até agora
    if (right < n && div_sizes[right] > div_sizes[largest])
        largest = right;

    // Se o maior não é a raiz
    if (largest != i) {
        div_update(divs[i], div_sizes[i], "red"); // Atualiza a cor
        div_update(divs[largest], div_sizes[largest], "red"); // Atualiza a cor

        var temp = div_sizes[i];
        div_sizes[i] = div_sizes[largest];
        div_sizes[largest] = temp;

        div_update(divs[i], div_sizes[i], "red"); // Atualiza a altura
        div_update(divs[largest], div_sizes[largest], "red"); // Atualiza a altura

        div_update(divs[i], div_sizes[i], "blue"); // Atualiza a cor
        div_update(divs[largest], div_sizes[largest], "blue"); // Atualiza a cor

        heapify(n, largest); // Recursivamente heapify a subárvore afetada
    }
}

function heap_sort(start, end) {
    var n = end - start + 1;

    // Constrói o heap (rearranja o array)
    for (var i = Math.floor(n / 2) - 1; i >= 0; i--)
        heapify(n, i);

    // Extrai um por um os elementos do heap
    for (var i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        div_update(divs[start], div_sizes[start], "red"); // Atualiza a cor
        div_update(divs[i + start], div_sizes[i + start], "red"); // Atualiza a cor

        var temp = div_sizes[start];
        div_sizes[start] = div_sizes[i + start];
        div_sizes[i + start] = temp;

        div_update(divs[start], div_sizes[start], "red"); // Atualiza a altura
        div_update(divs[i + start], div_sizes[i + start], "red"); // Atualiza a altura

        div_update(divs[start], div_sizes[start], "blue"); // Atualiza a cor
        div_update(divs[i + start], div_sizes[i + start], "blue"); // Atualiza a cor

        heapify(i, start); // Reduz o heap desconsiderando o último elemento extraído
    }
}