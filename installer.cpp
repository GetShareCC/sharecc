#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

int pigdig = 100;

int main() {
    bool clicked = true; // i don't know why this works, it makes no sense. but it does work

    // create entities
    sf::RenderWindow window(sf::VideoMode(400, 400), "ShareCC - Installer", sf::Style::Close);
    window.setFramerateLimit(144);
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::Text smallheader;
    sf::Text credits;
    sf::Sprite mouse;
    sf::Texture mousetex;
    sf::Text sustext;
    sf::Text started;
    sf::RectangleShape button;
    sf::Text buttonText;
    sf::RectangleShape button2;
    sf::Text buttonText2;
    sf::Text license;

    text.setString("Welcome To ShareCC!");
    license.setString("By installing, you agree to the MIT License at https://mit-license.org/");

    started.setString("Lets get started!");

    // sets all entity info
    credits.setString("Copyright SomeRandomPiggo. All rights reserved.");

    mousetex.setSmooth(true);
    mousetex.loadFromFile("cursors/left_ptr.png");
    mouse.setTexture(mousetex);
    window.setMouseCursorVisible(false);


    font.loadFromFile("fonts/ui.ttf");

    text.setCharacterSize(28);
    text.setFont(font);
    text.setFillColor(sf::Color{ 252, 159, 0 });

    credits.setCharacterSize(12);
    credits.setFont(font);
    credits.setFillColor(sf::Color(252, 159, 0));
    credits.setPosition(4.f, 383.f);

    license.setCharacterSize(12);
    license.setFont(font);
    license.setFillColor(sf::Color(252, 159, 0));
    license.setPosition(4.f, 383.f);

    started.setCharacterSize(12);
    started.setFont(font);
    started.setFillColor(sf::Color(252, 159, 0));
    started.setPosition(4.f,  383.f);

    text.setCharacterSize(22);
    text.setFont(font);
    text.setFillColor(sf::Color{ 252, 159, 0 });

    button.setSize(sf::Vector2f(98.f, 23.f));
    button.setOutlineColor(sf::Color(30,30,30));
    button.setOutlineThickness(2.f);
    button.setPosition(20,40);
    buttonText.setFont(font);
    buttonText.setCharacterSize(12);
    buttonText.setString("Install");
    button.setFillColor(sf::Color{50,50,50});
    
    button2.setSize(sf::Vector2f(98.f, 23.f));
    button2.setOutlineColor(sf::Color(30,30,30));
    button2.setOutlineThickness(2.f);
    button2.setPosition(20,40);
    buttonText2.setFont(font);
    buttonText2.setCharacterSize(12);
    buttonText2.setString("Exit");
    button2.setFillColor(sf::Color{50,50,50});
    
    // Terrible centering code

    float width = text.getLocalBounds().width;
    float intermediate = (400 - width);
    float textpos = (intermediate / 2);
    text.setPosition(textpos, 5);

    width = credits.getLocalBounds().width;
    intermediate = (400 - width);
    textpos = (intermediate / 2);
    credits.setPosition(textpos, 380);

    width = license.getLocalBounds().width;
    intermediate = (400 - width);
    textpos = (intermediate / 2);
    license.setPosition(textpos, 125);

    width = button.getLocalBounds().width;
    intermediate = (400 - width);
    textpos = (intermediate / 2);
    button.setPosition(textpos, 150);
    buttonText.setPosition(button.getPosition());

    width = button2.getLocalBounds().width;
    intermediate = (400 - width);
    textpos = (intermediate / 2);
    button2.setPosition(textpos, 180);
    buttonText2.setPosition(button.getPosition());

    width = button.getLocalBounds().width;
    intermediate = (98 - width);
    float bttntextpos = (intermediate / 2);
    buttonText.setPosition(182, 154);

    width = button2.getLocalBounds().width;
    intermediate = (98 - width);
    bttntextpos = (intermediate / 2);
    buttonText2.setPosition(188, 184);

    // Main Render Loop
    while (window.isOpen())
    {
        // Check to see all actions were completed on close
        while (window.pollEvent(event)) {
            // To close the window on the close button being pushed, pretty obvious really
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
        
        // Check for inputs

        if(event.type == sf::Event::MouseWheelScrolled) {
            if (event.mouseWheelScroll.delta == -1) {
                mouse.rotate(-1);
            }
            else if (event.mouseWheelScroll.delta == 1){
                mouse.rotate(1);
            }
            
        }


        // Button click detection! My code is so bad, honestly if you are reading this, just beware
        if (button.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            button.setOutlineColor(sf::Color(252, 159, 0));
            mousetex.loadFromFile("cursors/pointing_hand.png");
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (clicked = true) {
                    FILE *f = popen("zenity --error --title='ShareCC - Error' --text='You need to specify an install location.'", "r");
                    clicked = false;
                }
            }
            else {
                clicked = true;
            }
        }
        else {
            button.setOutlineColor(sf::Color(30,30,30));
            mousetex.loadFromFile("cursors/left_ptr.png");
        }

        if (button2.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            button2.setOutlineColor(sf::Color(252, 159, 0));
            mousetex.loadFromFile("cursors/pointing_hand.png");
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (clicked = true) {
                    return 0;
                }
            }
            else {
                clicked = true;
            }
        }
        else {
            button2.setOutlineColor(sf::Color(30,30,30));
            mousetex.loadFromFile("cursors/left_ptr.png");
        }

        // Opening Animation


        // Set dynamic positions and draw entities
        window.clear(sf::Color{ 38, 38, 38, 38 });  
        window.draw(text);
        window.draw(license);
        mouse.setPosition((float)mousepos.x, static_cast<float>(mousepos.y));
        window.draw(credits);
        window.draw(button);
        window.draw(buttonText);
        window.draw(button2);
        window.draw(buttonText2);
        window.draw(mouse);
        window.display();
    }
return 0;
}
