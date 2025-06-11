# 🚀 push_swap

## 📖 Descrição

O projeto **push_swap** é um desafio da 42 que consiste em ordenar uma lista de números inteiros usando duas pilhas (stacks) e um conjunto limitado de operações. O objetivo é implementar um algoritmo que ordene a lista com o menor número possível de movimentos.

---

## ⚙️ Como funciona

Você deve ordenar uma pilha de números utilizando as seguintes operações:

- `sa` — 🔄 swap (troca) os dois primeiros elementos do topo da pilha A.  
- `sb` — 🔄 swap os dois primeiros elementos do topo da pilha B.  
- `ss` — 🔄 `sa` e `sb` ao mesmo tempo.  
- `pa` — ⬆️ push do topo da pilha B para o topo da pilha A.  
- `pb` — ⬇️ push do topo da pilha A para o topo da pilha B.  
- `ra` — 🔁 rotate: move o primeiro elemento da pilha A para o final.  
- `rb` — 🔁 rotate a pilha B.  
- `rr` — 🔁 `ra` e `rb` ao mesmo tempo.  
- `rra` — 🔂 reverse rotate: move o último elemento da pilha A para o topo.  
- `rrb` — 🔂 reverse rotate a pilha B.  
- `rrr` — 🔂 `rra` e `rrb` ao mesmo tempo.

---

## 🗂️ Estrutura do projeto

- **src/** — Código-fonte do projeto  
- **Includes/** — Arquivos de cabeçalho (`.h`)  
- **Makefile** — Para compilar o projeto  
- **README.md** — Este arquivo de documentação  

---

## 🛠️ Como compilar

No terminal, execute:

```bash
make

Isso vai compilar o executável chamado push_swap.
▶️ Como usar

Você pode rodar o programa passando os números como argumentos separados por espaço:

./push_swap 3 2 5 1 4

O programa vai imprimir na saída padrão a sequência de operações para ordenar a lista.
📋 Regras e requisitos

    ✅ Apenas números inteiros válidos podem ser usados.

    🚫 Não pode haver números duplicados.

    ⚠️ O programa deve validar a entrada e retornar erro em caso de input inválido.

    🎯 O algoritmo deve minimizar o número de operações.

    🔐 Use apenas as operações permitidas.

🧩 Funções principais implementadas

    Inicialização e manipulação das pilhas (empilhar, desempilhar, rotacionar)

    Checagem se a pilha já está ordenada

    Algoritmo de ordenação eficiente usando as operações disponíveis

    Funções auxiliares para parsing e validação da entrada

    Função para imprimir a pilha (para debugging)

🔎 Exemplo

./push_swap 2 1 3 6 5 8

Saída:

sa
ra
ra

👨‍💻 Autor

Vinícius Moura

GitHub
📄 Licença

Este projeto está licenciado sob a licença MIT.
🔗 Referências

    42 push_swap subject

    Documentação oficial da 42

📬 Contato

Caso tenha dúvidas ou sugestões, abra uma issue ou me contate via GitHub.
