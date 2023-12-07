#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Convertir
{
public:
    char operator()(char c) const
    {
        return toupper(c);
    }
};

int main()
{
    string chaine("Salut les developpeurs !");
    transform(chaine.begin(), chaine.end(), chaine.begin(), Convertir());
    cout << chaine << endl;
    return 0;
}