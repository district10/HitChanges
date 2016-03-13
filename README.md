# HitChanges

## How to Compile

*****Windows Visual Studio**

Use CMake-GUI to build VS Project.

**Linux, OS X**

```
$ cd HitChanges
$ mkdir build && cd build
$ cmake ..
$ make
```

## Usage

process default data

```
$ ./HitChanges
Scanned 216 lines of file, #hits: 15
```

process specified csv file

```
$ ./HitChanges path/to/file.csv
```

process specified csv file & mark it

```
$ ./HitChanges path/to/file.csv mark
```
