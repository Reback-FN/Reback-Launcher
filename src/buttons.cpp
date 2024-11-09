#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text, const sf::Color& color = sf::Color::Blue, float radius = 0) 
    {
        buttonShape.setPosition(x, y);
        buttonShape.setSize(sf::Vector2f(width, height));
        buttonShape.setFillColor(color);

        buttonShape.setOutlineThickness(radius);
        buttonShape.setOutlineColor(color);

        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Erreur de chargement de la police" << std::endl;
        }

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::White);

        buttonText.setPosition(
            x + (width - buttonText.getLocalBounds().width) / 2,
            y + (height - buttonText.getLocalBounds().height) / 2 - 5
        );
    }

    void draw(sf::RenderWindow& window) {
        window.draw(buttonShape);
        window.draw(buttonText);
    }

    bool isClicked(sf::Vector2i mousePos) {
        return buttonShape.getGlobalBounds().contains(sf::Vector2f(mousePos));
    }

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
};