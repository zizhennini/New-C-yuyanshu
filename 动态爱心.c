#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <cstdlib>

struct Point { 
    double x, y;
    COLORREF color; 
};

const int MAX_POINTS = 256; 
const COLORREF colors[MAX_POINTS] = { 
    RGB(255, 192, 203), // 浅粉色 (Light Pink)    
    RGB(255, 182, 193), // 淡粉红 (LightPink)    
    RGB(255, 105, 180), // 热粉红 (HotPink)    
    RGB(255, 20, 147),  // 深粉色 (DeepPink)    
    RGB(219, 112, 147), // 浓粉红 (PaleVioletRed)    
    RGB(255, 174, 185), // 浅玫瑰红 (LightPink)    
    RGB(255, 0, 144)    // 紫红色 (Crimson)
};
const int xScreen = GetSystemMetrics(SM_CXSCREEN);
const int yScreen = GetSystemMetrics(SM_CYSCREEN) - 100;
const double PI = 3.14159265359;
const double E = 2.71828;
const double AVG_DISTANCE = 0.162;
const int NUM_ORIGIN_POINTS = 506;
const int NUM_CIRCLES = 210;
const int NUM_FRAMES = 20;
const int COLOR_RANGE = 6;

Point origin_points[NUM_ORIGIN_POINTS]; 
Point points[NUM_CIRCLES * NUM_ORIGIN_POINTS]; 
IMAGE images[NUM_FRAMES];

int create_random(int min, int max) { 
    return rand() % (max - min + 1) + min; 
}

void create_data() {
    int index = 0;    
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    // Generate origin points    
    for (double radian = 0.1; radian <= 2 * PI; radian += 0.005) {        
        x2 = 16 * pow(sin(radian), 3);        
        y2 = 13 * cos(radian) - 5 * cos(2 * radian) - 2 * cos(3 * radian) - cos(4 * radian);        
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));        
        if (distance > AVG_DISTANCE) {            
            x1 = x2, y1 = y2;            
            origin_points[index].x = x2;            
            origin_points[index++].y = y2;        
        }    
    }

    // Generate points    
    index = 0;    
    for (double size = 0.1, lightness = 1.5; size <= 20; size += 0.1) {        
        double success_p = 1 / (1 + pow(E, 8 - size / 2));        
        if (lightness > 1) lightness -= 0.0025;        
        for (int i = 0; i < NUM_ORIGIN_POINTS; ++i) {            
            if (success_p > create_random(0, 100) / 100.0) {                
                COLORREF color = colors[create_random(0, COLOR_RANGE)];                
                points[index].color = RGB(GetRValue(color) / lightness, GetGValue(color) / lightness, GetBValue(color) / lightness);                
                points[index].x = size * origin_points[i].x + create_random(-4, 4);                
                points[index++].y = size * origin_points[i].y + create_random(-4, 4);            
            }        
        }    
    }    
    int points_size = index;

    // Generate images    
    for (int frame = 0; frame < NUM_FRAMES; ++frame) {        
        images[frame] = IMAGE(xScreen, yScreen);        
        SetWorkingImage(&images[frame]);        
        setorigin(xScreen / 2, yScreen / 2);        
        setaspectratio(1, -1);

        for (index = 0; index < points_size; ++index) { 
            double x = points[index].x, y = points[index].y;            
            double distance = sqrt(pow(x, 2) + pow(y, 2));            
            double distance_increase = -0.0009 * distance * distance + 0.35714 * distance + 5;            
            double x_increase = distance_increase * x / distance / NUM_FRAMES;            
            double y_increase = distance_increase * y / distance / NUM_FRAMES;            
            points[index].x += x_increase;            points[index].y += y_increase;            
            setfillcolor(points[index].color);            
            solidcircle(points[index].x, points[index].y, 1); 
        }

        
        for (double size = 17; size < 23; size += 0.3) { 
            for (index = 0; index < NUM_ORIGIN_POINTS; ++index) { 
                if ((create_random(0, 100) / 100.0 > 0.6 && size >= 20) || (size < 20 && create_random(0, 100) / 100.0 > 0.95)) { 
                    double x, y;                    
                    if (size >= 20) { 
                        x = origin_points[index].x * size + create_random(-frame * frame / 5 - 15, frame * frame / 5 + 15);                        
                        y = origin_points[index].y * size + create_random(-frame * frame / 5 - 15, frame * frame / 5 + 15); 
                    } 
                    else { 
                        x = origin_points[index].x * size + create_random(-5, 5);                        
                        y = origin_points[index].y * size + create_random(-5, 5); 
                    }                    
                    setfillcolor(colors[create_random(0, COLOR_RANGE)]);                    
                    solidcircle(x, y, 1); 
                } 
            } 
        }

        setaspectratio(1, 1);        
        settextstyle(100, 0, _T("宋体"));        
        settextcolor(RGB(219, 112, 147));        
        outtextxy(-150, -50, _T("我爱你"));

        saveimage(_T("爱心.png"), &images[frame]);        
        setorigin(0, 0);        
        setaspectratio(1, 1);        
        loadimage(&images[frame], _T("爱心.png"));
    }    
    SetWorkingImage(); 
}

void init_graphics() { 
    HWND hwnd = initgraph(xScreen, yScreen);    
    RECT rect;    
    SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);    
    ShowWindow(hwnd, SW_MAXIMIZE);    
    SetWindowPos(hwnd, HWND_TOP, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);    
    BeginBatchDraw();    
    setorigin(xScreen / 2, yScreen / 2);    
    setaspectratio(1, -1);    
    srand(static_cast<unsigned>(time(0))); 
}

int main() { 
    init_graphics();    
    create_data();    
    graphdefaults();    
    bool extend = true, shrink = false;    
    for (int frame = 0; !_kbhit();) { 
        putimage(0, 0, &images[frame]);        
        FlushBatchDraw();        
        Sleep(20);        
        cleardevice();        
        if (extend)            
            frame == 19 ? (shrink = true, extend = false) : ++frame;        
        else            
            frame == 0 ? (shrink = false, extend = true) : --frame; 
    }    
    EndBatchDraw();    
    closegraph();    
    return 0; 
}