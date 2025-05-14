# tester_level3.sh
#!/bin/bash

file=$1
exercise=$(basename "$file" .c)
main_dir="./test_mains/level3"

needs_main=(
    add_prime_sum epur_str expand_str hidenp paramsum pgcd rstr_capitalizer str_capitalizer tab_mult
)

if [[ ! -f "$file" ]]; then
    echo "🚫 File '$file' not found!"
    exit 2
fi

mkdir -p compiled_output

has_main=false
for m in "${needs_main[@]}"; do
    if [[ "$exercise" == "$m" ]]; then
        has_main=true
        break
    fi
done

echo "🔧 Testing Level 3 - Exercise: $exercise"

if [[ "$has_main" == false ]]; then
    main_test="${main_dir}/${exercise}_main.c"
    if [[ ! -f "$main_test" ]]; then
        echo "❌ Missing test main for $exercise in $main_dir"
        exit 2
    fi
    gcc -Wall -Wextra -Werror "$file" "$main_test" -o compiled_output/"${exercise}_test"
else
    gcc -Wall -Wextra -Werror "$file" -o compiled_output/"${exercise}_test"
fi

if [[ $? -ne 0 ]]; then
    echo "❌ Compilation failed."
    exit 2
fi

echo "🚀 Running test:"
compiled_output/"${exercise}_test"
exit 0