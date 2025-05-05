#!/bin/bash

# Define exercises for each level with main function requirement
level1_exercises=(
    "first_word:no_main" "fizzbuzz:main_needed" "ft_strcpy:no_main" "ft_strlen:no_main"
    "ft_swap:no_main" "putstr:no_main" "repeat_alpha:main_needed" "rev_print:main_needed"
    "rot_13:main_needed" "rotone:main_needed" "search_and_replace:main_needed" "ulstr:main_needed"
)
level2_exercises=(
    "alpha_mirror:main_needed" "camel_to_snake:main_needed" "do_op:main_needed" "ft_atoi:no_main"
    "ft_strcmp:no_main" "ft_strcspn:no_main" "ft_strdup:no_main" "ft_strpbrk:no_main"
    "ft_strrev:no_main" "ft_strspn:no_main" "inter:main_needed" "is_power_of_2:no_main"
    "last_word:main_needed" "max:no_main" "print_bits:no_main" "reverse_bits:no_main"
    "snake_to_camel:main_needed" "swap_bits:no_main" "union:main_needed" "wdmatch:main_needed"
)
level3_exercises=(
    "add_prime_sum:main_needed" "epur_str:main_needed" "expand_str:main_needed"
    "ft_atoi_base:no_main" "ft_list_size:no_main" "ft_range:no_main" "ft_rrange:no_main"
    "hidenp:main_needed" "lcm:main_needed" "paramsum:main_needed" "pgcd:main_needed"
    "print_hex:no_main" "rstr_capitalizer:main_needed" "str_capitalizer:main_needed"
    "tab_mult:main_needed"
)
level4_exercises=(
    "flood_fill:no_main" "fprime:main_needed" "ft_itoa:no_main" "ft_list_foreach:no_main"
    "ft_list_remove_if:no_main" "ft_split:no_main" "rev_wstr:main_needed"
    "rostring:main_needed" "sort_int_tab:no_main" "sort_list:no_main"
)

