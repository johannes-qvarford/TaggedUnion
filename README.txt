An example program showing off the tut::TaggedUnion class.
tut::TaggedUnion is a union like class that prevents a user from assigning to a union member and
then reading from another without a reassignment.

Build with cmake i(minimum version 2.8) setting the build type to Release to have the program perform the illegal action
and to Debug to have the program assert on the illegal action.

Instructions:

cd build_directory
cmake -DCMAKE_BUILD_TYPE=Release|Debug project_directory
make
./TaggedUnionTest | TaggedUnionTest.exe
