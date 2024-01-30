#include <windows.h>
#include <cmath>
#include <iostream>

const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;

bool keepRunning = true;

void signalHandler(int signal) {
    keepRunning = false;
}

void moveMouseInCircle(int centerX, int centerY, int radius, double speed) {
    double angle = 0;

    while (keepRunning) {
        int x = centerX + static_cast<int>(radius * cos(angle));
        int y = centerY + static_cast<int>(radius * sin(angle));

        SetCursorPos(x, y);

        angle += speed;

        Sleep(10);
    }
}

int main() {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    int radius = 400;

    double speed = 0.03;

    std::cout << "Control + C to stop . . .\n";
    moveMouseInCircle(centerX, centerY, radius, speed);
    return 0;
}
