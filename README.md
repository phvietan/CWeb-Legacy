# Configuring PostgreSQL Database

## Installing PostgreSQL

$ sudo apt update

$ sudo apt install -y postgresql postgresql-contrib libpq-dev

## Managing user for the app

$ sudo -u postgres createuser --interactive

username: cweb & superuser = y

$ sudo -u postgres createdb cweb

$ sudo adduser cweb

## Installing PostgreSQL connector for C/C++

Based on (this)[https://www.tutorialspoint.com/postgresql/postgresql_c_cpp]

Note: I am using Ubuntu 16

$ wget http://pqxx.org/download/software/libpqxx/libpqxx-4.0.tar.gz

$ tar xvfz libpqxx-4.0.tar.gz

$ cd libpqxx-4.0

$ ./configure

$ make -j 8

$ sudo make install

$ service postgresql restart