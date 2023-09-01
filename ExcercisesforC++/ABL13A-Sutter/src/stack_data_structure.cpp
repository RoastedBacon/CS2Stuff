
/*
================================================================================================#=
ABL13A-LastName
stack_data_structure.cpp
================================================================================================#=
*/


// =====================================================================================#=
// Stack Functions
// =====================================================================================#=

const int MAX_STACK_LEN = 32;


struct Stack 
{
    unsigned char stk[MAX_STACK_LEN];
    int top_idx;
    int max_len;
};

bool stack_is_empty(Stack& given_stack)
{
    if (given_stack.top_idx >= 0) return false;
   return true;
}

bool stack_is_not_empty(Stack& given_stack)
{
    return !stack_is_empty(given_stack);
}

bool stack_is_full(Stack& given_stack)
{
    if (given_stack.top_idx == MAX_STACK_LEN)
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool  stack_is_not_full(Stack& given_stack)
{
    if (given_stack.top_idx != MAX_STACK_LEN)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void stack_push(Stack& given_stack, char given_char)
{
    if (stack_is_not_full)
    {
        given_stack.stk[++given_stack.top_idx] = given_char;
    }
    else
    {
        cout << "Stack was actually full ";
    }
}

unsigned char  stack_peek(Stack& given_stack)
{
    return given_stack.stk[given_stack.top_idx];
}

unsigned char  stack_pop(Stack& given_stack)
{
    return given_stack.stk[given_stack.top_idx--];

}

void stack_clear(Stack& given_stack)
{
    given_stack.top_idx = -1;
}

std::string stack_to_string(Stack& given_stack)
{
    std::string return_str;
    char buffer[32];

    sprintf(buffer, "%+03d", given_stack.max_len);
    return_str += "[";
    return_str += buffer;
    return_str += "] ";

    int top= given_stack.top_idx;
    sprintf(buffer, "%+03d", top);
    return_str += "(";
    return_str += std::to_string(top);
    return_str += ") ";

    return_str += "|";
    for(int idx = 0; idx <= top; idx++)
    {
        return_str += " ";
        return_str += given_stack.stk[idx];
        
        if(idx < top)
        {
            return_str += ", ";
        }
    }
    return_str += "|";

    return return_str;
}


// =====================================================================================#=
// TEST CODE: Test Stack Functions
// =====================================================================================#=
void test_stack_functions(void)
{
    // -----------------------------------------------------+-
    // Create an Empty Stack.
    // We are responsible to initialize it properly.
    // -----------------------------------------------------+-
    Stack stack_under_test;
    stack_under_test.top_idx = -1;
    stack_under_test.max_len = 0;

    if(stack_is_empty(stack_under_test)) {
        std::cout << "Empty Stack: " << std::endl;
        std::cout << "    " << stack_to_string(stack_under_test) << std::endl;
    } else {
        throw std::runtime_error("Test Failed!");
    }

    // -----------------------------------------------------+-
    // Push chars until it's full.
    // -----------------------------------------------------+-
    char next_char_to_push = '0';
    char expected_char_at_top;

    std::cout << std::endl;
    std::cout << "Pushing onto stack... " << std::endl;
    while(stack_is_not_full(stack_under_test))
    {
        stack_push(stack_under_test, next_char_to_push);
        expected_char_at_top = next_char_to_push;

        char peek_elem = stack_peek(stack_under_test);
        assert(peek_elem == expected_char_at_top);

        std::cout << "    " << stack_to_string(stack_under_test);
        std::cout << " <= " << next_char_to_push << std::endl;
        next_char_to_push += 1;
    }

    // -----------------------------------------------------+-
    // Pop elements from stack until empty.
    // -----------------------------------------------------+-
    std::cout << std::endl;
    std::cout << "Popping from stack... " << std::endl;
    while(stack_is_not_empty(stack_under_test))
    {
        char peek_elem = stack_peek(stack_under_test);
        assert(peek_elem == expected_char_at_top);

        char pop_elem  = stack_pop(stack_under_test);
        assert(pop_elem == peek_elem);

        std::cout << "    " << stack_to_string(stack_under_test);
        std::cout << " => " << pop_elem << std::endl;
        expected_char_at_top -= 1;
    }
    return;
};


