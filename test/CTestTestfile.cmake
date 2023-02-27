# CMake generated Testfile for 
# Source directory: /home/karthik/Computers/tchecker/test
# Build directory: /home/karthik/Computers/tchecker/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(build-tchecker "/usr/bin/cmake" "--build" "/home/karthik/Computers/tchecker" "--config" "Release" "--target" "tchecker")
set_tests_properties(build-tchecker PROPERTIES  FIXTURES_SETUP "BUILD_TCHECKER" _BACKTRACE_TRIPLES "/home/karthik/Computers/tchecker/test/CMakeLists.txt;58;add_test;/home/karthik/Computers/tchecker/test/CMakeLists.txt;0;")
subdirs("testutils")
subdirs("unit-tests")
subdirs("bugfixes")
subdirs("simple-nr")
subdirs("covreach")
subdirs("explore")
