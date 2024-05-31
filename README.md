# Blockchain

## :newspaper: About the project

This project simulates a basic blockchain and cryptocurrency system. It demonstrates the core functionalities of a blockchain, including block creation, mining, and validation. Each block contains an index, a hash of the previous block, a list of transactions, a timestamp, and a nonce for proof-of-work. The project is implemented in C++ and uses OpenSSL for cryptographic hashing. This simulation provides an educational example of how blockchain technology underpins cryptocurrencies, showcasing key concepts such as decentralization, immutability, and consensus.

### Content overview

    .
    ├── blockchain-and-cryptocurrency/ - source code
    ├── pkgs_installed/ - folder to store installed packages
    ├── storage/ - folder to store package archives
    ├── tests/ - contains testcases
    ├── vcpkg/ - contains vcpkg package manager
    ├── tests/ - folder to store the installed packages
    ├── .gitignore - ignore files, folders, etc. for version control
    ├── CMakeLists.txt - configurations for cmake buildsystem
    ├── CMakePresets.json - settings for cmake buildsystem
    ├── COPYRIGHT - project copyright
    └── README.md - relevant information about the project

## :notebook: Features

* Mine a block
* Get the entire chain
* Check validity of the Blockchain
* Add a transaction
* Connect to a single node
* Reset the chain

## :runner: Getting started

### Prerequisites and example usage

0. Clone the project:

```sh
git clone https://github.com/CH6832/blockchain-and-cryptocurrency.git
```

1. Navigate into root folder:

```sh
cd blockchain-and-cryptocurrency
```

2. Run the application.

## :books: Resources used to create this project

* CPlusPlus
  * [C++ Programming Language](https://devdocs.io/cpp/)
  * [Standard C++ Library reference](https://cplusplus.com/reference/)
  * [C++ reference](https://en.cppreference.com/w/)
  * [CMake Documentation and Community](https://cmake.org/documentation/)
* Editor
  * [Visual Studio Community Edition](https://code.visualstudio.com/)
* Markdwon
  * [Basic syntax](https://www.markdownguide.org/basic-syntax/)
  * [Complete list of github markdown emofis](https://dev.to/nikolab/complete-list-of-github-markdown-emoji-markup-5aia)
  * [Awesome template](http://github.com/Human-Activity-Recognition/blob/main/README.md)
  * [.gitignore file](https://git-scm.com/docs/gitignore)

## :bookmark: License

This project is licensed under the terms of the [GPL v3](LICENSE).

## :copyright: Copyright

See the [LICENSE](LICENSE) file for copyright and licensing details.
