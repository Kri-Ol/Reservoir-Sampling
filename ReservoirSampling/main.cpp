#include <iostream>
#include <random>
#include <vector>

#define func auto

static int N = 0;
static int s = 0;

func next_item() -> int // emulate incoming with the stream
{
    if (s == N) // all values are streamed
        return -1;

    return s++;
}


func RS(int k) -> std::vector<int>
{
    std::vector<int> result;

    std::mt19937_64 rng(987654321);

    int sp = 0; // position in the stream

    for ( ;; )
    {
        int v = next_item();
        if (v < 0)
            break;
        if (sp < k)
            result.push_back(v);
        else
        {
            std::uniform_int_distribution<int> uni(0, sp);
            int idx = uni(rng);
            if (idx < k)
                result[idx] = v;
        }
        ++sp;
    }
    return result;
}


func main() -> int
{
    s = 0;
    N = 10000;
    auto v = RS(10);
    for (auto e : v)
    {
        std::cout << e << "\n";
    }
    std::cin >> s;
    return 0;
}
