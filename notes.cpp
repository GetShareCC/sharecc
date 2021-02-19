Notes:

std::cout << "Button was clicked!";
char filename[1024];
FILE *f = popen("zenity --file-selection", "r");
fgets(filename, 1024, f);
std::cout << filename;
clicked = false;