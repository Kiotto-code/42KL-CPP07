if [ $# -eq 0 ]; then
	find . -name "Makefile" -execdir make {} re \;
else
	find . -type d -name $1 -exec make -C {} \;
fi

