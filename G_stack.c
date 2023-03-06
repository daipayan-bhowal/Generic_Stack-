#include <assert.h>

#define Stack( stack_type, STACK_SIZE, STACK_OBJ )         \
struct st_node_##STACK_OBJ {                                \                          \
     stack_type stack[ STACK_SIZE ];                      \
     int top_element;                                    \
 };                                                       \
  struct st_node_##STACK_OBJ STACK_OBJ;                      \
  STACK_OBJ.top_element = -1;                              \
int STACK_OBJ##_is_empty( void )                           \
{                                                       \
return STACK_OBJ.top_element == -1;                       \
}                                                       \
                                                        \
int STACK_OBJ##_is_full( void )                             \
{                                                       \
return STACK_OBJ.top_element == STACK_SIZE - 1;           \
}                                                       \
                                                        \
void STACK_OBJ##_push( stack_type value )                   \
{                                                       \
    assert( !STACK_OBJ##_is_full() );                       \
     STACK_OBJ.top_element += 1;                          \
     STACK_OBJ.stack[ STACK_OBJ.top_element ] = value;           \
}                                                       \
                                                        \
void STACK_OBJ##_pop(  )                                \
{                                                       \
    assert( !STACK_OBJ##_is_empty() );                      \
    STACK_OBJ.top_element -= 1;                 \
}                                                       \
                                                        \
stack_type STACK_OBJ##_top( void )                          \
{                                                       \
   assert( !STACK_OBJ##_is_empty() );                       \
   return STACK_OBJ.stack[ STACK_OBJ.top_element ];         \
}
#include <stdio.h>
int main()
{
    Stack(int,10,mystack);
    mystack_push(1);
    mystack_push(2);
    Stack(int,10,yourstack);
    yourstack_push(4);
    yourstack_push(5);
    yourstack_pop();
    printf("%d\n", yourstack_top());
		
}

