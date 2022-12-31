#include <iostream>
#include <sstream>
#include "rgbconventer.h"

int mainColor[4];
int targetOpacity;
int targetColor[3];

int readNumber(char* infoMessage, int min, int max)
{
    int x=0;
    while(true)
    {
        std::cout << infoMessage << std::endl;
        std::cin >> x;
        if(!std::cin.fail() && x >= min && x <= max){
            break;
        }
        else{
            std::cout << "Bad entry. Enter a NUMBER: " << std::endl;
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
    }

    return x;
}

void load_main_color(){
    mainColor[0] = readNumber("Provide R value for your base/background color:", 0, 255);
    mainColor[1] = readNumber("Provide G value for your base/background color:", 0, 255);
    mainColor[2] = readNumber("Provide B value for your base/background color:", 0, 255);
    mainColor[3] = readNumber("Provide A value for your base/background color:", 0, 100);
}

void load_target_color(){
    targetColor[0] = readNumber("Provide R value for your target, overlayed color:", 0, 255);
    targetColor[1] = readNumber("Provide G value for your target, overlayed color:", 0, 255);
    targetColor[2] = readNumber("Provide B value for your target, overlayed color:", 0, 255);
    targetOpacity = readNumber("Provide opacity of output color:", 1, 100);
}

int* output_color(){
    static int result[4];
    result[3] = targetOpacity;

    for(int i = 0; i < 3; i ++){
        result[i] = (targetColor[i]*(mainColor[3]+targetOpacity-mainColor[3]*targetOpacity)-mainColor[3]*mainColor[i])/(targetOpacity-mainColor[3]*targetOpacity);
    }

    return result;
}

void program(){
    load_main_color();
    load_target_color();

    int *color = output_color();
    char *outputMessage;
    std::string rgb = "(";

    if(*(color) >= 0 && *(color + 1) >= 0 && *(color + 2) >= 0) {
        int color_val[4];
        for (int i = 0; i < 4; i++) {
            color_val[i] = *(color + i);
            rgb += std::to_string(*(color + i));
            if(i < 3)
                rgb += "; ";
        }
        rgb += ")";
        std::cout << "Hex value of new color with opacity " << targetOpacity << ": " << rgbconventer::convertRGBtoHex(color_val[0], color_val[1], color_val[2]) << std::endl;
        std::cout << "RGBA value of the new color is: " << rgb << std::endl;
    }else{
        std::cout << "Output color wasn't found, probably doesn't exist. You may provide some different combination of colors.";
        program();
    }
}

int main() {
    program();
    return 0;
}


