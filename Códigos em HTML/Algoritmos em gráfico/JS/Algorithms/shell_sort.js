function Shell() {
    c_delay = 0;
    console.log("Selected S");

    shell_sort();

    enable_buttons();
}

function shell_sort() {
    var n = div_sizes.length;
    var gap = Math.floor(n / 2);

    while (gap > 0) {
        for (var i = gap; i < n; i++) {
            var temp = div_sizes[i];
            var j = i;

            div_update(divs[j], div_sizes[j], "yellow"); // Color update - Set color to yellow

            while (j >= gap && div_sizes[j - gap] > temp) {
                div_update(divs[j - gap], div_sizes[j - gap], "red"); // Color update - Set color to red
                div_sizes[j] = div_sizes[j - gap];
                div_update(divs[j], div_sizes[j], "red"); // Color update - Set color to red
                j -= gap;
            }

            div_sizes[j] = temp;
            div_update(divs[j], div_sizes[j], "green"); // Color update - Set color to green
        }

        gap = Math.floor(gap / 2);
    }
}
