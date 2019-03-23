#include "ast.h"
/*Check if the text is a list */
int read_list(struct parser_s *p)
{
    int tmp = p->cursor;
  if (read_and_or(p) && ZeroOrMany(read_spaces(p)) && 
      (ZeroOrMany(parser_readinset(p, ";&") && ZeroOrMany(read_spaces(p)) &&
        read_and_or(p))) && (ZeroOrOne(parser_readinset(p, ";&"))))
    {
      printf("AST LIST Success \n");
      return 1;
    }
    p->cursor = tmp;
  printf("AST LIst FAil \n");
  return 0;

}