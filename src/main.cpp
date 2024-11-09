#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "buttons.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Reback");

    Button button(300, 275, 200, 50, "Install", sf::Color(173, 216, 230), 40);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
        return -1;
    }

    sf::Text message;
    message.setFont(font);
    message.setString("");
    message.setCharacterSize(30);
    message.setFillColor(sf::Color::Black);
    message.setPosition(250, 150);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (button.isClicked(sf::Mouse::getPosition(window))) {
                    message.setString("Installing Fortnite..");
                }
            }
        }

        window.clear(sf::Color::White);

        button.draw(window);
        window.draw(message);

        window.display();
    }

    return 0;
}