bool isOverflow(long long a, long long b)
{
    if(a == 0 || b == 0) return false;

    if(a > LLONG_MAX / b)
        return true;

    return false;
}
