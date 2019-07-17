# Rasterisation_SimpleRenderer
Rasterisation-based image generator      


## Build

cmake and make generate directories including static library and execution files.

#### for rendering exec file:

```
$ cd ROOT/OF/THIS/PROJECT
$ mkdir build
$ cd build
$ cmake ..
$ make
```

#### for google-test exec file:

After the above,

```
$ cd ROOT/OF/THIS/PROJECT/test
$ mkdir build
$ cd build
$ cmake ..
$ make
```

   


## Directories & Files

Before build

```
Rasterisation_SimpleRenderer/
  ├─Rasterizer.sln
  ├─Rasterizer.vcxproj
  ├─Rasterizer.vcxproj.filters
  ├─Rasterizer.vcxproj.user
  ├─CMakeLists.txt
  ├─README.md
  ├─LICENSE
  ├─test 
  │  └─src/
  │     └─gtest .cpp source files
  └─src
     └─rasterizer .cpp/.hpp source files
```

After Build

```
Rasterisation_SimpleRenderer/
  ├─Rasterizer.sln
  ├─Rasterizer.vcxproj
  ├─Rasterizer.vcxproj.filters
  ├─Rasterizer.vcxproj.user
  ├─CMakeLists.txt
  ├─README.md
  ├─LICENSE
  ├─test/ 
  │  ├─src/
  │  │  └─gtest .cpp files
  │  ├─bin/
  │  │  └─test_run
  │  └─build/
  │     └─make files
  ├─src/
  │  └─rasterizer .cpp/.hpp source files
  ├─bin/
  │  └─test_run
  ├─build/
  │  └─make files
  └─libs/
     └─static library files
```

