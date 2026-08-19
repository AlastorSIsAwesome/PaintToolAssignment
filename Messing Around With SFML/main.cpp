/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [main.cpp]
Description : [Main file execution for Paint Tool]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/


#include <SFML/Graphics.hpp>

#include "cEllipseShape.h"
#include "cDrawButton.h"
#include "cShapeButton.h"
#include "ShapeMath.h"

//buttons
#include "cSizeButton.h"
#include "cColorButton.h"
#include "cFileInterface.h"

#include <vector>
#include <iostream>



int main()
{
    cFileInterface g_FileInterface;

    sf::RenderWindow window(sf::VideoMode({ 1600, 1020 }), "Paint Tool");

    //Default RectDrawTool
    sf::RectangleShape RectDrawTool({ 10.f, 10.f });
    RectDrawTool.setFillColor(sf::Color::White);

    // Default ElipseDrawTool
    cEllipseShape EllipseDrawTool({ 10.f, 10.f });
    EllipseDrawTool.setFillColor(sf::Color::White);

    // Default LineDrawTool
    sf::RectangleShape LineDrawTool({ 10.f, 10.f });
    LineDrawTool.setFillColor(sf::Color::White);
    sf::Vector2f LineDrawToolPosition; // need this or else line tool goes all funky and spins



    // Active color and active outline holders
    sf::Color ActiveColor = sf::Color::White;
    float ActiveOutline = 10.f;

    // gets size of window and sets drawable area to that
    sf::RenderTexture BackgroundTexture({ 1400, 1020 }); // RenderTexture is smaler than window to account for buttons
    sf::Sprite CanvasSprite(BackgroundTexture.getTexture());


    // is true when the player is pressing their mouse
    bool g_PressingMouse = 0;

    // Keeps track of the curren button that is active
    ButtonRole g_CurrentButton = DefaultButton;

    // Booleans needed for the resizing shapes
    bool g_StartResizing = false;
    bool g_CurrentlyResizing = false;
    bool g_FinishedResizing = false;



    /**************************************** BUTTON DECLEARATIONS *********************************************/
    std::vector<cButton> g_Buttons; // vector of all buttons
    int g_ButtonCount = 0;

    // Brush Button
    g_ButtonCount++;
    cButton UploadButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, FileLoadButton);
    sf::Texture UploadButtonTexture("textures/UploadImage.png");
    UploadButton.SetTexture(UploadButtonTexture);
    g_Buttons.push_back(UploadButton);

    // Brush Button
    g_ButtonCount++;
    cDrawButton BrushButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, PenButton);
    sf::Texture BrushButtonTexture("textures/PaintBrush.png");
    BrushButton.SetTexture(BrushButtonTexture);
    g_Buttons.push_back(BrushButton);

    // Square Button
    g_ButtonCount++;
    cShapeButton SquareButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, ShapeSquareButton);
    sf::Texture SquareButtonTexture("textures/Square.png");
    SquareButton.SetTexture(SquareButtonTexture);
    g_Buttons.push_back(SquareButton);

    // Ellipse Button
    g_ButtonCount++;
    cShapeButton EllipseButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, ShapeEllipseButton);
    sf::Texture EllipseButtonTexture("textures/Ellipse.png");
    EllipseButton.SetTexture(EllipseButtonTexture);
    g_Buttons.push_back(EllipseButton);

    // Line Button
    g_ButtonCount++;
    cShapeButton LineButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, ShapeLineButton);
    sf::Texture LineButtonTexture("textures/Line.png");
    LineButton.SetTexture(LineButtonTexture);
    g_Buttons.push_back(LineButton);

    // Outline size buttons
    // Small outline
    g_ButtonCount++;
    cSizeButton SmallOutlineButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, SmallSizeOutlineButton, 10);
    sf::Texture SmallOutlineButtonTexture("textures/SmallOutline.png");
    SmallOutlineButton.SetTexture(SmallOutlineButtonTexture);
    g_Buttons.push_back(SmallOutlineButton);

    // Medium-ish outline
    g_ButtonCount++;
    cSizeButton MediumIshOutlineButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, MediumIshSizeOutlineButton, 20);
    sf::Texture MediumIshButtonTexture("textures/Medium-ishOutline.png");
    MediumIshOutlineButton.SetTexture(MediumIshButtonTexture);
    g_Buttons.push_back(MediumIshOutlineButton);

    // Medium outline
    g_ButtonCount++;
    cSizeButton MediumOutlineButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, MediumOutSizelineButton, 30);
    sf::Texture MediumButtonTexture("textures/MediumOutline.png");
    MediumOutlineButton.SetTexture(MediumButtonTexture);
    g_Buttons.push_back(MediumOutlineButton);

    //Large outline
    g_ButtonCount++;
    cSizeButton LargeOutlineButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, LargeSizeOutlineButton, 50);
    sf::Texture LargeButtonTexture("textures/LargeOutline.png");
    LargeOutlineButton.SetTexture(LargeButtonTexture);
    g_Buttons.push_back(LargeOutlineButton);

    // Color Selection Buttons
    // no textures needed as the display color is the same as the return color

    // Red
    g_ButtonCount++;
    cColorButton RedButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::Red, RedColorButton);
    g_Buttons.push_back(RedButton);

    // Blue
    g_ButtonCount++;
    cColorButton BlueButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::Blue, BlueColorButton);
    g_Buttons.push_back(BlueButton);

    // Green
    g_ButtonCount++;
    cColorButton GreenButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::Green, GreenColorButton);
    g_Buttons.push_back(GreenButton);

    // White
    g_ButtonCount++;
    cColorButton WhiteButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, WhiteColorButton);
    g_Buttons.push_back(WhiteButton);

    // Black/Erase
    g_ButtonCount++;
    cColorButton BlackButton({ 1500.f, 55.f * g_ButtonCount }, sf::Color::White, BlackColorButton);
    // uses texture because it is hard to see black-on-black
    sf::Texture BlackButtonTexture("textures/Erase.png");
    BlackButton.SetTexture(BlackButtonTexture);
    g_Buttons.push_back(BlackButton);



    while (window.isOpen())
    {
          //std::cout << g_CurrentlyResizing << std::endl;
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

            // check if pressing a mouse button
            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonPressed>())
            {
                g_PressingMouse = true; 

                for (int i = 0; i < g_ButtonCount ; i++) //Checks every button to see if it was pressed
                {
                    if (g_Buttons[i].GetButtonObject().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) // compair bounds of the button with the current mouse position 
                    {
                        // sets g_CurrentButton to the button being pressed
                        g_CurrentButton = g_Buttons[i].GetButtonRole();
                    }
                }
            }

            if (const auto* keyPressed = event->getIf < sf::Event::MouseButtonReleased>())
            {
                // should be false/tue if user is not pressing any mosue buttons
                g_PressingMouse = false;
                g_FinishedResizing = true;
                g_CurrentlyResizing = false;
            }
        }





       



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
        case PenButton:
        {
            // Make sure size is normal
            RectDrawTool.setSize({ ActiveOutline, ActiveOutline });

            // set fill color and outline
            RectDrawTool.setFillColor(ActiveColor);
            RectDrawTool.setOutlineThickness(0.f);
            
            if (g_PressingMouse)
            {
                RectDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
                BackgroundTexture.draw(RectDrawTool);
            }


            break;
        }


        // shape buttons
  
        case ShapeSquareButton:
        {
            // make sure colour and outline thickness is correct
            RectDrawTool.setFillColor(ActiveColor);
            RectDrawTool.setOutlineThickness(ActiveOutline);


            if (g_StartResizing) // player presses mouse
            {
                if(g_PressingMouse)
                {
                    // create square with position of inital click positon
                    RectDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))); //creates rectangle with the origin of the mouse's current position
                    g_StartResizing = false;
                    g_CurrentlyResizing = true;
                }
            }

            if (g_CurrentlyResizing) 
            {
                // while player's mouse is held down, resize square
                ResizeRect(RectDrawTool, sf::Vector2f(sf::Mouse::getPosition(window)));
              
            }

            if (g_FinishedResizing)
            {
                // once player releaces mouse, add that rectangle to the rendertexture
                BackgroundTexture.draw(RectDrawTool);

                //resetting booleans
                g_FinishedResizing = false;
                g_StartResizing = true;
            }

            break;
        }

        case ShapeEllipseButton:
        {
            // make sure colour and outline thickness is correct
            EllipseDrawTool.setFillColor(ActiveColor);
            EllipseDrawTool.setOutlineThickness(ActiveOutline);

            if (g_StartResizing) // player presses mouse
            {
                if (g_PressingMouse)
                {
                    // create ellipse with position of inital click positon
                    EllipseDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))); //creates rectangle with the origin of the mouse's current position
                    g_StartResizing = false;
                    g_CurrentlyResizing = true;
                }
            }

            if (g_CurrentlyResizing)
            {
                // while player's mouse is held down, resize ellipse
                ResizeEllipse(EllipseDrawTool, sf::Vector2f(sf::Mouse::getPosition(window)));

            }

            if (g_FinishedResizing)
            {
                // once player releaces mouse, add that ellipse to the rendertexture
                BackgroundTexture.draw(EllipseDrawTool);

                //resetting booleans
                g_FinishedResizing = false;
                g_StartResizing = true;
            }



            break;
        }

        case ShapeLineButton:
        {
            // make sure colour and outline thickness is correct
            LineDrawTool.setFillColor(ActiveColor);
            LineDrawTool.setOutlineColor(ActiveColor);
            LineDrawTool.setOutlineThickness(ActiveOutline);

            if (g_StartResizing) // player presses mouse
            {
                if (g_PressingMouse)
                {
                    // create rect/line with position of inital click positon
                    LineDrawTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(window))); //creates rect/line with the origin of the mouse's current position
                    LineDrawToolPosition = LineDrawTool.getPosition();
                    g_StartResizing = false;
                    g_CurrentlyResizing = true;
                }
            }

            if (g_CurrentlyResizing)
            {
                // while player's mouse is held down, resize and rotate rect/line
                ResizeLine(LineDrawTool, sf::Vector2f(sf::Mouse::getPosition(window)), LineDrawToolPosition);
            }

            if (g_FinishedResizing)
            {
                // once player releaces mouse, add that rect/line to the rendertexture
                BackgroundTexture.draw(LineDrawTool);

                //resetting booleans
                g_FinishedResizing = false;
                g_StartResizing = true;
            }




            break;
        }


        // for outlines, set the shape tools' width and the Draw Tool's width
        case SmallSizeOutlineButton:
        {
            ActiveOutline = SmallOutlineButton.GetSize();

            break;
        }
        case MediumIshSizeOutlineButton:
        {
            ActiveOutline = MediumIshOutlineButton.GetSize();
            break;
        }
        case MediumOutSizelineButton:
        {
            ActiveOutline = MediumOutlineButton.GetSize();
            break;
        }
        case LargeSizeOutlineButton:
        {
            ActiveOutline = LargeOutlineButton.GetSize();
            break;
        }

        // Set Shape tool's color and draw tool's color
        case RedColorButton:
        {
            ActiveColor = sf::Color::Red;
            break;
        }

        case BlueColorButton:
        {
            ActiveColor = sf::Color::Blue;
            break;
        }

        case GreenColorButton:
        {
            ActiveColor = sf::Color::Green;
            break;
        }

        case WhiteColorButton:
        {
            ActiveColor = sf::Color::White;
            break;
        }

        case BlackColorButton:
        {
            ActiveColor = sf::Color::Black;
            break;
        }

        case DefaultButton: // follow through because the default button does nothing
        default:
            break;
        }









       //display to consol

        window.clear();
        for (int i = 0; i < g_ButtonCount;  i++) // draw every button
        {
            window.draw(g_Buttons[i].GetButtonObject());
        }

        BackgroundTexture.display();

        window.draw(RectDrawTool);
        window.draw(EllipseDrawTool);
        window.draw(LineDrawTool);

        window.draw(CanvasSprite);
        window.display();
    }
}




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