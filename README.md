Systems Programming 2 Ex2 @ Ariel University
@author : diaa monder

in this assigment we overload the operators we asked to overload.

explaination about each operator overload :

    Addition Operator (operator+):
        This operator is overloaded to perform addition between two graphs.
        It takes two Graph objects (g1 and g2) as operands and returns a new Graph object that represents the element-wise addition of their adjacency matrices.
        If the two graphs have different sizes, it outputs an error message and exits the program.
        It sets the Cycles flag of the resulting graph to true if either of the input graphs has cycles.
        It sets the NegativeCycles flag of the resulting graph to true if either of the input graphs has negative cycles.

    Addition Assignment Operator (operator+=):
        This operator is overloaded to perform addition assignment between two graphs.
        It takes two Graph objects (g1 and g2) as operands and modifies g1 by adding the elements of g2 to it.
        If the two graphs have different sizes, it outputs an error message and exits the program.

    Unary Plus Operator (operator+):
        This operator is overloaded to return the graph itself.
        It simply returns the input Graph object g.

    Subtraction Operator (operator-):
        This operator is overloaded to perform subtraction between two graphs.
        It takes two Graph objects (g1 and g2) as operands and returns a new Graph object that represents the element-wise subtraction of g2 from g1.
        If the two graphs have different sizes, it outputs an error message and exits the program.
        It sets the Cycles flag of the resulting graph to true if either of the input graphs has cycles.
        It sets the NegativeCycles flag of the resulting graph to true if either of the input graphs has negative cycles.

    Subtraction Assignment Operator (operator-=):
        This operator is overloaded to perform subtraction assignment between two graphs.
        It takes two Graph objects (g1 and g2) as operands and modifies g1 by subtracting the elements of g2 from it.
        If the two graphs have different sizes, it outputs an error message and exits the program.

    Unary Minus Operator (operator-):
        This operator is overloaded to return the graph itself.
        It simply returns the input Graph object g.

    Equality Operator (operator==):
        This operator is overloaded to compare two graphs for equality.
        It returns true if the sizes and corresponding elements of the adjacency matrices of the two graphs are equal; otherwise, it returns false.

    Less Than Operator (operator<):
        This operator is overloaded to compare two graphs.
        It returns true if the number of vertices in g1 is less than the number of vertices in g2, or if the number of vertices is equal but the number of edges in g1 is less than in g2; otherwise, it returns false.

    Greater Than Operator (operator>):
        This operator is overloaded to compare two graphs.
        It returns true if the number of vertices in g1 is greater than the number of vertices in g2, or if the number of vertices is equal but the number of edges in g1 is greater than in g2; otherwise, it returns false.

    Less Than or Equal To Operator (operator<=):
        This operator is overloaded to compare two graphs.
        It returns true if either g1 < g2 or g1 == g2; otherwise, it returns false.

    Greater Than or Equal To Operator (operator>=):
        This operator is overloaded to compare two graphs.
        It returns true if either g1 > g2 or g1 == g2; otherwise, it returns false.

    Inequality Operator (operator!=):
        This operator is overloaded to compare two graphs for inequality.
        It returns the negation of the result of the equality comparison (operator==).

    Prefix Increment Operator (operator++):
        This operator is overloaded to increment all non-zero elements of the adjacency matrix of the graph g by 1.

    Prefix Decrement Operator (operator--):
        This operator is overloaded to decrement all non-zero elements of the adjacency matrix of the graph g by 1.

    Multiplication Assignment Operator (operator*=):
        This operator is overloaded to multiply all elements of the adjacency matrix of the graph g by a scalar value s.

    Division Assignment Operator (operator/=):
        This operator is overloaded to divide all elements of the adjacency matrix of the graph g by a scalar value s.

    Multiplication Operator (operator*):
        This operator is overloaded to perform matrix multiplication between two graphs.
        It takes two Graph objects (g1 and g2) as operands and returns a new Graph object that represents the result of multiplying the adjacency matrices of g1 and g2.
        If the two graphs have different sizes, it outputs an error message and exits the program.
        It sets the Cycles flag of the resulting graph to true if either of the input graphs has cycles.
        It sets the NegativeCycles flag of the resulting graph to true if either of the input graphs has negative cycles.

    Stream Insertion Operator (operator<<):
        This operator is overloaded to output the adjacency matrix of the graph g to an output stream out in a human-readable format.
