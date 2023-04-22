all:
	g++ main.cpp game.cpp lib.cpp birds.cpp land.cpp Column.cpp sound.cpp -IC:\Users\admin\OneDrive\Desktop\SDL2-2.26.3\x86_64-w64-mingw32\include\SDL2 -LC:\Users\admin\OneDrive\Desktop\SDL2-2.26.3\x86_64-w64-mingw32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o FlappyBird

