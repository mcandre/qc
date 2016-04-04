# qc - a C port of the QuickCheck unit test framework

# EXAMPLE

```
$ cmake . && make

$ bin/example
+++ OK, passed 100 tests.
*** Failed!
1200315752
*** Failed!
1909203817
287898845
435231224
*** Failed!
'9'
9
*** Failed!
T9^/NeP)Y^k/"-V$DSJ"U/.$vT<ih(|
```

See [example.c](https://github.com/mcandre/qc/blob/master/lib/example.c) for more information.

# HOMEPAGE

http://www.yellosoft.us/quickcheck

# LICENSE

FreeBSD

# REQUIREMENTS

## Compiler Collection

* [clang](http://clang.llvm.org/)

E.g. from Xcode

* [gcc](https://gcc.gnu.org/)

E.g. from Apt, Dnf, Homebrew, MinGW, Strawberry Perl

## CMake

* [cmake](https://cmake.org/)

E.g. `brew install cmake`

## Ubuntu

* [libgc-dev](http://packages.ubuntu.com/search?keywords=libgc-dev&searchon=names)

Example: `sudo apt-get install libgc-dev`

## Windows

* [BoehmGC](http://www.hpl.hp.com/personal/Hans_Boehm/gc/)

## Mac OS X

* [Homebrew](http://brew.sh/)
* `boehmgc`

Example: `brew install boehmgc`

## Optional

* [Python](https://www.python.org/) 2+ (for infer)
* [cppcheck](http://cppcheck.sourceforge.net/)
* [splint](http://www.splint.org/)
* [vera++](https://bitbucket.org/verateam/vera/wiki/Home)
* [valgrind](http://www.valgrind.org/)
* [Ruby](https://www.ruby-lang.org/) 2+
* [Bundler](http://bundler.io/)
* [Cucumber](http://cukes.info/)
* [Guard](http://guardgem.org/)
* [aspelllint](https://github.com/mcandre/aspelllint)

# DEVELOPMENT

## Test

Ensure the example script works as expected:

```
$ bundle
$ cucumber
Feature: Run example tests

  Scenario: Running example tests            # features/run_example_tests.feature:3
    Given the program has finished           # features/step_definitions/steps.rb:1
    Then the output is correct for each test # features/step_definitions/steps.rb:7

1 scenario (1 passed)
2 steps (2 passed)
0m0.091s
```

## Grind

Eliminate memory leaks:

```
$ make valgrind
...
```

## Spell Check

```
$ aspelllint
...
```

## Local CI

Guard can automatically run testing when the code changes:

```
$ bundle
$ guard -G Guardfile-cucumber
...
```
