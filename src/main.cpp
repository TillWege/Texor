#include "raylib.h"
#include "string"
#include "vector"
#include "iostream"
#include "sstream"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "Texor");

    std::vector<std::string> content = {""};
    int currentLine = 0;
    int currentPos = 0;
    const int lineHeight = 20;



    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        int i = 0;
        for(; i<content.size(); i++)
        {
            DrawText(content[i].c_str(), 0, 20*i, 20, LIGHTGRAY);
        }

        int bottomLine = GetScreenHeight() - 20;
        DrawLine(0, bottomLine, GetScreenWidth(), bottomLine, LIGHTGRAY);

        std::stringstream ss;
        ss << "Currently holding "<<  content.size() << " / " << content.capacity() << " lines";

        DrawText(ss.str().c_str(), 50, bottomLine, 20, RED);

        EndDrawing();

        if(IsKeyReleased(KEY_ENTER))
        {
            content.emplace_back("");
            currentLine++;
        }

        if(IsKeyReleased(KEY_BACKSPACE))
        {
            if(!content[currentLine].empty())
            {
                content[currentLine].pop_back();
            }
        }

        if(IsKeyReleased(KEY_UP))
        {
            if(currentLine != 0)
            {
                currentLine -= 1;
            }
        }

        if(IsKeyReleased(KEY_DOWN))
        {
            if(currentLine != (content.size() - 1))
            {
                currentLine += 1;
            }
        }

        bool running = true;
        while(running)
        {
            int val = GetCharPressed();
            if(val == 0)
            {
                running = false;
            }
            else
            {
                auto line = &content[currentLine];
                *line += char(val);
                std::cout << *line << std::endl;
            }
        }
    }

    CloseWindow();

    return 0;
}