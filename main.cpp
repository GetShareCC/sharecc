#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <string>

int pigdig = 100;

void settings() {
    sf::Text settings;
    settings.setString("this is a test");
    sf::RenderWindow settingwin(sf::VideoMode(600, 400), "Scribe - Settings", sf::Style::Default);
    sf::Event event;


    // Main loop
    while (settingwin.isOpen()) {
        while (settingwin.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                settingwin.close();
            }
        }
        settingwin.draw(settings);
        settingwin.display();
    }
}

int main() {
    bool clicked = false;

    // create entities
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Share", sf::Style::Fullscreen);
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::Text credits;
    sf::Thread settingsthread(&settings);
    sf::Sprite mouse;
    sf::Texture mousetex;
    sf::Text sustext;
    sf::RectangleShape button;
    sf::Text buttonText;
    text.setString("default: running uncapped fps (space for cap)");
    
    // sets all entity info
    credits.setString("Scribe v0.0.1");
    
    mousetex.setSmooth(true);
    mousetex.loadFromFile("cursors/left_ptr.png");
    mouse.setTexture(mousetex);


    font.loadFromFile("fonts/ui.ttf");

    text.setPosition(10.f, 10.f);
    text.setCharacterSize(18);
    text.setFont(font);
    text.setFillColor(sf::Color{ 252, 159, 0 });
    
    credits.setCharacterSize(16);
    credits.setFont(font);
    credits.setFillColor(sf::Color{ 252, 159, 0 });
    credits.setPosition(4.f, 580.f);
    
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
        button.setSize(sf::Vector2f(98.f, 23.f));
        buttonText.setPosition((float)mousepos.x, static_cast<float>(mousepos.y));
        button.setOutlineColor(sf::Color(30,30,30));
        button.setOutlineThickness(2.f);
        button.setPosition(20,40);
        buttonText.setFont(font);
        buttonText.setCharacterSize(12);
        buttonText.setString("Button!");
        button.setFillColor(sf::Color{50,50,50});
        


        if (button.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
            button.setOutlineColor(sf::Color(252, 159, 0));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                clicked = true;
            }
            else {
                if (clicked = true) {
                    std::cout << "Button was clicked!";
                    clicked = false;
                }
            }
        }
        else {
            button.setOutlineColor(sf::Color(30,30,30));
        }

        // Set dynamic positions and draw entities
        window.clear(sf::Color{ 38, 38, 38, 38 });  
        window.draw(text);
        mouse.setPosition((float)mousepos.x, static_cast<float>(mousepos.y));
        window.draw(credits);
        window.draw(button);
        window.draw(buttonText);
        // window.draw(mouse);
        window.display();
    }
return 0;
}