shacl trait
==================

In the C++ 11 standard introduced a small collection of utilities for
compile-time introspection and metaprogramming, by way of the `type_traits`
header. This header was subsequently expanded in the C++14 and C++17 standards.

These facilities are often very helpful in the context of generic programming,
namely to dispatch between available templated implementations based on one or
more template parameters without resorting to explicit template specialization.

For more information on the standard facilities and this mechanism of template
dispatch (i.e. concept emulation), please see the additional resources below.

This library provides:

+ backports of `type_types` features introduced within the C++17 standard to
C++14
+ an extended set of type traits found to be useful in the course of developing
other shacl library.

Standard Capabilities
------------------------

Backports of standard library features are available in the `shacl::trait`
namespace, albeit under slightly different names in some cases.

+ `std::conjunction` -> `shacl::trait::Conjunction`
+ `std::conjunction_v` -> `shacl::trait::Conjunction_v`
+ `std::disjunction` -> `shacl::trait::Disjunction`
+ `std::disjunction_v` -> `shacl::trait::Disjunction_v`
+ `std::invoke_result` -> `shacl::trait::InvokeResult`
+ `std::invoke_result_t` -> `shacl::trait::InvokeResult_t`
+ `std::is_invocable` -> `shacl::trait::InvokeDefined`
+ `std::is_invocable_v` -> `shacl::trait::InvokeDefined_v`
+ `std::is_nothrow_invocable` -> `shacl::trait::InvokeNoThrow`*
+ `std::is_nothrow_invocable_v` -> `shacl::trait::InvokeNoThrow_v`*
+ `std::is_nothrow_swappable` -> `shacl::trait::SwapNoThrow`*
+ `std::is_nothrow_swappable_v` -> `shacl::trait::SwapNoThrow_v`*
+ `std::is_swappable` -> `shacl::trait::Swappable`
+ `std::is_swappable_v` -> `shacl::trait::Swappable_v`
+ `std::negate` -> `shacl::trait::Negate`
+ `std::negate_v` -> `shacl::trait::Negate_v`
+ `std::void_t` -> `shacl::trait::void_t`

\* These shacl traits have slightly different semantics than their standard
library conterparts. In each case, the shacl version of each type trait struct
only has a nested static `value` data member if (and only if) the prefix trait
is true, whereas the standard library version will always provide a static
`value` data member. For example, an instantiation of `InvokeNoThrow`,
parameterized on som type `T`, will only ha a static `value` data member iff
`shacl::trait::InvokeDefined<T>::value` is `true`.

Extended Capabilities
------------------------

In addition to the standard library facilities, this library provides additional
functionality. For those familiar with the standard library traits, the use
these templates should come quite naturally.

+ `shacl::trait::EqualityDefined` and `shacl::trait::EqualityDefined_v`
+ `shacl::trait::EqualityResult` and `shacl::trait::EqualityResult_t`
+ `shacl::trait::InequalityDefined` and `shacl::trait::InequalityDefined_v`
+ `shacl::trait::InequalityResult` and `shacl::trait::InequalityResult_t`
+ `shacl::trait::EqualityComparable` and `shacl::trait::EqualityComparable_v`

+ `shacl::trait::LessThanDefined` and `shacl::trait::LessThanDefined_v`
+ `shacl::trait::LessThanResult` and `shacl::trait::LessThanResult_t`
+ `shacl::trait::LessThanEqualDefined` and `shacl::trait::LessThanEqualDefined_v`
+ `shacl::trait::LessThanEqualResult` and `shacl::trait::LessThanEqualResult_t`
+ `shacl::trait::GreaterThanDefined` and `shacl::trait::GreaterThanDefined_v`
+ `shacl::trait::GreaterThanResult` and `shacl::trait::GreaterThanResult_t`
+ `shacl::trait::GreaterThanEqualDefined` and `shacl::trait::GreaterThanEqualDefined_v`
+ `shacl::trait::GreaterThanEqualResult` and `shacl::trait::GreaterThanEqualResult_t`
+ `shacl::trait::Comparable` and `shacl::trait::Comparable_v`

