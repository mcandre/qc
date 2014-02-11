# qc - A C port of the QuickCheck unit test framework

# EXAMPLE

    $ make
    clang -O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith -o example example.c qc.c -lgc
    ./example
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

# HOMEPAGE

[http://www.yellosoft.us/quickcheck](http://www.yellosoft.us/quickcheck)

# LICENSE

FreeBSD

# REQUIREMENTS

* [clang](http://clang.llvm.org/), such as from [Xcode](https://developer.apple.com/xcode/)

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

* [splint](http://www.splint.org/)
* [vera++](https://bitbucket.org/verateam/vera/wiki/Home)

* [Ruby](https://www.ruby-lang.org/) 2+
* [Bundler](http://bundler.io/)
* [Cucumber](http://cukes.info/)
* [Guard](http://guardgem.org/)

# TESTING

Ensure the example script works as expected:

    $ bundle
    $ cucumber
    Feature: Run example tests

      Scenario: Running example tests            # features/run_example_tests.feature:3
        Given the program has finished           # features/step_definitions/steps.rb:1
        Then the output is correct for each test # features/step_definitions/steps.rb:7

    1 scenario (1 passed)
    2 steps (2 passed)
    0m0.091s

Guard can automatically run testing when the code changes:

    $ bundle
    $ guard -G Guardfile-cucumber
    ...
