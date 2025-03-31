mkdir --parents ".build/examples"

# Examples
gcc -Wall -Wextra -I "include" -o ".build/examples/01-ppm" "examples/01-ppm.c" "src/imglib.c"
