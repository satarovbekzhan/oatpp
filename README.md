
# Pizzeria Web Anwendung mit Oat++


### Dependencies
This project uses Oat++ Web Framework and requires 
it to be installed in your machine. Just before 
installing make sure you have:
* Git
* C++ compiler supporting C++ version >= 11.
* Make
* CMake version >= 3.1

To install Oat++, open a terminal and execute 
commands below consequently:
```console
$ git clone https://github.com/oatpp/oatpp.git
$ cd oatpp/

$ mkdir build && cd build

$ cmake ..
$ make install
```
In addition to Oat++ it uses external JWT library, so to install it:
```console
$ sudo apt install nlohmann-json3-dev 
$ sudo apt install libgtest-dev
$ sudo apt install libssl-dev
$ git clone https://github.com/arun11299/cpp-jwt.git
$ cd cpp-jwt
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . -j
$ sudo make install
```
### Database
[<img src="diagram.svg" width="100%" alt="Pizzeria Database Diagram"/>](diagram.png)

