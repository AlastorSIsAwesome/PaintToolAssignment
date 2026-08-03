#include <SFML/Graphics.hpp>

#include "ShapeMath.h"


int main()
{


    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");
    sf::RectangleShape Player({ 100.f, 100.f });
    
    // Texture Setting
    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("textures/alastorsphere.png");
    Player.setTexture(&PlayerTexture);

    // gets size of window and sets drawable area to that
    sf::RenderTexture BackgroundTexture{ window.getSize() };
    sf::Sprite CanvasSprite(BackgroundTexture.getTexture());

    bool CurrentlyDrawing = false;
    bool CurrentlyResizing = false;

   // pointer array to keep track of shapes
   // sf::Shape* pShapeArray = new sf::Shape*[0];

   // sf::Shape test[1] = ;

    sf::Vector2f IncreaseScale(1.f, 1.f);


    sf::RenderTexture; 

    int numOfRects = 0;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) // checks if the window is open
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            // check if window is resized
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the veiw to the new sive of the window
                sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }



            // check if drawing/resizing
            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonPressed>())
            {
                CurrentlyResizing = true;
            }

            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonReleased>())
            {
                CurrentlyResizing = false;
            }
           
            // check if trying to exit
            if (const auto* keypressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keypressed->scancode == sf::Keyboard::Scan::Escape)
                {
                    printf("You are trying to exit");
                }
            }


        }


        if (CurrentlyResizing)
        {
            numOfRects++;
            sf::RectangleShape Testing;
            ResizeRect(Player, (sf::Vector2f(sf::Mouse::getPosition(window))));
            BackgroundTexture.draw(Player);
        }

        if (CurrentlyDrawing)
        {
            Player.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
            BackgroundTexture.draw(Player);
        }



        BackgroundTexture.display(); // actialy display to consol

        window.draw(CanvasSprite);

        window.clear();
        window.draw(Player);
        window.display();
    }
}


/*
            if (const auto* buttonPressed = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (buttonPressed->button == sf::Mouse::Button::Left)
                {
                    CurrentlyDrawing = true;
                }
            }




            // create and resize shape

            while (CurrentlyDrawing)
            {
                // this may create thousands of shapes so be careful

                //current mouse position
                sf::Vector2i mousePosition = sf::Mouse::getPosition();
                sf::RectangleShape(ResizeRect({ mousePosition.x - 0.f, mousePosition.y - 0.f })); //double check this later



*/