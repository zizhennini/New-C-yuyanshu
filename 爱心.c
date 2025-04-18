#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 640
#define CANVAS_CENTER_X (CANVAS_WIDTH / 2)
#define CANVAS_CENTER_Y (CANVAS_HEIGHT / 2)
#define IMAGE_ENLARGE 11
#define SCATTER_BETA 0.15f
#define SHRINK_RATIO 15
#define CURVE_RATIO 10
#define FRAME_DELAY 160
#define NUM_POINTS 2000
#define NUM_HALO_POINTS 3000
#define MAX_POINTS 100000
#define GENERATE_FRAMES 20

typedef struct {
    Vector2 point;
    int size;
} HeartPoint;

typedef struct {
    HeartPoint* points;
    int count;
} HeartFrame;

typedef struct {
    HeartPoint* all_points;
    int points_count;
    HeartFrame frames[GENERATE_FRAMES];
} HeartParameters;

Vector2 heart_function(float t, float shrink_ratio) {
    Vector2 result;
    result.x = 16 * pow(sinf(t), 3);
    result.y = -(13 * cosf(t) - 5 * cosf(2 * t) - 2 * cosf(3 * t) - cosf(4 * t));
    result.x *= shrink_ratio;
    result.y *= shrink_ratio;
    result.x += CANVAS_CENTER_X;
    result.y += CANVAS_CENTER_Y;
    return result;
}

Vector2 scatter_points(Vector2 point, float beta) {
    Vector2 result;
    float ratio_x = -beta * logf((float)rand() / RAND_MAX);
    float ratio_y = -beta * logf((float)rand() / RAND_MAX);
    float dx = ratio_x * (point.x - CANVAS_CENTER_X);
    float dy = ratio_y * (point.y - CANVAS_CENTER_Y);
    result.x = point.x - dx;
    result.y = point.y - dy;
    return result;
}

Vector2 shrink_points(Vector2 point, float ratio) {
    Vector2 result;
    float force = -1.0f / powf(powf(point.x - CANVAS_CENTER_X, 2) + powf(point.y - CANVAS_CENTER_Y, 2), 0.6f);
    float dx = ratio * force * (point.x - CANVAS_CENTER_X);
    float dy = ratio * force * (point.y - CANVAS_CENTER_Y);
    result.x = point.x - dx;
    result.y = point.y - dy;
    return result;
}

float curve(float p) {
    return 2 * (3 * sinf(4 * p)) / (2 * PI);
}

Vector2 calc_position(Vector2 point, float ratio) {
    Vector2 result;
    float force = 1.0f / powf(powf(point.x - CANVAS_CENTER_X, 2) + powf(point.y - CANVAS_CENTER_Y, 2), 0.52f);
    float dx = ratio * force * (point.x - CANVAS_CENTER_X) + (rand() % 3 - 1);
    float dy = ratio * force * (point.y - CANVAS_CENTER_Y) + (rand() % 3 - 1);
    result.x = point.x - dx;
    result.y = point.y - dy;
    return result;
}

void build_heart(HeartParameters* params) {
    // Initialize points
    params->all_points = (HeartPoint*)malloc(MAX_POINTS * sizeof(HeartPoint));
    params->points_count = 0;

    // Generate base points
    for (int i = 0; i < NUM_POINTS; i++) {
        float t = (float)rand() / RAND_MAX * 2 * PI;
        Vector2 p = heart_function(t, IMAGE_ENLARGE);
        params->all_points[params->points_count++] = (HeartPoint){ p, 1 };
    }

    // Generate edge diffusion points
    for (int i = 0; i < NUM_POINTS * 3; i++) {
        int idx = rand() % params->points_count;
        Vector2 p = params->all_points[idx].point;
        Vector2 scattered = scatter_points(p, SCATTER_BETA);
        params->all_points[params->points_count++] = (HeartPoint){ scattered, 1 };
    }

    // Generate center diffusion points
    for (int i = 0; i < NUM_HALO_POINTS; i++) {
        int idx = rand() % NUM_POINTS;
        Vector2 p = params->all_points[idx].point;
        Vector2 scattered = scatter_points(p, 0.17f);
        params->all_points[params->points_count++] = (HeartPoint){ scattered, 1 };
    }
}

void calculate_frames(HeartParameters* params) {
    for (int frame = 0; frame < GENERATE_FRAMES; frame++) {
        HeartFrame* f = &params->frames[frame];
        f->points = (HeartPoint*)malloc(MAX_POINTS * sizeof(HeartPoint));
        f->count = 0;

        float ratio = CURVE_RATIO * curve(frame / 10.0f * PI);
        int halo_radius = (int)(4 + 6 * (1 + curve(frame / 10.0f * PI)));
        int halo_number = (int)(3000 + 4000 * fabs(pow(curve(frame / 10.0f * PI), 2)));

        // Generate halo points
        for (int i = 0; i < halo_number; i++) {
            float t = (float)rand() / RAND_MAX * 2 * PI;
            Vector2 p = heart_function(t, SHRINK_RATIO);
            p = shrink_points(p, halo_radius);
            p.x += rand() % 29 - 14;
            p.y += rand() % 29 - 14;
            f->points[f->count++] = (HeartPoint){ p, (rand() % 3) + 1 };
        }

        // Process other points
        for (int i = 0; i < params->points_count; i++) {
            Vector2 new_p = calc_position(params->all_points[i].point, ratio);
            int size = (rand() % 3) + 1;
            f->points[f->count++] = (HeartPoint){ new_p, size };
        }
    }
}

int main(void) {
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Heart Animation");
    SetTargetFPS(60);
    srand(time(NULL));

    HeartParameters params = { 0 };
    build_heart(&params);
    calculate_frames(&params);

    int current_frame = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw current frame
        HeartFrame* f = &params.frames[current_frame % GENERATE_FRAMES];
        for (int i = 0; i < f->count; i++) {
            HeartPoint p = f->points[i];
            Color color = (p.size == 2) ? PINK : RED;
            DrawRectangle(p.point.x, p.point.y, p.size, p.size, color);
        }

        EndDrawing();
        current_frame++;
        WaitTime(FRAME_DELAY / 1000.0f);
    }

    // Cleanup
    for (int i = 0; i < GENERATE_FRAMES; i++) {
        free(params.frames[i].points);
    }
    free(params.all_points);
    CloseWindow();
    return 0;
}
//