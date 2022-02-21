struct Point {
    int x;
	int y;
};

int cmp_Point (const void* p1, const void* p2)
{
    struct Point* pt1 = (struct Point*)p1;
    struct Point* pt2 = (struct Point*)p2;
    return pt1->x*pt1->x + pt1->y*pt1->y - pt2->x*pt2->x - pt2->y*pt2->y;
}