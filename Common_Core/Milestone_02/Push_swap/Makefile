# **************************************************************************** #
#                                                                              #
#                  ✨ PUSH_SWAP - A MÁQUINA DE ORDENAÇÃO ✨                    #
#                                                                              #
#    Feito com ☕ e muito <3 por: vmoura-d <vmoura-d@student.42porto.com>      #
#                                                                              #
# **************************************************************************** #

# ----------------------------- CONFIGURAÇÕES DO PROJETO ------------------------------ #
# Compilador e Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g # Adicione -fsanitize=address para debug de memória hardcore!
RM = rm -f

# Nome do Executável Mágico
NAME = push_swap

# Diretórios
OBJS_DIR = objs
# Diretórios onde os arquivos .c estão escondidos (o VPATH cuida da mágica)
SRCS_DIRS = Main Error Stack Ranking Operations Sorting Utils

# Arquivos Fonte (apenas os nomes base, o VPATH faz a mágica de encontrá-los)
# Listamos todos os seus guerreiros .c aqui!
SRCS_BASENAMES = main.c main_utils.c \
                 error.c \
                 new_node.c stack_free.c stack_init.c stack_push.c \
                 ranking.c ranking_utils.c \
                 operations_swap.c operations_push.c operations_rotate.c operations_rev_rotate.c \
                 sort_small.c sort_radix.c sort_two.c sort_three.c sort_four.c sort_five.c \
                 utils.c utils_split.c

# Arquivos Objeto (serão criados em $(OBJS_DIR)/)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_BASENAMES:.c=.o))

# VPATH: Onde o Make deve procurar pelos arquivos fonte. A ordem importa se houver nomes duplicados!
VPATH = $(SRCS_DIRS)

# Cores para mensagens épicas! (Porque a vida é muito curta para terminais monocromáticos)
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
CYAN := \033[0;36m
RED := \033[0;31m
BOLD := \033[1m
NC := \033[0m # Sem Cor (para voltar ao normal)

# Efeitos de Loading (simples, mas charmoso)
LOADING_CHARS = ⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏
define SLEEP_AND_ECHO
    @printf "$(1)$(2) %s\r" $(shell echo '$(LOADING_CHARS)' | cut -c $$(($(3)%10+1))); \
    sleep 0.1;
endef

# --------------------------------- REGRAS DE COMPILAÇÃO ---------------------------------- #
all: welcome $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)🔗 Ligando os módulos... $(BOLD)QUASE LÁ!$(NC) ✨"
	@$(call SLEEP_AND_ECHO,$(YELLOW),🔗 Ligando os módulos...,1)
	@$(call SLEEP_AND_ECHO,$(YELLOW),🔗 Ligando os módulos...,2)
	@$(call SLEEP_AND_ECHO,$(YELLOW),🔗 Ligando os módulos...,3)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo ""
	@echo "$(GREEN)==================================================================$(NC)"
	@echo "$(GREEN)🚀 $(BOLD)$(NAME)$(NC) compilado com SUCESSO TOTAL! Prepare-se para o PUSH e SWAP! 🚀$(NC)"
	@echo "$(GREEN)==================================================================$(NC)"
	@echo "$(CYAN)Para executar: ./$(NAME) <lista de números>$(NC)"
	@echo "$(CYAN)Exemplo: ./$(NAME) \"3 1 2\" ou ./$(NAME) 4 8 2 9 1 5$(NC)"
	@echo ""

# Regra para compilar arquivos .c para .o no diretório $(OBJS_DIR)
# $< é o primeiro pré-requisito (o arquivo .c)
# $@ é o nome do alvo (o arquivo .o)
$(OBJS_DIR)/%.o: %.c push_swap.h Makefile
	@mkdir -p $(OBJS_DIR) # Cria o diretório de objetos se não existir (mágica silenciosa)
	@printf "$(BLUE)⚙️  Compilando $(BOLD)%s$(NC)... Segure firme nos seus bits e bytes! 💾\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------- COMANDOS DE LIMPEZA PROFUNDA ----------------------------- #
clean:
	@echo "$(RED)🧹 Limpando a área... Varrendo $(BOLD)$(OBJS_DIR)$(NC) para debaixo do tapete digital... 🧹"
	@$(call SLEEP_AND_ECHO,$(RED),🧹 Limpando...,1)
	@$(RM) -r $(OBJS_DIR)
	@echo "$(GREEN)✨ Arquivos objeto evaporados! Puff! Como se nunca tivessem existido! ✨$(NC)"

fclean: clean
	@echo "$(RED)💣 Efetuando faxina nível hard... $(BOLD)$(NAME)$(NC) está prestes a virar poeira cósmica! 💣"
	@$(call SLEEP_AND_ECHO,$(RED),💣 Desintegrando $(NAME)...,1)
	@$(RM) $(NAME)
	@echo "$(GREEN)💥 $(BOLD)$(NAME)$(NC) foi desintegrado da existência! Thanos ficaria orgulhoso! 💥$(NC)"

re:
	@echo "$(YELLOW)🛠️  Modo Fênix ativado! Reconstruindo $(BOLD)$(NAME)$(NC) das cinzas... 🔥"
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory
	@echo "$(GREEN)✨ $(BOLD)$(NAME)$(NC) renasceu mais forte e brilhante do que nunca! ✨$(NC)"

# ---------------------------- MENSAGENS CINEMATOGRÁFICAS ----------------------------- #
welcome:
	@echo "$(CYAN)==================================================================$(NC)"
	@echo "$(CYAN)✨ Bem-vindo ao $(BOLD)Push_Swap Construtor Automágico 9001$(NC)! ✨$(NC)"
	@echo "$(CYAN)Preparando para transformar código em pura magia de ordenação...$(NC)"
	@echo "$(CYAN)Apertem os cintos, a compilação vai começar!$(NC)"
	@echo "$(CYAN)==================================================================$(NC)"
	@$(call SLEEP_AND_ECHO,$(YELLOW),🚀 Iniciando sequência...,1)
	@$(call SLEEP_AND_ECHO,$(YELLOW),🚀 Iniciando sequência...,2)
	@$(call SLEEP_AND_ECHO,$(YELLOW),🚀 Iniciando sequência...,3)
	@printf "\n"

# Alvos Falsos (targets que não são arquivos reais, mas ações)
.PHONY: all clean fclean re welcome

# Comente a linha abaixo se quiser ver os comandos que o Make está executando (para debug)
# .SILENT: