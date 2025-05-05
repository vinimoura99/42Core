# tester_level2.sh
#!/bin/bash

file=$1
exercise=$(basename "$file" .c)
main_dir="./test_mains/level2"

needs_main=(
    alpha_mirror camel_to_snake do_op inter last_word snake_to_camel union wdmatch
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

echo "🔧 Testing Level 2 - Exercise: $exercise"

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