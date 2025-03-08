//다음 코드는 뉴턴의 방법을 사용하여 함수의 근을 찾습니다.f(x) = e ^ 2x - 1 - 2 다음 두 섹션을 채워 코드를 완성하세요
//
//값은 함수를 e ^ x 통해 계산할 수 있습니다.Math.exp() 그리고 뉴턴의 방법에 대한 위키피디아를 참조 할 수 도 있습니다.
//
//참고사항: 명접 중에 주어진 함수의 미분을 수학적으로 어떻게 유도했는지 질문 받을 수 도 있으니, 이를 설명할 준비를 하세요
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cctype>
/** The function whose root we are trying to find: f(x) = e^(2x - 1) - 2 */
function f(x) {
    return Math.exp(2 * x - 1) - 2
}

/** The derivative of the function */
function f_prime(x) {
    return // TODO: here
}

/** The maximum number of iterations to compute */
const max_iterations = 100;
/** Do not divide by a number smaller than this */
const epsilon = Number.EPSILON;
/** Stop when iterations change by less than this */
const tolerance = Number.EPSILON;

/** The initial guess */
let x_0 = 1

for (let i = 0; i < max_iterations; i++) {
    const y = f(x_0)
        const y_prime = f_prime(x_0)

        console.log(`x_${i
} = ${ x_0 }\t->y = ${ y }`)

// Give up if the denominator is too small
if (Math.abs(y_prime) < epsilon) {
    break
}

    // Do Newton's computation
    let x_1 = // TODO: here

        // Stop when the result is within the desired tolerance
        // x_1 is a solution within tolerance and maximum number of
        if (Math.abs(x_1 - x_0) < tolerance) {
            break
        }

    // Update x0 to start the process again
    x_0 = x_1
}

// OUTPUT:
// x_0 = 1    -> y = 0.7182818284590451
// x_1 = 0.8678794411714423    -> y = 0.08706522863453303
// x_2 = 0.8470211499594577    -> y = 0.0017910401957283995
// x_3 = 0.8465737905298857    -> y = 8.009998127000983e-7
// x_4 = 0.8465735902800127    -> y = 1.5987211554602254e-13
// x_5 = 0.8465735902799727    -> y = 0