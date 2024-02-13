#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


// lets use some object oriented programming as well, well this was an ugly way....


//sfml ma button
class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
//all css bullshit
public:
    Button(float x, float y, float width, float height, string buttonText) {//string data element use handeko
        shape.setPosition(sf::Vector2f(x, y));//read through documentries and made ugly button
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Black);
//yo kina chalena
        text.setString(buttonText);//this could fil the button
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(x + width / 2 - text.getLocalBounds().width / 2, y + height / 2 - text.getLocalBounds().height / 2);
    }
//same as javascript just long function names
    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));//getting the position whenever mouse hovers over the window
        if (shape.getGlobalBounds().contains(mousePos)) {
            return true;
        }
        return false;
    }
//casual rendering
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Button Banako");
//created an object button
    Button button(200, 200, 200, 50, "Press Me");

    while (window.isOpen()) {
      //close button thichda kinda mandatory
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //main point of the program
            if (event.type == sf::Event::MouseButtonPressed) {//if mouse is pressed
                if (button.isMouseOver(window)) {//member function ismouseover called
                   cout << "Button Pressed\n";
                }
            }
        }
//just some formalities
        window.clear(sf::Color::Yellow);
        button.draw(window);
        window.display();
    }

    return 0;
}