+ `shacl::trait::MultiplicationDefined` and `shacl::trait::MultiplicationDefined_v`
+ `shacl::trait::Product` and `shacl::trait::Product_t`
+ `shacl::trait::DivisionDefined` and `shacl::trait::DivisionDefined_v`
+ `shacl::trait::Quotient` and `shacl::trait::Quotient_t`
+ `shacl::trait::Scalable` and `shacl::trait::Scalable_v`

+ `shacl::trait::AdditionDefined` and `shacl::trait::AdditionDefined_v`
+ `shacl::trait::Sum` and `shacl::trait::Sum_t`
+ `shacl::trait::SubtractionDefined` and `shacl::trait::SubtractionDefined_v`
+ `shacl::trait::Difference` and `shacl::trait::Difference_t`
+ `shacl::trait::Arithmetic` and `shacl::trait::Arithmetic_v`

+ `shacl::trait::DereferenceDefined` and `shacl::trait::DereferenceDefined_v`
+ `shacl::trait::DereferenceResult` and `shacl::trait::DereferenceResult_t`

+ `shacl::trait::SubscriptDefined` and `shacl::trait::SubscriptDefined_v`
+ `shacl::trait::SubscriptResult` and `shacl::trait::SubscriptResult_t`

+ `shacl::trait::IsRange` and `shacl::trait::IsRange_v`
+ `shacl::trait::RangeTraits`

+ `shacl::trait::Identity` and + `shacl::trait::Identity_t`
+ `shacl::trait::ConditionalApplication` and `shacl::trait::ConditionalApplication_t`

+ `shacl::trait::Compound` and + `shacl::trait::Compond_t`

Build System
--------------

