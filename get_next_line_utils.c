#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *accumulation) {
        size_t i = 0;
        while (accumulation[i] != '\0')
                i++;
        return i;
}

char    *ft_strjoin(char *accumulation, char *s2)
{
        char    *string;
        size_t  s_len;
        size_t  s1_len;
        size_t  s2_len;

        if (!s2)
                return (NULL);
        s1_len = 0;
        if (accumulation)
                s1_len = ft_strlen(accumulation);
        s2_len = ft_strlen(s2);
        s_len = s1_len + s2_len;
        string = malloc((s_len + 1) * sizeof(char));
        if (!string)
                return (NULL);
        if (accumulation)
        {
                ft_strlcpy(string, accumulation, s1_len + 1);
                free(accumulation);
        }
        ft_strlcpy(string + s1_len, s2, s2_len + 1);
        // free(s2);
        return (string);
}

char    *ft_strdup(const char *s1)
{
        char    *string;
        size_t  len;
        size_t  i;

        i = 0;
        len = ft_strlen(s1) + 1;
        string = malloc(len * sizeof(char));
        if (!string)
                return (NULL);
        while (s1[i])
        {
                string[i] = s1[i];
                i++;
        }
        string[i] = '\0';
        return (string);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  dst_len;
        size_t  src_len;

        // if (!dst && dstsize == 0)
        //         return (ft_strlen(src));
        dst_len = ft_strlen(dst);
        src_len = ft_strlen(src);
        i = 0;
        // if (dstsize <= dst_len)
        //         return (dstsize + src_len);
        while (src[i] != '\0' && dst_len + i < dstsize - 1)
        {
                dst[dst_len + i] = src[i];
                i++;
        }
        dst[dst_len + i] = '\0';
        return (dst_len + src_len);//the actual size for stash 
}
//we have changed size_t ot int
int  ft_strchr(const char *accumulation, int c)
{
        int i;

        i = 0;
        while (accumulation[i])
        {
                if (accumulation[i] == c)
                        return i;
                i++;
        }
        return (-1);
}

// char    *ft_strchr(const char *s, int c)
// {
//         char    ch;
//         int             i;

//         i = 0;
//         ch = (char)c;
//         while (s[i])
//         {
//                 if (ch == s[i])
//                         return ((char *)(s + i));
//                 i++;
//         }
//         if (ch == '\0')
//                 return ((char *)(s + i));
//         return (NULL);
// }

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize) {
        size_t i;
        size_t srcsize = 0;

        while (src[srcsize] != '\0')
                srcsize++;
        if (dstsize == 0)
                return srcsize;
        i = 0;
        while (i < dstsize - 1 && src[i] != '\0') {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return srcsize;
}

char *ft_substr(char *accumulation, unsigned int start, size_t len)
{
        size_t acc_len;
        size_t final;
        char *sub;

        if (!accumulation)
                return NULL;
        acc_len = ft_strlen(accumulation);
        final = acc_len - start;
        if (final > len)
                final = len;   
        sub = malloc((final + 1) * sizeof(char));
        if (!sub)
                return NULL;
        ft_strlcpy(sub, accumulation + start, final + 1);
        // if(ft_strchr(accumulation, '\n'))
                // free(accumulation);
        return sub;
}