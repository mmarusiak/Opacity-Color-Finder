# Opacity Color Finder

Just quick project for C++, also my first project in C++ for long time.

## What is it and how it works?

So, when I was using creating UI in Unity I wanted to find color with some declared opacity which after blend with my background color will be color that I expect. That's why I made this tool.

<picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/20907620/210140897-7b093d00-6b95-4464-b4ba-cb014dcee548.png">
  <source media="(prefers-color-scheme: light)" srcset="https://user-images.githubusercontent.com/20907620/210140898-86174a7c-5bfe-4d6d-bc65-a59a952192a4.png">
  <img alt="Shows an illustrated sun in light mode and a moon with stars in dark mode." src="https://user-images.githubusercontent.com/25423296/163456779-a8556205-d0a5-45e2-ac17-42d089e3c3f8.png">
</picture>

So from example above:  
If you have ``background color`` (here blue *(left)* color), ``opacity of second color`` (opacity of green *(right)* color) and ``blended color`` (middle, blended green and blue color, here gray-blue-ish like) **``you will get output color``** (RGBA and HEX) value.

Example input:
- Main color/background color: `rgb(1, 4, 9)`
- Opacity of target color: `70`
- Blended color: `rgb(13, 17, 23)`

Expected output:
> Hex value of new color with opacity 70: #0C0161  
RGBA value of the new color is: (12, 16, 22, 70)

App is simple and made by beginner in C++, so feel free to contribute and improve it by yourself.

App works in console.

## Installation

- Clone this repo from your project folder;
- Be sure that you're using ``C++17`` *(should work on any other version, but didn't test that)*;
- Compile or build ``main.cpp``;

## Usage

Just follow instructions displayed in console.
