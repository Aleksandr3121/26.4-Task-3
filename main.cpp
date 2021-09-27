#include <iostream>
#include <iomanip>

using namespace std;

struct Coordinate {
    int x = 0, y = 0;
};

const int HeightDisplay = 50;
const int WidthDisplay = 80;

class Window {
public:
    void Move(const Coordinate& move_vector) {
        top_lef_corner.x += move_vector.x;
        top_lef_corner.y += move_vector.y;
        if (top_lef_corner.x > WidthDisplay)top_lef_corner.x = WidthDisplay-1;
        else if (top_lef_corner.x < 0)top_lef_corner.x = 0;
        if (top_lef_corner.y > HeightDisplay)top_lef_corner.y = HeightDisplay-1;
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

    const Coordinate& GetCoordinate() const {
        return top_lef_corner;
    }

    const int& GetHeight() const {
        return height;
    }

    const int& GetWidth() const {
        return width;
    }

private:
    int height;
    int width;
    Coordinate top_lef_corner;
};

class Display {
public:
    Display() : height(HeightDisplay), width(WidthDisplay) {}

    void PrintWindow(const Window& window) const {
        for (size_t h = 0; h < window.GetCoordinate().y; ++h) {
            for (size_t w = 0; w < width; ++w) {
                cout << 0;
            }
            cout << endl;
        }
        cout << setfill('0');
        for (size_t h = window.GetCoordinate().y; h < window.GetCoordinate().y + window.GetHeight(); ++h) {
            cout << setw(1 + window.GetCoordinate().x);
            for (size_t w = 0; w < window.GetWidth(); ++w) {
                cout << 1;
            }
            for (size_t w = window.GetWidth() + window.GetCoordinate().x; w < width; ++w) {
                cout << 0;
            }
            cout << endl;
        }
        for (size_t h = window.GetCoordinate().y + window.GetHeight(); h < height; ++h) {
            for (size_t w = 0; w < width; ++w) {
                cout << 0;
            }
            cout << endl;
        }
    }

private:
    const int height;
    const int width;
};

int main() {
    Display display;
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
            display.PrintWindow(window);
        } else cout << "Unknown command" << endl;
    }
    return 0;
}
