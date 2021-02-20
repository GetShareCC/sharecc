echo "This sh script will build ShareCC"
echo "Building 'installer.cpp' with arguments -lsfml-graphics -lsfml-window -lsfml-system"
g++ installer.cpp -o ShareCC -lsfml-graphics -lsfml-window -lsfml-system
echo "Done compiling! Now running."
./ShareCC
echo "Scribe has terminated! If you closed the program yourself, this is fine. But if this happened shortly after the last message, there may be an error in your code."
