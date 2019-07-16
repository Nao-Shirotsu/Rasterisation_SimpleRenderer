# Rasterisation_SimpleRenderer
Rasterisation-based image generator      


## Build

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
	│	└─src/
    │	   └─GTEST_SOURCE_FILES
	└─src
	   └─RASTERIZER_SOURCE_FILES
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
	│	├─src/
    │	│  └─GTEST_SOURCE_FILES
    │	├─bin/
    │	│  └─test_run
	│	└─build/
	│	   └─MAKEFILES
	├─src/
	│  └─RASTERIZER_SOURCE_FILES
    ├─bin/
    │  └─test_run
	└─build/
	   └─MAKEFILES
```

