This platform is for plain C enhanced with NCurses as interface.
Requirement:
- GCC
- Alsa
- NCurses

This should be pre-installed.
On Arch Linux, can be installed by:
~~~
sudo pacman -S base-devel alsa-lib ncurses
~~~

To build, just run on top repos directory:
~~~
./build.sh ncurses
~~~

If no error on compiling, then run:
~~~
./build/plainc/tescurses
~~~
