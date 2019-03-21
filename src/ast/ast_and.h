#ifndef AST_AND_H
#define AST_AND_H


/*
**Author souleymane.ba
**function for ast_and.c
*/

struct ast_node_compound_list *create_node_and(struct ast_node_compound_list
                                               *lhs,
                                                struct ast_node_compound_list
                                               *rhs);


//print

void ast_and_print(struct ast_node_compound_list *node, FILE *out,
                  unsigned int *node_id);

/*
** Destruct node
*/

void ast_and_destruct_node(struct ast_node_compound_list *node);


/*
** Destruct ast_and
*/
void ast_and_destruct(struct ast_node_compound_list *node);


#endif
