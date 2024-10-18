#include <iostream>
#include <vector>

class Prostoe {
private:
    uint64_t limit;
    std::vector<bool> simple;
public:
    Prostoe(uint64_t n) : limit(n), simple(n + 1, true) {
        simple[0] = false;
        simple[1] = false;
    }
    std::vector<uint64_t> GetPriority() {
        for (uint64_t p = 2; p * p <= limit; p++) {
            if (simple[p]) {
                for (uint64_t multiple = p * p; multiple <= limit; multiple += p) {
                    simple[multiple] = false;
                }
            }
        }
        
        std::vector<uint64_t> answer;
        for (uint64_t i = 2; i <= limit; i++) {
            if (simple[i]) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};

int main() {
    uint64_t n;
    std::cout << "Введите число n: ";
    std::cin >> n;

    Prostoe prostie(n);
    std::vector<uint64_t> answer = prostie.GetPriority();
    
    std::cout << "Простые числа от 2 до " << n << ":\n";
    for ( uint64_t i = 0 ; i < answer.size() ; i ++) {
        std::cout << answer[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}