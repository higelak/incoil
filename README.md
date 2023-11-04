# incoil [![GitHub](https://img.shields.io/github/license/higelak/incoil)](https://github.com/higelak/incoil/blob/main/LICENSE)
Instance counter and once initializator

## Description
Incoil is a small header for organizing a class instance counter.

It also allows you to implement initialization when creating the first instance of a class and deinitialization when deleting the last instance. 
It is provided that if initialization is not successful, then the class instance is deleted.

See example.cpp for undestanding.

## Example output
```bash
[CurlClass] ctor...
Init [CurlClass]...
[CurlClass] ctor...
[CurlClass] ctor...
[SomeClass] ctor...
Init [SomeClass]...
[SomeClass] ctor...
[SomeClass] ctor...
[SomeClass] ctor...
[SomeClass] ctor...
[UnsuccessClass] ctor...
Init [UnsuccessClass]...
### Init [class UnsuccessClass] failed!
[UnsuccessClass] dtor...
[UnsuccessClass] ctor...
Init [UnsuccessClass]...
### Init [class UnsuccessClass] failed!
[UnsuccessClass] dtor...
How many instances of CurlClass: 3
How many instances of SomeClass: 5
How many instances of UnsuccessClass: 0
[SomeClass] dtor...
[SomeClass] dtor...
[SomeClass] dtor...
[SomeClass] dtor...
Shutdown [SomeClass]...
[SomeClass] dtor...
[CurlClass] dtor...
[CurlClass] dtor...
Shutdown [CurlClass]...
[CurlClass] dtor...
```

## Building incoil
I use [premake5](http://premake.github.io/) to build solution and project files. Download it and make sure it's available on your path, or specify the path to it. Execute command:
```bash
premake5 vs2022
```
