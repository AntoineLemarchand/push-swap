#!/bin/sh
if [[ ! -f ./push_swap ]]
then
	echo "Please compile push_swap"
	exit 0
fi
if [[ ! -x $1 ]]
then
	echo "checker not found or not executable"
	exit 0
fi

RED="\033[0;31m"
GREEN="\033[1;32m"
CYAN="\033[0;36m"
NC="\033[0m"

OUTPUT="$(./push_swap $2 2>/dev/null | ./$1 $2 2>&1)"
STEPS="$(./push_swap $2 2> /dev/null | wc -l)"
printf "${CYAN}Checker output: ${NC}"
if [[ ${OUTPUT} == "KO" ]]
then
	printf "${RED}KO${NC}\n"
elif [[ ${OUTPUT} == "OK" ]]
then
	printf "${GREEN}OK${NC}\n"
else
	printf "${RED}Error${NC}\n"
fi
printf "${CYAN}Number of steps: ${NC}${STEPS}\n"
printf "${CYAN}Leaks: ${NC}"
valgrind --leak-check=full ./push_swap $2 2> /dev/null > /dev/null && {
	printf "${GREEN}NONE${NC}\n"
} || {
	printf "${RED}DETECTED${NC}\n"
}
