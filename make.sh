echo "Welcome To Scribe Builder"
echo "Building 'main.cpp' with arguments -lsfml-graphics -lsfml-window -lsfml-system"
g++ installer.cpp -o scribe -lsfml-graphics -lsfml-window -lsfml-system
echo "Done compiling! Now running."
./scribe
echo "Scribe has terminated! If you closed the program yourself, this is fine. But if this happened shortly after the last message, there may be an error in your code."
