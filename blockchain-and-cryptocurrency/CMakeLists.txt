# CMakeList.txt : CMake project for blockchain-and-cryptocurrency, include source and define
# project specific logic here.
#

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Add source to this project's executable.
add_executable (blockchain-and-cryptocurrency "blockchain.cpp" "blockchain.h" "transaction.cpp" "transaction.h" "wallet.cpp" "wallet.h" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET blockchain-and-cryptocurrency PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(OpenSSL REQUIRED)
# target_link_libraries(blockchain_simulation OpenSSL::Crypto)
target_link_libraries(blockchain-and-cryptocurrency PRIVATE OpenSSL::SSL OpenSSL::Crypto)
