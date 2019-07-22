PLATFORM=$1

cleaning(){
	echo "remove main.c and build dir"
	rm -f main.c
	rm -rf build/
}

usage(){
	echo "usage:  "
	echo "./build.sh [PLATFORM]"
	echo ""
	echo "supported platform:"
	echo "- plainc        : Plain C"
	echo "- stm32f429disc : STM32F429ZI Discovery board"
	echo "- clean         : Clean build files"
}

if [ -z $PLATFORM ];then
	usage
	exit
fi

if [ $PLATFORM = "plainc" ];then
	sed "s#while(1){ system_loop(); }##g" main.template > main.c
	mkdir -p build/plainc/
	cd build/plainc/
	gcc -v -c ../../plainc/driver.c
	gcc -v -c ../../main.c
	gcc -v -o pikotes main.o driver.o -lasound -lm
	echo "FINISHED"
elif [ $PLATFORM = "stm32f429disc" ];then
	cp -f main.template main.c
	mkdir -p build/stm32f429disc/
	cd stm32f429disc/
	make all
	mv build/ ../build/stm32f429disc/
	rm -rf .dep
	echo "FINISHED"
elif [ $PLATFORM = "clean" ];then
	cleaning
else
	echo "Platform currently not supported"
fi
