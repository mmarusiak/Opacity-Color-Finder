//
// Created by mmarusiak on 31.12.22.
//

// https://www.geeksforgeeks.org/convert-the-given-rgb-color-code-to-hex-color-code/
#include <string>
#include "rgbconventer.h"

namespace rgbconventer {
    std::string decToHexa(int n) {
        // char array to store hexadecimal number
        char hexaDeciNum[2];

        // counter for hexadecimal number array
        int i = 0;
        while (n != 0) {

            // temporary variable to store remainder
            int temp = 0;

            // storing remainder in temp variable.
            temp = n % 16;

            // check if temp < 10
            if (temp < 10) {
                hexaDeciNum[i] = temp + 48;
                i++;
            } else {
                hexaDeciNum[i] = temp + 55;
                i++;
            }

            n = n / 16;
        }

        std::string hexCode = "";
        if (i == 2) {
            hexCode.push_back(hexaDeciNum[0]);
            hexCode.push_back(hexaDeciNum[1]);
        } else if (i == 1) {
            hexCode = "0";
            hexCode.push_back(hexaDeciNum[0]);
        } else if (i == 0)
            hexCode = "00";

        // Return the equivalent
        // hexadecimal color code
        return hexCode;
    }

// Function to convert the
// RGB code to Hex color code
    std::string convertRGBtoHex(int R, int G, int B) {
        if ((R >= 0 && R <= 255)
            && (G >= 0 && G <= 255)
            && (B >= 0 && B <= 255)) {

            std::string hexCode = "#";
            hexCode += decToHexa(R);
            hexCode += decToHexa(G);
            hexCode += decToHexa(B);

            return hexCode;
        }

            // The hex color code doesn't exist
        else
            return "-1";
    }
}