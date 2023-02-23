#include <iostream>

class CCoords{
public:
    int x;
    int y;

    CCoords(){
      x=0;y=0;  
    }   

    friend CCoords operator+(const CCoords& c, const int& b);
    friend CCoords operator+(const int& b, const CCoords& c);

    friend std::ostream& operator<<(std::ostream& os, const CCoords& c);

};

CCoords operator+(const CCoords& c, const int& b){
        CCoords result;
        result.x = c.x + b;
        result.y = c.y + b;
        return result;
    }

CCoords operator+( const int& b,const CCoords& c){
        CCoords result;
        result.x = c.x + b;
        result.y = c.y + b;
        return result;
    }

 std::ostream& operator<<(std::ostream& os, const CCoords& c){
    os<<c.x<<" "<<c.y<<std::endl;
    return os;
 };

int main(){
    CCoords c;
    c.x=0;c.y=0;
    auto cc=2+c;
    std::cout<<2+c;
    std::cout<<c+2;
}
