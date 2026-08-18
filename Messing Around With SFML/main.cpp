/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [main.cpp]
Description : [One line description of what is the file is for]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/



#include <SFML/Graphics.hpp>

#include "ShapeMath.h"

#include "cButton.h"

#include "cFileInterface.h"

#include <vector>


enum ResizeStates
{
    SetOrigin,
    ActivelyResizing,
    FinishedResizing,
};



int main()
{

    cFileInterface g_FileInterface;

    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Paint Tool");

    sf::RectangleShape RectDrawTool({ 20.f, 20.f });
    RectDrawTool.setFillColor(sf::Color::White);

    // gets size of window and sets drawable area to that
    sf::RenderTexture BackgroundTexture({1280, 620}); // (window.getSize().x, window.getSize().y - 100.f)
    sf::Sprite CanvasSprite(BackgroundTexture.getTexture());


    bool g_PressingMouse = 0;

    
    ButtonRole g_CurrentButton = DefaultButton;
    bool g_StartResizing = false;
    bool g_CurrentlyResizing = false;
    bool g_FinishedResizing = false;

    ResizeStates g_ResizeState = SetOrigin;


    sf::Vector2f IncreaseScale(1.f, 1.f);


    int g_ButtonCount = 9;

    std::vector<cButton> g_Buttons; // vector wiht all vertexes

    for (int i = 0; i < g_ButtonCount; i++)
    {
        cButton NewButton({ 1200.f , 55.f * i }, sf::Color::Blue, static_cast<ButtonRole>(i+1)); // creates one of each button type excluding default
        g_Buttons.push_back(NewButton);
    }


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
               // BackgroundTexture.resize(window.getSize());
            }



            // check if pressing a mouse button
            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonPressed>())
            {
                g_PressingMouse = true;

                for (int i = 0; i < g_ButtonCount ; i++) //Checks every button to see if it was pressed
                {
                    if (g_Buttons[i].m_ButtonShape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) // compair bounds of the button with the current mouse position 
                    {
                        g_CurrentButton = g_Buttons[i].GetButtonRole();
                        g_Buttons[i].Update();

                        if (i == 7)
                        {
                            g_StartResizing = true;
                        }
                        else
                        {
                            g_StartResizing = false;
                        }
                    }
                }
            }

            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonReleased>())
            {
                g_PressingMouse = false;
                g_FinishedResizing = true;
                g_CurrentlyResizing = false;
            }
           



        }



        //

        //


       



        // switch case to check which button is active right now
        switch (g_CurrentButton)
        {
            //file buttons
        case FileSaveButton:
        {
            g_CurrentButton = DefaultButton;
            break;
        }
        case FileLoadButton:
        {
            g_FileInterface.LoadFile(&BackgroundTexture);
            //Player.setTexture(&BackgroundTexture.getTexture()); // fix this???

            g_CurrentButton = DefaultButton;
            break;
        }

        // pen buttons
        case PenCircleButton:
        {
            break;
        }
        case PenSquareButton:
        {
            if (g_PressingMouse)
            {
                RectDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                BackgroundTexture.draw(RectDrawTool);
            }


            break;
        }
        case PenTriangleButton:
        {
            break;
        }

        // shape buttons
        case ShapeCircleButton:
        {
            break;
        }
        case ShapeSquareButton:
        {
            // TODO: RESIZE TOOL
            // RIGHT NOW IM TOO STRESSED TO DEAL WITH IT ;-;


            // player presses down
            // create square with origin of inital click positon
            // while player's mouse is held down, resize square
            // once player releaces mouse, save that rectangle



            if (g_StartResizing)
            {
                RectDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))); //creates rectangle with the origin of the mouse's current position
                g_StartResizing = false;
                g_CurrentlyResizing = true;
            }

            if (g_CurrentlyResizing)
            {
                ResizeRect(RectDrawTool, sf::Vector2f(sf::Mouse::getPosition(window)));
            }

            if (g_FinishedResizing)
            {
                BackgroundTexture.draw(RectDrawTool);
                g_FinishedResizing = false;
            }















   


            


    

            break;
        }
        case ShapeTriangleButton:
        {
            break;
        }
        case ShapeLineButton:
        {
            break;
        }

        case DefaultButton: // follow through because the default button does nothing
        default:
            break;
        }









       // actialy display to consol

        window.clear();
        
        for (int i = 0; i < g_ButtonCount;  i++) // draw every button
        {
            window.draw(g_Buttons[i].m_ButtonShape);
        }

        BackgroundTexture.display();

        window.draw(CanvasSprite);
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







                            // check if trying to exit
            if (const auto* keypressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keypressed->scancode == sf::Keyboard::Scan::Escape)
                {
                    printf("You are trying to exit");
                }
            }

*/


/*

TODO:



Mouse-based drawing
• The tool must include the ability to draw shapes with the mouse. These shapes are
listed under Required Shapes, below.
• The mouse must allow for click-to-hold; shapes may not be ‘placed’ onto the
canvas.
• Shapes must be able to be resized while the user holds down the mouse button.
Scaling these shapes from the top left is expected.
• Shapes must persist on the canvas after they have been drawn.




the following shapes are required:
• Boxes
• Ellipses
• Lines
• Lines must be able to be adjusted in thickness for this feature to be fully
implemented.




A simple persistent menu must be always accessible, to allow the user to change the
current tool. This menu should allow the user to:
• Change the current tool (i.e., change from box drawing to ellipse drawing)
• Change the fill colour of the shape to any of the basic implemented SFML colours,
under sf::Color.
• Change the width of the selected tool.
• For the Line object, this applies to the line itself. For other shapes – e.g., Box
or Ellipse – this applies to the outline of the shape.








Addons:



Saving and loading files
• Images must be able to be saved out to the file system. This may make use of a file dialog or
save directly to the disk.
• Saved images must save out correctly (with correct extension attached) to minimise any
issues the user may have.
• Image loading must make use of a file dialog. This system should allow the user to ‘open’ a
file, and have it be displayed proportionally in the window. The image must not stretch or be
manipulated in any way when opening the file in the paint tool.



The polygon tool is a system for drawing n-gon shapes within the paint tool. It must allow the
user to draw custom shapes. Multiple approaches can be taken to this.
• The tool may need to make use of multiple inputs (i.e., click with the left mouse button to
create points, right-click to connect them); this solution is appropriate. Other approaches
may be taken, if a completed polygon is created.


The stamp tool should allow the user to load a file through the image dialog, then ‘stamp’ it
onto the canvas.
• This image may be resized to fit the canvas, but it should not be modified (i.e. cropped, or
disproportionately scaled)
• This tool should allow the user to place multiple images around the window


The user should be able to change the
colour of the tools, using a colour dialog
(see example image) This image should
include a similar gradient, to allow users
to click-to-select their colour from a wide
range.
•
• This tool should apply to all other tools,
i.e., circle / square / line etc.
• This tool does not need to apply to the
stamp tool, or file save / loading.





*/