As a header-only library, `shacl::trait` has no compiled components.
Nevertheless, a [CMake](https://cmake.org/overview/) build system is provided to
allow easy testing, installation, and subproject composition on many platforms
and operating systems. CMake version 3.8 or later is required to configure and
build this library.

#### Compiler Support

The shacl::variant library is written in C++14, and makes considerable use of
template metaprogramming, generalized constant expressions, and SFINAE. As such,
a relatively robust C++ compiler supporting the C++14 standard is required. The
following compilers are explicitly supported.

+ GNU g++ version 6.0.0 or later
+ LLVM clang++ version 3.5 or later
+ Xcode version 6.3/Apple clang++ version 9.0.0 or later
+ Visual Studio 2017 Update 8 (version 15.8) or later
+ Intel icpc version 18.0.3 or later

The current IBM XLC++ compiler (16.1.1) supports only a subset of the C++ 14
standard. It's currently untested with this library.

#### Dependencies

While the library itself depends only upon the C++ standard library,
testing distributed with the `shacl::trait` library is dependent on the *Catch2*
unit testing framework. See the **Testing** section below for more information.

Given an internet connection, by default, the *Catch2* library will be
downloaded (without any need for user intervention) during the CMake
configuration step. If this behavior is undesirable, users can opt to consume a
local installation of *Catch2* by setting the `git.submodule.packages` CMake
option to `OFF`. Non-standard installation roots to *Catch2* can be specified
using the `CMAKE_PREFIX_PATH` environment variable or CMake option. See the
CMake [`find_package`](https://cmake.org/cmake/help/v3.0/command/find_package.html)
documentation for more information. Alternatively, the *Catch2* dependency can
be avoided by disabling testing. This can be achieved by setting either the
`BUILD_TESTING` or `trait.tests` CMake cache variables to `OFF`.

#### Testing

The shacl::trait library is distributed with a suite of tests. When
`shacl::trait` is configured as the highest level CMake project, this suite
of executables is built by default. These test executables are integrated with
the CMake test driver program,
[CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html).

#### Building

CMake supports a number of backends for compilation and linking.

To use a static configuration build tool, such as GNU Make or Ninja:

```sh
cd <shacl::trait source directory>
mkdir build
cd build

# Configure the build
cmake -D CMAKE_BUILD_TYPE=<Debug | Release> \
      -G <"Unix Makefiles" | "Ninja"> ..

# build the tests
< make | ninja | cmake --build . >

# run the tests
< make test | ninja test | cmake --build . --target test | ctest >
```

To use a dynamic configuration build tool, such as Visual Studio or Xcode:

```sh
cd <shacl::trait source directory>
mkdir build
cd build

# Configure the build
cmake -G <"Visual Studio 14 2015 Win64" | "Xcode"> ..

# build the tests
cmake --build . --config <Debug | Release>

# run the tests via ctest...
ctest --build-config <Debug | Release>

# ... or via CMake build tool mode...
cmake --build . --config <Debug | Release> --target test
```

Of course the **build** and **test** steps can also be executed via the **all**
and **test** targets, respectively, from within the IDE after opening the
project file generated during the configuration step.

This testing is also configured to operate as a client to the
[CDash](https://www.cdash.org/) software quality dashboard application. Please
see the [Kitware documentation](https://cmake.org/cmake/help/latest/manual/ctest.1.html#dashboard-client)
for more information on this mode of operation.

#### Installation

The shacl::trait library build system provides an installation target and
support for downstream consumption via CMake's
[`find_package`](https://cmake.org/cmake/help/v3.0/command/find_package.html)
intrinsic function. CMake allows installation to an arbitrary location, which
may be specified by defining `CMAKE_INSTALL_PREFIX` at configure time.
In the absense of a user specification, CMake will install shacl::trait to
conventional location based on the platform operating system.

To use a static configuration build tool, such as GNU Make or Ninja:

```sh
cd <shacl::trait source directory>
mkdir build
cd build

# Configure the build
cmake [-D CMAKE_INSTALL_PREFIX="path/to/installation"] \
      [-D BUILD_TESTING=False]                         \
      [-D BOOST_ROOT="path/to/boost/installation"]     \
      -D CMAKE_BUILD_TYPE=Release                      \
      -G <"Unix Makefiles" | "Ninja"> ..

# install shacl::trait
<make install | ninja install | cmake --build . --target install>
```

To use a dynamic configuration build tool, such as Visual Studio or Xcode:

```sh
cd <shacl::trait source directory>
mkdir build
cd build

# Configure the project
cmake [-D CMAKE_INSTALL_PREFIX="path/to/installation"] \
      [-D BUILD_TESTING=False]                         \
      [-D BOOST_ROOT="path/to/boost/installation"]     \
      -G <"Visual Studio 14 2015 Win64" | "Xcode"> ..

# install shacl::trait
cmake --build . --config Release --target install
```

Note that the last command of the installation sequence may require
administrator privileges (e.g. `sudo`) if the installation root directory lies
outside your home directory.

This installation
+ copies the shacl::trait header files to the `include/shacl` subdirectory of
the installation root
+ generates and copies several CMake configuration files to the
`share/cmake/shacl/trait` subdirectory of the installation root

This latter step allows downstream CMake projects to consume shacl::trait via
`find_package`, e.g.

```cmake
find_package(shacl REQUIRED COMPONENTS trait)
target_link_libraries(MyTarget PUBLIC shacl::trait)
```

If `shacl::trait` was installed to a non-conventional location, it may be
necessary for downstream projects to specify the shacl installation root
directory via either

+ the `CMAKE_PREFIX_PATH` configuration option,
+ the `CMAKE_PREFIX_PATH` environment variable, or
+ `shacl_DIR` environment variable.

Please see the
[Kitware documentation](https://cmake.org/cmake/help/v3.0/command/find_package.html)
for more information.

In addition, shacl::trait supports packaged relocatable installations via
[CPack](https://cmake.org/cmake/help/latest/manual/cpack.1.html).
Following configuration, from the build directory, invoke cpack as follows to
generate a packaged installation:

```sh
cpack -G <generator name> -C Release
```

The list of supported generators varies from platform to platform. See the
output of `cpack --help` for a complete list of supported generators on your
platform.

Recommended Introductory Material
------------------------

In suggested order

1. [An introduction to C++ Traits](https://accu.org/index.php/journals/442)
1. [Concepts without Concepts](https://akrzemi1.wordpress.com/2016/03/21/concepts-without-concepts/)
2. [SFINAE and enable_if](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/)
