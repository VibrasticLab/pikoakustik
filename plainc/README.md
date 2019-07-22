This platform is for plain C.
Requirement:
- GCC
- Alsa

This should be pre-installed.
On Arch Linux, can be installed by:
~~~
sudo pacman -S base-devel alsa-lib
~~~

To build, just run on top repos directory:
~~~
./build.sh plainc
~~~

If no error on compiling, then run:
~~~
./build/plainc/pikotes
~~~
