@echo off
g++ -g -c src/main.cpp -o main.o -I libs/glfw/include -I libs/glad/include -I libs/glm
g++ -g -c libs/glad/src/glad.c -o glad.o -I libs/glad/include
g++ -g main.o glad.o -o game.exe -L libs/glfw/lib-mingw-w64 -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32