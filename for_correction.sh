# shellcheck --shell=bash

# This file is meant to have example to test push_swap

#	Checker:

# Normal behavior:
./checker 0 1 2 3 4

./checker 0 1 2 3 4 -c -v

./checker 4 1 0 2 3 -c -v
# unsorted

./checker 4 1 0 2 3 -c -v
# ra sa : sorted

# Error:
./checker bonjour

./checker 0 1 2 3 A

./checker 0 1 2 3 2147483647
# no Error

./checker 0 1 2 3 2147483648

./checker 0 1 2 3 -2147483648
# no Error

./checker 0 1 2 3 -2147483649

./checker 0 1 1 3 4

./checker 0 1 2 3 0

#	Push_swap

# Normal behavior:
./push_swap 0 1 2 3 4

./push_swap 0 1 2 3 4 -v

./push_swap 4 1 0 2 3 -v

# Error:
./push_swap bonjour

./push_swap 0 1 2 3 A

./push_swap 0 1 2 3 2147483647
# no Error

./push_swap 0 1 2 3 2147483648

./push_swap 0 1 2 3 -2147483648
# no Error

./push_swap 0 1 2 3 -2147483649

./push_swap 0 1 1 3 4

./push_swap 0 1 2 3 0
