output_file="output.txt"

[ -e "$output_file" ] && rm "$output_file"

run_command() {
    command_number=$((command_number+1))
    echo "################  Command $command_number: $* ###############" >> "$output_file"
    "$@" >> "$output_file" 2>&1
    return $?
}

command_number=0

# Command 1
run_command ./PmergeMe #zero number
echo "" >> "$output_file"

# Command 2
run_command ./PmergeMe 3 #one number
echo "" >> "$output_file"

# Command 3
run_command ./PmergeMe 3 2
echo "" >> "$output_file"

# Command 4
run_command ./PmergeMe 4 3 2
echo "" >> "$output_file"

# Command 5
run_command ./PmergeMe 4 3 2 2 2 4 67 87 46 98 239 87 44 44 44
echo "" >> "$output_file"

# Command 6
run_command ./PmergeMe $(jot -r 10 0 100 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 7
run_command ./PmergeMe $(jot -r 15 0 100 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 8
run_command ./PmergeMe $(jot -r 50 0 500 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 9
run_command ./PmergeMe $(jot -r 55 0 500 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 10
run_command ./PmergeMe $(jot -r 100 0 1000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 11
run_command ./PmergeMe $(jot -r 111 0 1000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 12
run_command ./PmergeMe $(jot -r 1000 0 10000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 13
run_command ./PmergeMe $(jot -r 1111 0 10000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 14
run_command ./PmergeMe $(jot -r 3500 0 100000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 15
run_command ./PmergeMe $(jot -r 3555 0 100000 | tr '\n' ' ')
echo "" >> "$output_file"

# Command 16
run_command ./PmergeMe $(jot -r 5000 0 100000 | tr '\n' ' ') #fail too high
echo "" >> "$output_file"

# Command 17
run_command ./PmergeMe 5 4 7 8 9 allo
echo "" >> "$output_file"

# Command 18
run_command ./PmergeMe 5 4 7 8 9 -1
echo "" >> "$output_file"

# Command 19
run_command ./PmergeMe 5 4 7 8 9 999999999999999
echo "" >> "$output_file"

echo "################# TOUTES LES COMMANDES ONT ÉTÉ EXÉCUTÉES AVEC SUCCÈS. ###############" >> "$output_file"
