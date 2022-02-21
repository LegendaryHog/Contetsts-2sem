int foo2 (int * px, int * py)
{
    (*px)++;
    (*py)--;
    printf ("foo2 : res=%d x=%d y=%d\n", *px + *py, *px, *py);
    return *px + *py;
}