# CMakeList.txt : CMake project for atomic-ref, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (atomic-ref "atomic-ref.cpp"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET atomic-ref PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
