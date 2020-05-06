#include <SFML/Graphics.hpp>
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("resources/2x/attack_0.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    //draw background (let's start with white, to see our sprite better)
    //
    sf::RectangleShape square(sf::Vector2f(window.getSize().x,window.getSize().y));
    square.setFillColor(sf::Color::White);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        window.draw(square);
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return 0;
}
