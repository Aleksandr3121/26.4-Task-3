#include <iostream>
#include <iomanip>

using namespace std;

struct Coordinate {
    int x = 0, y = 0;
};

class Window {
public:
    void Move(const Coordinate& move_vector) {
        top_lef_corner.x += move_vector.x;
        top_lef_corner.y += move_vector.y;
        if (top_lef_corner.x > 79)top_lef_corner.x = 79;
        else if (top_lef_corner.x < 0)top_lef_corner.x = 0;
        if (top_lef_corner.y > 49)top_lef_corner.y = 49;
        else if (top_lef_corner.y < 0)top_lef_corner.y = 0;
        cout << "New coordinate of the window: " << top_lef_corner.x << ' ' << top_lef_corner.y << endl;
    }

    void Resize(int h, int w) {
        if (h < 0 || w < 0)cerr << "Invalid arguments" << endl;
        else {
            height = h;
            width = w;
            cout << "New window sizes: " << height << " X " << width << endl;
        }
    }

    void Display() const {
        for (size_t h = 0; h < top_lef_corner.y; ++h) {
            for (size_t w = 0; w < 80; ++w) {
                cout << 0;
            }
            cout << endl;
        }
        cout << setfill('0');
        for (size_t h = top_lef_corner.y; h < top_lef_corner.y+height; ++h) {
            cout<<setw(1+top_lef_corner.x);
            for (size_t w = 0; w < width; ++w) {
                cout<<1;
            }
            for (size_t w = width + top_lef_corner.x; w < 80; ++w) {
                cout << 0;
            }
            cout << endl;
        }
        for(size_t h=top_lef_corner.y+height; h<50; ++h){
            for (size_t w = 0; w < 80; ++w) {
                cout << 0;
            }
            cout << endl;
        }
    }

private:

    int height;
    int width;
    Coordinate top_lef_corner;
};

int main() {
    Window window;
    string command;
    Coordinate move_vector;
    int h = 0, w = 0;
    while (cin >> command && command != "close") {
        if (command == "move") {
            cin >> move_vector.x >> move_vector.y;
            window.Move(move_vector);
        } else if (command == "resize") {
            cin >> h >> w;
            window.Resize(h, w);
        } else if (command == "display") {
            window.Display();
        } else cout << "Unknown command" << endl;
    }
    return 0;
}
