#include <iostream>
#include <cstring>
#include <cmath>
#include <chrono>
#include <thread>
#include <limits>

using namespace std;

float A, B, C;
const int width = 84, height = 24, cubeSize = 10, vSet = 57, hSet = 13;
char backGround[height * width];
float zBuffer;
float buffer[height * width];

float roll(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) 
        - k * cos(A) * sin(B) * cos(C) 
        + j * cos(A) * sin(C) 
        + k * sin(A) * sin(C) 
        + i * cos(B) * cos(C);
}

float pitch(int i, int j, int k) {
    return j * cos(A) * cos(C) 
        + k * sin(A) * cos(C) 
        - j * sin(A) * sin(B) * sin(C) 
        + k * cos(A) * sin(B) * sin(C) 
        - i * cos(B) * sin(C);
}

float yaw(int i, int j, int k) {
    return k * cos(A) * cos(B) 
        - j * sin(A) * cos(B) 
        + i * sin(B);
}

int cubePos(int x, int y, int z) {
    float X, Y, Z;
    X = roll(x, y, z);
    Y = pitch(x, y, z);
    Z = yaw(x, y, z) + 1000;

    X = (int)X + vSet;
    Y = (int)Y / 2 + hSet;
    zBuffer = 1 / Z;
    return X + Y * width;
}

void insertSymbol(int index, char symbol) {
    if (index >= 0 && index < height * width) {
        if (zBuffer > buffer[index]) {
            buffer[index] = zBuffer;
            backGround[index] = symbol;
        }
    }
}

int main() {
    int countEndLine = 0;
    float velocity = 0.6;
    int index;

    while (1) {
        printf("\x1b[2J\x1b[H");
        memset(backGround, ' ', sizeof(backGround));

        for (int i = 0; i < height * width; ++i) {
            buffer[i] = -std::numeric_limits<float>::max();
        }

        for (float iX = -cubeSize; iX <= cubeSize; iX += velocity) {
            for (float iY = -cubeSize; iY <= cubeSize; iY += velocity) {
                index = cubePos(iX, iY, -cubeSize);
                insertSymbol(index, '#');
                index = cubePos(-cubeSize, iY, iX);
                insertSymbol(index, '@');
                index = cubePos(cubeSize, iY, iX);
                insertSymbol(index, '%');
                index = cubePos(-iX, iY, cubeSize);
                insertSymbol(index, '*');
                index = cubePos(iX, -cubeSize, iY);
                insertSymbol(index, '+');
                index = cubePos(iX, cubeSize, iY);
                insertSymbol(index, '-');
            }
        }

        string output;
        output.reserve(sizeof(backGround) + height);
        for (int i = 0; i < sizeof(backGround); i++) {
            output += backGround[i];
            countEndLine++;
            if (countEndLine == width) {
                output += '\n';
                countEndLine = 0;
            }
        }

        cout << output;
        A += 0.06;
        B += 0.02;
        C += 0.08;
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
    }
    return 0;
}
