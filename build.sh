PLATFORM=$1

cleaning(){
	rm -vf main.c
	rm -rvf build/
}

usage(){
	echo "usage:  "
	echo "./build.sh [PLATFORM]"
	echo ""
	echo "supported platform:"
	echo "- plainc : Plain C"
	echo "- clean  : Clean build files"
}

if [ -z $PLATFORM ];then
	usage
	exit
fi

if [ $PLATFORM = "plainc" ];then
	sed "s#while(1){ system_loop(); }##g" main.template > main.c

	mkdir -p build/plain_c/
	cd build/plain_c/
	gcc -v -c ../../plain_c/driver.c
	gcc -v -c ../../main.c
	gcc -v -o pikotes main.o driver.o -lasound -lm

elif [ $PLATFORM = "clean" ];then
	cleaning
else
	echo "Platform currently not supported"
fi
