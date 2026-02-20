#include "vect2.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Vect2 Test ===" << std::endl;

    // Test constructors
    vect2 a(2, 3);
    vect2 b(4, 5);
    vect2 c;    // default (0, 0)
    vect2 d(1); // (1, 0)

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    // Test addition
    std::cout << "\n=== Addition Tests ===" << std::endl;
    vect2 sum = a + b;
    std::cout << a << " + " << b << " = " << sum << std::endl;
    std::cout << "Expected: {6, 8}" << std::endl;

    // Test subtraction
    std::cout << "\n=== Subtraction Tests ===" << std::endl;
    vect2 diff = a - b;
    std::cout << a << " - " << b << " = " << diff << std::endl;
    std::cout << "Expected: {-2, -2}" << std::endl;

    // Test scalar multiplication (subject example)
    std::cout << "\n=== Scalar Multiplication Tests ===" << std::endl;
    vect2 v1(2, 2);
    vect2 result = v1 * 2;
    std::cout << v1 << " * 2 = " << result << std::endl;
    std::cout << "Expected: {4, 4}" << std::endl;
    std::cout << "Subject test (vect2(2,2) * 2 == vect2(4,4)): "
              << ((result[0] == 4 && result[1] == 4) ? "PASS" : "FAIL") << std::endl;

    // More scalar tests
    vect2 v2(3, -1);
    std::cout << v2 << " * 3 = " << (v2 * 3) << std::endl;
    std::cout << v2 << " * 0 = " << (v2 * 0) << std::endl;
    std::cout << v2 << " * -2 = " << (v2 * -2) << std::endl;

    // Test index operator []
    std::cout << "\n=== Index Operator Tests ===" << std::endl;
    vect2 v3(10, 20);
    std::cout << "v3 = " << v3 << std::endl;
    std::cout << "v3[0] = " << v3[0] << std::endl;
    std::cout << "v3[1] = " << v3[1] << std::endl;

    // Test modifying through index operator
    v3[0] = 100;
    v3[1] = 200;
    std::cout << "After v3[0] = 100, v3[1] = 200:" << std::endl;
    std::cout << "v3 = " << v3 << std::endl;

    // Test const index operator
    const vect2 v4(7, 8);
    std::cout << "const v4 = " << v4 << std::endl;
    std::cout << "v4[0] = " << v4[0] << ", v4[1] = " << v4[1] << std::endl;

    // Test output format exactly as specified in subject
    std::cout << "\n=== Output Format Test ===" << std::endl;
    vect2 v5(42, -13);
    std::cout << "Output format test: " << v5 << std::endl;
    std::cout << "Should match format: {42, -13}" << std::endl;

    // Test chain operations
    std::cout << "\n=== Chain Operations ===" << std::endl;
    vect2 v6(1, 2);
    vect2 v7(3, 4);
    vect2 v8(5, 6);

    vect2 chain_result = (v6 + v7) * 2 - v8;
    std::cout << "(" << v6 << " + " << v7 << ") * 2 - " << v8 << " = " << chain_result << std::endl;
    std::cout << "Step by step:" << std::endl;
    std::cout << "  " << v6 << " + " << v7 << " = " << (v6 + v7) << std::endl;
    std::cout << "  " << (v6 + v7) << " * 2 = " << ((v6 + v7) * 2) << std::endl;
    std::cout << "  " << ((v6 + v7) * 2) << " - " << v8 << " = " << chain_result << std::endl;

    std::cout << "\n=== All Tests Complete ===" << std::endl;
    return 0;
}