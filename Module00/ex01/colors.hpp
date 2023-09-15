#ifndef COLORS_HPP
# define COLORS_HPP

/* For more information on colors visit:
 * https://chrisyeh96.github.io/2020/03/28/terminal-colors.html */

/* General*/
#define RESET "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[1;1H";

/* Effects */
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define U_LINE "\033[4m"
#define BLINK "\033[5m"

/* foreground colors */
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

/* background colors */
#define B_BLACK "\033[40m"
#define B_RED "\033[41m"
#define B_GREEN "\033[42m"
#define B_YELLOW "\033[43m"
#define B_BLUE "\033[44m"
#define B_MAGENTA "\033[45m"
#define B_CYAN "\033[46m"
#define B_WHITE "\033[47m"

#endif
