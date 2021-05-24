#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

sf::Color random_color()
{
    return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

int main() 
{
    srand(time(NULL));

    int window_size_x = 800;
    int window_size_y = 600;

    // create the window
    sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;
    int counter = 0;

    float rectangle_velocity_x = 50;
    float rectangle_velocity_y = 150;
    float rectangle_angular_velocity = 10;

    // run the program as long as the window is open
    while (window.isOpen()) 
    {
        sf::Time elapsed = clock.restart();
        sf::Int32 t1 = elapsed.asMicroseconds();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();
        if (rectangle_bounds.top <= 0) 
        {
            if (rectangle_velocity_y < 0)
            {
                rectangle_velocity_y = -rectangle_velocity_y;
                rectangle.setFillColor(random_color());
            }
        }
        if (rectangle_bounds.top + rectangle_bounds.height >= window_size_y)
        {
            if (rectangle_velocity_y > 0)
            {
                rectangle_velocity_y = -rectangle_velocity_y;
                rectangle.setFillColor(random_color());
            }
        }
        if (rectangle_bounds.left <= 0)
        {
            if (rectangle_velocity_x < 0)
            {
                rectangle_velocity_x = -rectangle_velocity_x;
                rectangle.setFillColor(random_color());
            }
        }
        if (rectangle_bounds.left + rectangle_bounds.width >= window_size_x)
        {
            if (rectangle_velocity_x > 0)
            {
                rectangle_velocity_x = -rectangle_velocity_x;
                rectangle.setFillColor(random_color());
            }
        }

        rectangle.move(rectangle_velocity_x * t1 / 1'000'000.0f, rectangle_velocity_y * t1 / 1'000'000.0f);
        rectangle.rotate(rectangle_angular_velocity * t1 / 1'000'000.0f);        

        // draw everything here...
        //window.draw(circle);
        window.draw(rectangle);
        //window.draw(triangle);

        // end the current frame
        window.display();

        if (++counter > 1000)
        {
            std::cout.width(8);
            std::cout << 1'000'000/t1 << " FPS" << std::endl;
            counter = 0;
        }
        
    }

    return 0;
}