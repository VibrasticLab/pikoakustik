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
	echo "- stm32f401nucl : STM32F401RE Nucleo board"
	echo "- testarray     : Test Array on Plain C"
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

elif [ $PLATFORM = "stm32f429disc" ];then
	cp -f main.template main.c
	mkdir -p build/stm32f429disc/
	cd stm32f429disc/
	make all

	rm -rf ../build/stm32f429disc/build/
	mv build/ ../build/stm32f429disc/
	rm -rf .dep

elif [ $PLATFORM = "stm32f401nucl" ];then
	cp -f main.template main.c
	mkdir -p build/stm32f401nucl/
	cd stm32f401nucl/
	make all

	rm -rf ../build/stm32f401nucl/build/
	mv build/ ../build/stm32f401nucl/
	rm -rf .dep

elif [ $PLATFORM = "testarray" ];then
	sed "s#while(1){ system_loop(); }##g" main.template > main.c
	mkdir -p build/testarray/

	cd build/testarray/
	gcc -v -c ../../testarray/driver.c
	gcc -v -c ../../main.c
	gcc -v -static -o testarr main.o driver.o -lm

	cp -vf ../../testarray/testarrplot.py ./
	cp -vf ../../testarray/singraf.py ./

elif [ $PLATFORM = "testmmc" ];then
	echo "test mmc based-on stm32f401nucl"
	cp -f main.template main.c
	mkdir -p build/testmmc/
	cd testmmc/
	make all

	rm -rf ../build/testmmc/build/
	mv build/ ../build/testmmc/
	rm -rf .dep

elif [ $PLATFORM = "clean" ];then
	cleaning

else
	echo "Platform currently not supported"
	usage
fi
