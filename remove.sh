
if [ $# -eq 0 ]; then
	find . -type f -name "Makefile" -execdir make fclean \;
else
	find . -name "$1" -exec make fclean -C {} \;
fi