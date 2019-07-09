# Configuring PostgreSQL Database

## Installing PostgreSQL

$ sudo apt update

$ sudo apt install -y postgresql postgresql-contrib

## Managing user for the app

$ sudo -u postgres createuser --interactive

username: cweb & superuser = y

$ sudo -u postgres createdb cweb

$ sudo adduser cweb

## Installing PostgreSQL connector for C/C++

$ sudo apt install -y libreadline-dev libpq-dev zlib1g-dev

$ git clone https://github.com/jtv/libpqxx.git

$ cd libpqxx

$ ./configure --disable-documentation

$ make

$ sudo make install