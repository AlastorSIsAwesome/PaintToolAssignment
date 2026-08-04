#include <SFML/Graphics.hpp>

#include "ShapeMath.h"


int main()
{


    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "ALASTOR SPHERE RETURNS");
    sf::RectangleShape Player({ 10.f, 10.f });
    
    // Texture Setting
    sf::Texture PlayerTexture;
    PlayerTexture.loadFromFile("textures/alastorsphere.png");
    Player.setTexture(&PlayerTexture);

    // gets size of window and sets drawable area to that
    sf::RenderTexture BackgroundTexture{ window.getSize() };
    sf::Sprite CanvasSprite(BackgroundTexture.getTexture());

    bool CurrentlyDrawing = false;
    bool CurrentlyResizing = false;
    bool BeginResizing = false;
    bool FinishedResizing = false;

   // pointer array to keep track of shapes
   // sf::Shape* pShapeArray = new sf::Shape*[0];

   // sf::Shape test[1] = ;

    sf::Vector2f IncreaseScale(1.f, 1.f);


    int numOfRects = 0;

    numOfRects++;
    sf::RectangleShape Testing(IncreaseScale);
    Testing.setFillColor(sf::Color::White);

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
                // resize rendertexture
            }



            // check if drawing/resizing
            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonPressed>())
            {
                BeginResizing = true;
            }

            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonReleased>())
            {
                FinishedResizing = true;
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



        //
        // player presses down
        // create square with origin of inital click positon
        // while player's mouse is held down, resize square
        // once player releaces mouse, save that rectangle
        //


        if (BeginResizing)
        {

            Player.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));

            BeginResizing = false;
            CurrentlyResizing = true;
        }


        if (CurrentlyResizing)
        {
            
            ResizeRect(Player, (sf::Vector2f(sf::Mouse::getPosition(window))));
            //BackgroundTexture.draw(Player);
        }

        if (FinishedResizing)
        {
            BackgroundTexture.draw(Player);
            FinishedResizing = false;
        }

        if (CurrentlyDrawing)
        {
            Player.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
            BackgroundTexture.draw(Player);
        }



       // actialy display to consol

        window.clear();
        
        BackgroundTexture.display();
        window.draw(CanvasSprite);
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