# Define ASCII Arts
DRAGON="
\033[1;33m
          __====-_  _-====___
     _-^^^#####//      \\\#####^^^--_
  _-^##########// (    ) \\\##########^-_
 -############//  |\^^/|  \\\############-
_/############//   (@::@)   \\\############\\_
/#############((     \\//     ))#############\\
-###############\\    (oo)    //###############-
-#################\\  / U \\  //#################-
-###################\\/  (  ) \//###################-
_#/|##########/\######(   )######/\##########|\#_
 |/ |#/\#/\#/  \#/\##\  (  )  /##/\#/  \#/\#/\#| \
 \033[0m"
CROWN="
\033[1;36m
        _____
       /     \\
      | () () |
       \  ^  /
        |||||
        |||||
     👑 THE CROWN OF GLORY 👑
\033[0m"
STARSHIP="
\033[1;33m
          _____
         /     \
        /       \
       |   O   O |
       |   ___   |
      /   /   \   \
     |   |     |   |
      \__/-----\__/
         |     |
         |     |
        /       \
       /         \
      |           |
     /             \
    ~~~~~~~~~~~~~~~~~
    🚀 STARSHIP AWAY 🚀
\033[0m"
SWORD="
\033[1;31m
      /\\
     /  \\
    /    \\
   |      |
   |      |
   |      |
    \\    /
     \\  /
      \\/
    ⚔️ WARRIOR'S SWORD ⚔️
\033[0m"
PHOENIX="
\033[1;35m
          \    /
       .-'      '-.
      /            \\
     |    ()()      |
     |   _    _     |
     |   (_)  (_)   |
     \\     \/      /
      '-.______.-'
   🔥 THE RISING PHOENIX 🔥
\033[0m"


# Function to process a level
process_level() {
    local level_num=$1
    shift
    local exercises_info=("$@")

    case $level_num in
        1)
            echo -e "$DRAGON"
            ;;
        2)
            echo -e "$CROWN"
            ;;
        3)
            echo -e "$STARSHIP"
            ;;
        4)
            echo -e "$SWORD"
            ;;
        *)
            echo -e "$PHOENIX"
            ;;
    esac

    local tester_script="./tester_level${level_num}.sh"

    for exercise_data in "${exercises_info[@]}"; do
        IFS=':' read -r exercise_name main_requirement <<< "$exercise_data"
        local exercise_file="eval/${exercise_name}.c"

        echo -e "\n\033[1;36m🧩💥 Time to conquer the quest: Level $level_num - Exercise: $exercise_name 💥🧩\033[0m"
        echo -e "\033[1;36m-------------------------------------------------------------\033[0m"
        
        if [[ "$main_requirement" == "main_needed" ]]; then
            echo -e "\033[1;31m⚔️ This exercise needs a 'main' function. Prepare your battle plan! 📝\033[0m"
        else
            echo -e "\033[1;32m🧙‍♂️ Only the magic function needed here—no 'main' required! 🎩✨\033[0m"
        fi
        
        echo -e "\033[1;35m🌿 Create your code in: \`$exercise_file\`\033[0m"
        echo ""

        while true; do
            
            
            echo -e "\033[1;34m🚀 Ready for testing? Type 'grade' to cast the compiler spell!\033[0m"
            echo -e "\033[1;33mType 'plim' to skip this exercise and continue the journey! 🎉\033[0m"
            read -p "Code Commander> " user_command
            
            clear
            if [[ "$user_command" == "grade" ]]; then
                if [[ -f "$exercise_file" ]]; then
                    echo -e "\033[1;36m💻 Unleashing the magic on $exercise_file...\033[0m"
                    $tester_script "$exercise_file"
                    result=$?
                    
                    if [[ $result -eq 0 ]]; then
                        echo -e "\033[1;32m🎉🎉 Woohoo! Code works like a charm! On to the next exercise! 🚀\033[0m"
                        break
                    elif [[ $result -eq 2 ]]; then
                        echo -e "\033[1;31m💥💥 Oops! There’s an error! Debug and try again! 🛠️\033[0m"
                    fi
                else
                    echo -e "\033[1;33m🧐 File \`$exercise_file\` is missing! Create it first! ⚡\033[0m"
                fi
            
            elif [[ "$user_command" == "plim" ]]; then
                echo -e "\033[1;32m✨ Exercise skipped... Moving on! 💫\033[0m"
                break

            else
                echo -e "\033[1;31m❌ Invalid command! Type 'grade' to test or 'plim' to skip.\033[0m"
                
            fi
        done
    done

    echo -e "\n\033[1;33m🏆 Congratulations! You've completed Level $level_num! 🎉\033[0m"
    echo -e "\033[1;32mOn to the next challenge! 🧑‍💻🚀 Keep going, legendary coder!\033[0m"
    echo "====================================================="
    echo ""
}

# --- Main Script ---
echo -e "\033[1;35m🎉🎉 Welcome to the Grand Gauntlet of C Challenges! 🎉🎉\033[0m"
echo -e "\033[1;32mAre you ready to dive into an epic journey of coding? Let's get started!\033[0m"
echo "====================================================="
echo ""

# Create eval directory
mkdir -p eval
echo -e "\033[1;34mYour enchanted lab 'eval/' is set up. Time to start coding! 🔮✨\033[0m"
echo ""

# Process each level
process_level 1 "${level1_exercises[@]}"
process_level 2 "${level2_exercises[@]}"
process_level 3 "${level3_exercises[@]}"
process_level 4 "${level4_exercises[@]}"

echo -e "\n\033[1;33m✨👑✨ YOU HAVE CONQUERED THE GAUNTLET! ✨👑✨\033[0m"
echo -e "\033[1;32mThe C beast is tamed! Your solutions are now legendary! 🌟\033[0m"
echo -e "\033[1;35mUntil next time, coder extraordinaire! Stay awesome! 🚀\033[0m"
echo -e "====================================================="
