#include "test.h"

void test_INPUT()
{
  char *str[] = 
    {
      "",
      "until ! a=15 b=569 15 < kergjkergerklg 16 < jsdhvjsdfhvs | uhhvhbrb=15 15 < zrevjzrjvjerv do a=15 | JE=45 15 < WORDfadde 30 < wfvkfdkvndfkbv 15 < fdjkbhdfbjekbej 10< WORD && ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada ! a=1 b=2 || ! a=5 15 < toto ; ! WORD=10 b=50 15 < dada done",
    };
  /* struct parser_s *p = parser_new_from_string(str[0]);
     assert(read_pipeline(p) == 1); */
  struct parser_s *p1= parser_new_from_string(str[1]);
  assert(read_input(p1) == 1);
  printf("%s \n", p1->input);
  print_node(p1->nodes);
}