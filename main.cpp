#include "raylib.h"
#include "string"
#include "vector"
#include "format"
#include "iostream"

int main()
{
    InitWindow(800, 450, "Texor");

    std::vector<std::string> content;
    content.emplace_back("");
    int currentLine = 0;



    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        int i = 0;
        for(; i<content.size(); i++)
        {
            DrawText(content[i].c_str(), 0, 20*i, 20, LIGHTGRAY);
        }
        DrawText(std::format("Currently holding {} / {} lines", content.size(), content.capacity()).c_str(), 50, 20*i, 20, RED);

        EndDrawing();

        if(IsKeyReleased(KEY_ENTER))
        {
            content.emplace_back("");
            currentLine++;
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