#include <windows.h>
#include <cmath>
#include <ctime>

const int WIDTH = 800;
const int HEIGHT = 600;
const double PI = 3.141592653589793;

// 三维心形方程
bool isHeart(double x, double y, double z) {
    return pow(x * x + 2.25 * y * y + z * z - 1, 3)
        - x * x * z * z * z - 0.1125 * y * y * z * z * z < 0;
}

// 三维坐标旋转
void rotate3D(double& x, double& y, double& z, double angleX, double angleY) {
    double temp = y * cos(angleX) - z * sin(angleX);
    z = y * sin(angleX) + z * cos(angleX);
    y = temp;

    temp = x * cos(angleY) + z * sin(angleY);
    z = -x * sin(angleY) + z * cos(angleY);
    x = temp;
}

// 窗口过程函数
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static double angle = 0;
    static POINT pts[2000];
    static int colorPhase = 0;

    switch (msg) {
    case WM_CREATE: {
        // 初始化随机点
        srand(time(0));
        for (int i = 0; i < 2000; i++) {
            pts[i].x = rand() % WIDTH;
            pts[i].y = rand() % HEIGHT;
        }
        SetTimer(hWnd, 1, 30, NULL);
        break;
    }

    case WM_TIMER: {
        InvalidateRect(hWnd, NULL, TRUE);
        angle += 0.05;
        colorPhase = (colorPhase + 1) % 360;
        break;
    }

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 双缓冲绘图
        HDC memDC = CreateCompatibleDC(hdc);
        HBITMAP hBmp = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
        SelectObject(memDC, hBmp);

        // 背景色
        HBRUSH bgBrush = CreateSolidBrush(RGB(0, 0, 40));
        FillRect(memDC, &ps.rcPaint, bgBrush);
        DeleteObject(bgBrush);

        // 绘制动态粒子
        for (int i = 0; i < 2000; i++) {
            int alpha = rand() % 155 + 100;
            SetPixel(memDC, pts[i].x, pts[i].y, RGB(alpha, alpha, alpha));
            pts[i].x = (pts[i].x + rand() % 3 - 1 + WIDTH) % WIDTH;
            pts[i].y = (pts[i].y + rand() % 3 - 1 + HEIGHT) % HEIGHT;
        }

        // 绘制3D爱心
        for (double scale = 10; scale < 16; scale += 0.4) {
            for (int x = -30; x <= 30; x++) {
                for (int y = -30; y <= 30; y++) {
                    double px = x / 10.0, py = y / 10.0, pz = 0;
                    rotate3D(px, py, pz, angle * 1.2, angle * 0.8);

                    if (isHeart(px, py, pz)) {
                        int color = (int)(scale * 15 + colorPhase) % 360;
                        int r = (int)(sin(color / 180.0 * PI) * 255);
                        int g = (int)(sin((color + 120) / 180.0 * PI) * 255);
                        int b = (int)(sin((color + 240) / 180.0 * PI) * 255);

                        SetPixel(memDC,
                            WIDTH / 2 + (int)(px * scale * 15),
                            HEIGHT / 2 - (int)(py * scale * 15),
                            RGB(abs(r), abs(g), abs(b))
                        );
                    }
                }
            }
        }

        // 绘制文字
        LOGFONT lf = { 0 };
        lf.lfHeight = 48;
        lf.lfWeight = FW_BOLD;
        wcscpy(lf.lfFaceName, L"Arial");
        HFONT hFont = CreateFontIndirect(&lf);
        SelectObject(memDC, hFont);

        SetTextColor(memDC, RGB(255, 105, 180));
        TextOutW(memDC, WIDTH / 2 - 100, HEIGHT - 80, L"Love C++", 8);

        // 输出到屏幕
        BitBlt(hdc, 0, 0, WIDTH, HEIGHT, memDC, 0, 0, SRCCOPY);

        // 清理资源
        DeleteObject(hFont);
        DeleteObject(hBmp);
        DeleteDC(memDC);
        EndPaint(hWnd, &ps);
        break;
    }

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

// 主函数
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow) {
    // 注册窗口类
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"HeartWindow";
    RegisterClassEx(&wc);

    // 创建窗口
    HWND hWnd = CreateWindow(
        L"HeartWindow", L"3D Love Heart",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WIDTH, HEIGHT,
        NULL, NULL, hInst, NULL
    );

    // 显示窗口
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}