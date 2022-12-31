#include <iostream>
#include "colormod.h"
#include "rgbconventer.h"

int mainColor[4];
int targetOpacity;
int targetColor[3];

// colors
Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier gray(Color::FG_LIGHT_GRAY);
Color::Modifier def(Color::FG_DEFAULT);

int readNumber(char* infoMessage, char* typeValue, Color::Modifier color, int min, int max)
{
    int x=0;
    while(true)
    {
        std::cout << "Provide " << color << typeValue << def << infoMessage << std::endl;
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
    mainColor[0] = readNumber(" value for your base/background color:", "Red", red, 0, 255);
    mainColor[1] = readNumber(" value for your base/background color:", "Blue", blue, 0, 255);
    mainColor[2] = readNumber(" value for your base/background color:", "Green", green, 0, 255);
    mainColor[3] = readNumber(" value for your base/background color:", "Alpha", gray,  0, 100);
}

void load_target_color(){
    targetColor[0] = readNumber(" value for your blended color:", "Red", red, 0, 255);
    targetColor[1] = readNumber(" value for your blended color:", "Blue", blue, 0, 255);
    targetColor[2] = readNumber(" value for your blended color:", "Green", green, 0, 255);
    targetOpacity = readNumber(" value for your second color:", "Alpha", gray,  0, 100);
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

    if(*(color) >= 0 && *(color + 1) >= 0 && *(color + 2) >= 0) {
        int color_val[4];
        for (int i = 0; i < 4; i++) {
            color_val[i] = *(color + i);
        }

        std::cout << "Hex value of new color with opacity " << targetOpacity << ": " << rgbconventer::convertRGBtoHex(color_val[0], color_val[1], color_val[2]) << std::endl;
        std::cout << red << "R" << green << "G" << blue << "B" << gray << "A" << def << " value of the new color is: (" << red << color_val[0] << def << ", " << green << color_val[1] << def
        << ", " << blue << color_val[2] << def << ", " << gray << targetOpacity << def << ")" << std::endl;
    }else{
        std::cout << "Output color wasn't found, probably doesn't exist. You may provide some different combination of colors.";
        program();
    }
}

int main() {
    program();
    return 0;
}


