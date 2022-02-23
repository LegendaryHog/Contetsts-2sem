char* my_strdup (const char* str)
{
    size_t len = strlen (str);
    char* str_dup = (char*) calloc (len + 1, sizeof (char));
    for (size_t i = 0; i < len; i++)
    {
        str_dup[i] = str[i];
    }
    return str_dup;
}