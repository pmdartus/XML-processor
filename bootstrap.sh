#!/usr/bin/env bash

sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get install -y make
sudo apt-get install -y build-essential
sudo apt-get install m4


# Istall bison
cd /tmp
wget http://ftp.gnu.org/gnu/bison/bison-3.0.2.tar.gz
tar -xvf bison-3.0.2.tar.gz
cd bison-3.0.2/
sudo ./configure
sudo make install

# Install Flex
sudo apt-get install -y flex