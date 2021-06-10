#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Color random_color()
{
    return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

class customRectangleShape : public sf::RectangleShape
{
public:
    customRectangleShape(sf::Vector2f& size, sf::Vector2f& position) : sf::RectangleShape(size) { this->setPosition(position); };
    void setSpeed(float x, float y, float r) { x_speed = x; y_speed = y; rotation_speed = r; };
    void animate(sf::Time& elapsed);
    void setBounds(int top, int bottom, int left, int right) { limit_top = top; limit_bottom = bottom; limit_left = left; limit_right = right; };
    void select() { is_selected = true; setFillColor(random_color()); };
    void unselect() { is_selected = false; setFillColor({ 128,128,128 }); };
protected:
    float x_speed = 0;
    float y_speed = 0;
    float rotation_speed = 0;

    int limit_top;
    int limit_bottom;
    int limit_left;
    int limit_right;

    bool is_selected = false;

    void bounce();
};

void customRectangleShape::animate(sf::Time& elapsed)
{
    sf::Int32 t = elapsed.asMicroseconds();
    
    if (!is_selected)
    {
        this->move(x_speed * t / 1'000'000.0f, y_speed * t / 1'000'000.0f);
        this->rotate(rotation_speed * t / 1'000'000.0f);

        this->bounce();
    }
    else
    {
        sf::FloatRect rectangle_bounds = this->getGlobalBounds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
        {
            if (rectangle_bounds.top > limit_top)
            {
                this->move(0, -abs(y_speed) * t / 1'000'000.0f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (rectangle_bounds.top + rectangle_bounds.height < limit_bottom)
            {
                this->move(0, abs(y_speed) * t / 1'000'000.0f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (rectangle_bounds.left > limit_left)
            {
                this->move(-abs(y_speed) * t / 1'000'000.0f, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (rectangle_bounds.left + rectangle_bounds.width < limit_right)
            {
                this->move(abs(y_speed) * t / 1'000'000.0f, 0);
            }
        }
    }
}

void customRectangleShape::bounce() 
{
    sf::FloatRect rectangle_bounds = this->getGlobalBounds();

    if (rectangle_bounds.top <= limit_top)
    {
        if (y_speed < 0)
        {
            y_speed = -y_speed;
        }
    }
    if (rectangle_bounds.top + rectangle_bounds.height >= limit_bottom)
    {
        if (y_speed > 0)
        {
            y_speed = -y_speed;
        }
    }
    if (rectangle_bounds.left <= limit_left)
    {
        if (x_speed < 0)
        {
            x_speed = -x_speed;
        }
    }
    if (rectangle_bounds.left + rectangle_bounds.width >= limit_right)
    {
        if (x_speed > 0)
        {
            x_speed = -x_speed;
        }
    }
}

int main() 
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    std::vector<customRectangleShape> rectangles;

    for (int i = 0; i < 10; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(customRectangleShape(size, position));
    }

    for (auto& rec : rectangles) {
        rec.setFillColor(sf::Color(128, 128, 128));
        rec.setBounds(0, window.getSize().y, 0, window.getSize().x);
        rec.setSpeed(200, 200, 10);
    }

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen()) 
    {
        sf::Time deltaTime = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape) 
                {
                    window.close();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.key.code == sf::Mouse::Left || event.key.code == sf::Mouse::Right)
                {
                    sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    for (size_t i = 0; i < rectangles.size(); i++)
                    {
                        sf::FloatRect rectangle_bounds = rectangles[i].getGlobalBounds();
                        if (mouse_position.x > rectangle_bounds.left && mouse_position.x < rectangle_bounds.left + rectangle_bounds.width && mouse_position.y > rectangle_bounds.top && mouse_position.y < rectangle_bounds.top + rectangle_bounds.height)
                        {
                            if (event.key.code == sf::Mouse::Left)
                            {
                                rectangles[i].select();
                            }
                            if (event.key.code == sf::Mouse::Right)
                            {
                                rectangles[i].unselect();
                            }
                        }
                    }
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        for (size_t i = 0; i < rectangles.size(); i++) 
        {
            window.draw(rectangles[i]);
            rectangles[i].animate(deltaTime);
        }

        // end the current frame
        window.display();
    }

    return 0;
}