g++ main.cpp -o sharecc-installer -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
./sharecc-installer
