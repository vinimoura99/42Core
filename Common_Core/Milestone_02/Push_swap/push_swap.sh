#!/bin/bash

# Caminhos dos programas
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# Arte ASCII
ascii_header() {
    clear
    cat << "EOF"
╔══════════════════════════════════════════════════════╗
║     🌀 PUSH_SWAP INFERNAL TESTER - NIVEL EXTREMO 🌀    ║
╚══════════════════════════════════════════════════════╝
EOF
}

# Valida existência de arquivos
validate_files() {
    if [[ ! -x "$PUSH_SWAP" ]]; then
        echo "❌ ERRO: Arquivo push_swap não encontrado ou não é executável."
        exit 1
    fi
    if [[ ! -x "$CHECKER" ]]; then
        echo "❌ ERRO: Arquivo checker não encontrado ou não é executável."
        exit 1
    fi
}

# Geração segura de números aleatórios únicos
generate_random_numbers() {
    count=$1
    max=$((count * 10))
    shuf -i 0-"$max" -n "$count" | tr '\n' ' '
}

# Executa um teste com feedback visual
run_test() {
    size=$1
    round=$2

    echo ""
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    echo "🚀 Random Test $round com $size números"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

    nums=$(generate_random_numbers "$size")
    if [ -z "$nums" ]; then
        echo "❌ Falha ao gerar números aleatórios (tamanho: $size)"
        return
    fi

    result=$($PUSH_SWAP $nums)
    moves=$(echo "$result" | wc -l)
    checker_output=$(echo "$result" | $CHECKER $nums)

    if [[ "$checker_output" == "OK" ]]; then
        echo "✅ Ordenado corretamente em $moves movimentos."
    else
        echo "❌ ERRO: checker retornou '$checker_output'"
        echo "💥 O caos venceu desta vez..."
    fi
}

# Testes fixos para até 5 números
run_fixed_tests() {
    echo ""
    echo "🌟 Testes fixos (até 5 números):"
    echo "--------------------------------"
    tests=(
        "2 1"
        "3 2 1"
        "1 5 2"
        "4 1 3 2"
        "5 4 3 2 1"
    )

    for t in "${tests[@]}"; do
        echo ""
        echo "🔢 Testando: $t"
        result=$($PUSH_SWAP $t)
        moves=$(echo "$result" | wc -l)
        checker_output=$(echo "$result" | $CHECKER $t)

        if [[ "$checker_output" == "OK" ]]; then
            echo "✅ Sucesso em $moves movimentos."
        else
            echo "❌ Falha: checker => $checker_output"
        fi
    done
}

# Testes randômicos para tamanhos diversos
run_random_tests() {
    for size in 10 50 100 250 500; do
        echo ""
        echo "🌌 Testes com $size números aleatórios:"
        for i in {1..5}; do
            run_test "$size" "$i"
            sleep 0.4
        done
    done
}

# Execução principal
main() {
    ascii_header
    validate_files
    run_fixed_tests
    run_random_tests
    echo ""
    echo "🏁 Fim dos testes. Prepare-se para o próximo round!"
}

main
