PLATFORM=$1

if [ -z $PLATFORM ];then
	echo "usage:  "
	echo "./build.sh [PLATFORM]"
	echo ""
	echo "supported platform:"
	echo "- plainc : Plain C"
	echo "- clean  : Clean build files"
fi

if [ $PLATFORM = "plainc" ];then
	sed "s#while(1){ system_loop(); }##g" main.template > main.c

	mkdir -p build/
	cd build/
	gcc -v -c ../plain_c/driver.c
	gcc -v -c ../main.c
	gcc -v -o pikotes main.o driver.o -lasound -lm

elif [ $PLATFORM = "clean" ];then
	rm -vf main.c
	rm -rvf build/
else
	echo "Platform currently not supported"
fi
