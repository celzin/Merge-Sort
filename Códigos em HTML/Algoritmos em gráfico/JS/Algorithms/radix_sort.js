function Radix() {
    c_delay = 0;
    console.log("Selected R");

    radix_partition(0, array_size - 1);

    enable_buttons();
}

function radix_sort(start, end, exp) {
    var n = end - start + 1;
    var output = new Array(n).fill(0);
    var count = new Array(10).fill(0);

    for (var i = start; i <= end; i++) {
        var index = Math.floor(div_sizes[i] / exp) % 10;
        count[index]++;
        div_update(divs[i], div_sizes[i], "yellow"); // Color update - Set color to yellow
    }

    for (var i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (var i = end; i >= start; i--) {
        var index = Math.floor(div_sizes[i] / exp) % 10;
        output[count[index] - 1] = div_sizes[i];
        count[index]--;
    }

    for (var i = 0; i < n; i++) {
        div_sizes[start + i] = output[i];
        div_update(divs[start + i], div_sizes[start + i], "red"); // Color update - Set color to red
        div_update(divs[start + i], div_sizes[start + i], "green"); // Color update - Set color to green
    }
}

function radix_partition(start, end) {
    if (start < end) {
        var max = Math.max(...div_sizes.slice(start, end + 1));
        for (var exp = 1; Math.floor(max / exp) > 0; exp *= 10) {
            radix_sort(start, end, exp);
        }
    }
}