/*
** EPITECH PROJECT, 2020
** 108trigo
** File description:
** 108trigo
*/

//libC
#include <iostream>
#include <iomanip>

using namespace std;

int get_int_lenght(int nb)
{
    int length = 0;

    if (!nb)
        return 1;
    while (nb != 0) {
        nb /= 10;
        length++;
    }
    return length;
}

void display_number_with_space(float nb, int space)
{
    nb = ((int)(nb * 100) == 0) ? 0 : nb;
    int length = get_int_lenght(nb) + 3;
    int precision = (int)((nb - (int)nb) * 100);

    if (nb < 0)
        length++;
    cout << fixed << setprecision(2) << nb;
    for (int i = 0; i < space - length; i++)
        cout << " ";
}