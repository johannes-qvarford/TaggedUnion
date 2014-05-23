An example program showing off the tut::TaggedUnion class.
tut::TaggedUnion is a union like class that prevents a user from assigning to a union member and
then reading from another without a reassignment.

Build with cmake (minimum version 2.8) in Release mode to have the program perform an illegal action
and to Debug mode to have the program assert on the illegal action.

Instructions:

cd build_directory
cmake -DCMAKE_BUILD_TYPE=Release|Debug project_directory
build and run(not debug) with visual studio or some other build system.