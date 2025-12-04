#include <stdio.h>

typedef struct InnerMap {
    int des;
    int count;
    struct InnerMap* next;
} InnerMap;

typedef struct Map {
    int key;
    InnerMap* inner;
    struct Map* next;
} Map;


#define HASH_SIZE 10007

Map* hash_table[HASH_SIZE];

int gcd(int a, int b) {
    if (b == 0) return a > 0 ? a : -a;
    return gcd(b, a % b);
}

int abs_val(int x) { return x < 0 ? -x : x; }

InnerMap* find_inner(InnerMap* head, int des) {
    while (head) {
        if (head->des == des) return head;
        head = head->next;
    }
    return NULL;
}

Map* find_map(Map* head, int key) {
    while (head) {
        if (head->key == key) return head;
        head = head->next;
    }
    return NULL;
}

void add(Map** table, int key, int des) {
    int idx = key % HASH_SIZE;
    if (idx < 0) idx += HASH_SIZE;

    Map* m = find_map(table[idx], key);
    if (!m) {
        m = malloc(sizeof(Map));
        m->key = key;
        m->inner = NULL;
        m->next = table[idx];
        table[idx] = m;
    }

    InnerMap* inner = find_inner(m->inner, des);
    if (!inner) {
        inner = malloc(sizeof(InnerMap));
        inner->des = des;
        inner->count = 1;
        inner->next = m->inner;
        m->inner = inner;
    } else {
        inner->count++;
    }
}

long count(Map** table) {
    long ans = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Map* m = table[i];
        while (m) {
            int total = 0;
            for (InnerMap* in = m->inner; in; in = in->next) total += in->count;
            int rem = total;
            for (InnerMap* in = m->inner; in; in = in->next) {
                rem -= in->count;
                ans += (long)in->count * rem;
            }
            m = m->next;
        }
    }
    return ans;
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    
    Map* t[HASH_SIZE] = {0};
    Map* v[HASH_SIZE] = {0};

    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            int dx = x2 - x1;
            int dy = y2 - y1;

            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            int g = gcd(dx, abs_val(dy));
            int sx = dx / g;
            int sy = dy / g;
            int des = sx * y1 - sy * x1;

            int key1 = (sx << 12) | (sy + 2000);
            int key2 = (dx << 12) | (dy + 2000);

            add(t, key1, des);
            add(v, key2, des);
        }
    }

    long result = count(t) - count(v)/2;
    return (int)result;
}