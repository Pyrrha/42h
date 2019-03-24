/**
 ** \file test_ELEMENT.c
 */
#include "test.h"
/**
 ** \brief test unit for element Grammar
 */
void test_ELEMENT()
{
  char *str[] =
    {
      "WORD",
      "12        <      WORD",
      "a=15 b=16 c=17 word word2 word3"
      "a=15 fsnvsfvn skdvjsfdjkv sdkvnjdsv skdvjdsk"
    };
  struct parser_s *p = parser_new_from_string(str[1]);
  assert(read_element(p) == 1);
  /*
    while(p->capture)
    {
    printf("%s\n", p->capture->tag);
    p->capture = p->capture->next;
    }*/
}
