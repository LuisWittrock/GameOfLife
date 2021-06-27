#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;


class Frame
{
    public:
        RenderWindow window;
        Event event;
        int WINDOW_HEIGHT = 500;
        int WINDOW_WIDTH = 500;

        Frame()
        {
            window.setFramerateLimit(10);
        }
};

class Space : Frame
{
    public:
        bool field[50][50];
        bool tmp_field[50][50];
        RectangleShape alive;
        RectangleShape dead;

        Space()
        {
            alive.setFillColor(sf::Color(255,255,255));
            alive.setSize(Vector2f(10,10));
            dead.setFillColor(sf::Color(0,0,0));
            dead.setSize(Vector2f(10,10));

            for(int i = 0; i<50; i++)
            {
                for(int j = 0; j<50; j++)
                {
                    field[i][j] = false;
                    tmp_field[i][j] = true;
                }
            }
        }

        void randomize()
        {
            srand(time(nullptr));
            
            for(int i = 0; i<50; i++)
            {
                for(int j = 0; j<50; j++)
                {
                    int x = rand()%2;
                    field[i][j] = x;
                }
                
            }
        }

        int countNeighbours(int y, int x)
        {
            int count = 0;

            for(int i = -1; i<=1; i++)
            {
                for(int j = -1; j<=1; j++)
                {
                    if(j == 0 && i == 0 || x+j < 0 || y+i < 0 || x+j >= 50 || y+i >= 50) continue;
                    if(field[y+i][x+j] == true) count++;
                }
            }
            return count;
        }

        void updateField()
        {
            cout << "updateField" << endl;
            for(int y = 0; y<50; y++)
            {
                for(int x = 0; x<50; x++)
                {
                    int neighbours = countNeighbours(y,x);
                    if(x == 0 && y == 0) cout << neighbours << endl;
                    if(field[y][x] == true && (neighbours < 2 || neighbours > 3))
                    {
                        tmp_field[y][x] = false;
                    }
                    else if(field[y][x] == true && (neighbours == 2 || neighbours == 3))
                    {
                        tmp_field[y][x] = true;
                    }
                    else if(field[y][x] == false && neighbours == 3)
                    {
                        tmp_field[y][x] = true;
                    }
                    else
                    {
                        tmp_field[y][x] = false;
                    }
                }
            }
            for(int i = 0; i<50; i++)
            {
                for(int j = 0; j<50; j++)
                {
                    field[i][j] = tmp_field[i][j];
                }
            }           
        }

        RectangleShape getAlive()
        {
            return alive;
        }
        RectangleShape getDead()
        {
            return dead;
        }
};

class Panel : Frame
{
    public:

        Space space;

        void redraw()
        {
            //j,jj are the coordinates for the acording space in the actual window
            //i, ii are coordinates for the array which saves the state of each cell 
            for(int i = 0, j=0; i<50; i++, j+=10) 
            {
                for(int ii = 0, jj=0; ii<50; ii++, jj+=10)
                {
                    if(space.field[i][ii] == true)
                    {
                        space.alive.setPosition(Vector2f(j,jj));
                        window.draw(space.getAlive());
                    }
                    else
                    {
                        space.dead.setPosition(Vector2f(j,jj));
                        window.draw(space.getDead());
                    }
                }
            }
        }
        void update()
        {
            space.updateField();
        }

        void drawWindow()
        {
            window.create(VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "GAME OF LIFE");
            space.randomize();
            while(window.isOpen())
            {
                sleep(seconds(0.1));
                window.clear();
                redraw();
                window.display();
                update();

                while(window.pollEvent(Frame::Frame::event))
                {
                    if(event.type == Event::Closed) window.close();
                }
            }
        }
    
};

int main()
{
    Frame frame;
    Panel panel;
    panel.drawWindow();
}
