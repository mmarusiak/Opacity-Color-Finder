// https://stackoverflow.com/a/17469726/13786856

#ifndef OPACITY_COLOR_FINDER_COLORMOD_H
#define OPACITY_COLOR_FINDER_COLORMOD_H


#include <ostream>
#include <ostream>
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        FG_LIGHT_GRAY = 37
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}
#endif //OPACITY_COLOR_FINDER_COLORMOD_H
