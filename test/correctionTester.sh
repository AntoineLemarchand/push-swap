#!/bin/sh
if [[ ! -f ./push_swap ]]
then
	echo "Please compile push_swap"
	exit 0
fi
if [[ ! -f $1 ]]
then
	echo "Usage: "
	echo "	bash correctionTester.sh [checker] \"[stack]\""
	echo "	or "
	echo "	bash correctionTester.sh [checker] -gen [size] [min] [max]"
	exit 0
fi
if [[ ! -x $1 ]]
then
	echo "Checker not executable, please use chmod +x"
	exit 0
fi

RED="\033[0;31m"
GREEN="\033[1;32m"
CYAN="\033[0;36m"
NC="\033[0m"

if [[ $2 == "-gen" ]]
then
	STACK="$(perl $(dirname "$(realpath "$0")")/tester.pl $3 $4 $5)"
else
	STACK=$2
fi
OUTPUT="$(./push_swap ${STACK} 2>/dev/null | ./$1 ${STACK} 2>&1)"
STEPS="$(./push_swap ${STACK} 2> /dev/null | wc -l)"
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
valgrind --leak-check=full ./push_swap ${STACK} 2> /dev/null > /dev/null && {
	printf "${GREEN}NONE${NC}\n"
} || {
	printf "${RED}DETECTED${NC}\n"
}
