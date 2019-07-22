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
	sed "s#PLATFORM#plain_c#g" main.template > main.c

	mkdir -p build/
	cd build/
	gcc -v -c ../plain_c/driver.c
	gcc -v -c ../main.c
	gcc -v -o pikotest main.o driver.o -lasound -lm

	echo "result is: build/pikotest"

elif [ $PLATFORM = "clean" ];then
	rm -vf main.c
	rm -rvf build/
else
	echo "Platform currently not supported"
fi
