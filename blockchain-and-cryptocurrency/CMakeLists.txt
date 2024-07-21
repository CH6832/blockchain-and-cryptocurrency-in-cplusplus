# CMakeList.txt : CMake project for blockchain-and-cryptocurrency, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (blockchain-and-cryptocurrency "main.cpp"  "Blockchain.cpp" "Blockchain.h" "Block.h" "Block.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET blockchain-and-cryptocurrency PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Find OpenSSL
find_package(OpenSSL REQUIRED)
# Include the OpenSSL directories
target_include_directories(blockchain-and-cryptocurrency PRIVATE ${OPENSSL_INCLUDE_DIR})
# Link against the OpenSSL libraries
target_link_libraries(blockchain-and-cryptocurrency PRIVATE OpenSSL::SSL OpenSSL::Crypto)
