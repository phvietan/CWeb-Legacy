# CWeb

This repo holds my C/C++ Web service code.

The main purpose of this repo:

- Learn C/C++ especially when applying OOP/Design pattern.
- Learn to use various hard-to-understand C/C++ syntax: pointers, template, etc...
- Learn & explore Linux system when connecting to database (because C/C++ is very near to Linux system, unlike Python, NodeJS, Ruby, ...).
- Applying/Implementing Cryptography papers (currently studying Symmetric Searchable Encryption).

# Installation

- sudo apt install libboost-all-dev

## Install Crypto++ lib

- Github repo: [https://github.com/weidai11/cryptopp](https://github.com/weidai11/cryptopp)

- Clone that repo

- cd <cryptopp directory>

- make -j8

- make test

- mkdir ~/.usrlib/

- make install PREFIX=~/.usrlib/

- mv cryptopp src/cryptopp/

## Install database

- Follow database/README.md to install database