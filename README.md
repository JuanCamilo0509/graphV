# GraphV
## Dependencies
- Ncurses (Linux).
- PDcurses (Windows).
## Linux
### Build
```
git clone https://github.com/JuanCamilo0509/graphV.git
cd graphV
mkdir build && cd build
cmake ../
make
```

## Windows
### Build
```
git clone https://github.com/JuanCamilo0509/graphV.git
cd graphV
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

## Run
Go to the samples directory and run the binary inside it.
```
cd ../samples/
../build/graphV ./
```
