#include "grammar.h"
/*
simple_command: 
    (prefix)+ | (prefix)* (element)+
*/
int read_simple_command(struct parser_s *p)
{
  int tmp = p->cursor;
  if ((OneOrMany(read_prefix(p)) && ZeroOrMany(read_element(p))) || (ZeroOrMany(read_prefix(p)) && OneOrMany(read_element(p))))
  {
    FILE *file = fopen("ast.txt", "w+");
    struct s_simple_cmd *s_cmd = init_simple_command(p);
    fprintf(file, "AST {\n");
    fprintf(file, "    node [fontname=\"Arial\"];\n");
    
    while(find_assign(p, s_cmd)|| find_redir(p, s_cmd) || find_word(p, s_cmd));

    /*dot*/
    for (int i = 0; i < s_cmd->child; i++)
    {
      fprintf(file,  "    %d -> %d;\n", s_cmd->type, s_cmd->child_node[i].type); 
    }
    fprintf(file, "}\n");
    printf("AST SIMPLE COMMAND SUCCESS\n");
    return 1;
  }
  printf("AST SIMPLE COMMAND FAIL !!!!!!!!!!!!!!!\n");
  p->cursor = tmp;
  return 0;
}
