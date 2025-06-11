# COLORS
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
MAGENTA = \033[0;35m
BOLD    = \033[1m
RESET   = \033[0m

# PROJECT
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -IIncludes
RM = rm -f

# FILES
SRC_DIRS = Main Operations Sorting Utils Error
SRCS = $(wildcard Main/*.c) \
	   $(wildcard Operations/*.c) \
	   $(wildcard Sorting/*.c) \
	   $(wildcard Utils/*.c) \
	   $(wildcard Error/*.c) \
	   $(wildcard Ranking/*.c)

OBJS = $(SRCS:.c=.o)

# SPINNER FOR FUN LOADING BAR
SPINNER = '|/-\\'

#######################
### LOADING BAR FUN ###
#######################
define loading_bar
	@echo -ne "  $(CYAN)Loading: $(RESET)"
	@for i in $$(seq 1 20); do \
		idx=`expr $$i % 4`; \
		percent=`expr $$i \* 5`; \
		bar_length=20; \
		filled=$$i; \
		empty=`expr $$bar_length - $$filled`; \
		printf "$(GREEN)"; \
		for j in $$(seq 1 $$filled); do printf "█"; done; \
		printf "$(RESET)"; \
		for j in $$(seq 1 $$empty); do printf "░"; done; \
		spin_char=`echo "$(SPINNER)" | cut -c $$((idx + 1))`; \
		printf " %3d%% $(MAGENTA)%s$(RESET)\\r" $$percent $$spin_char; \
		sleep 0.07; \
	done; \
	echo ""
endef

##################
### COMPILATION ###
##################

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(YELLOW)\n🎯 Linking all objects to create $(NAME)...$(RESET)"
	$(call loading_bar)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN)✔ Done! Run with ./$(NAME)$(RESET)"

%.o: %.c
	@echo -e "$(CYAN)- Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo -e "$(RED)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "$(RED)🧹 Removed $(NAME).$(RESET)"

re: fclean all

.PHONY: all clean fclean re
