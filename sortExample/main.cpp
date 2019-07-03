#include <iostream>
#include <vector>
#include <algorithm> // sort를 사용하기 위한 헤더

using namespace std;

template <typename T>
void print_vector(vector<T> &vec)
{
    for(typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
    {
        if(itr == vec.end() - 1)
            cout << *itr;
        else {
            cout << *itr << ",";
        }

    }
    cout << endl;
}

struct int_compare{
    bool operator()(const int& a, const int&b) const{
        return a>b;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    print_vector(vec);

    sort(vec.begin(), vec.end()); // 순서대로 정렬
    print_vector(vec);

    sort(vec.begin(), vec.end(), int_compare()); // 역순대로 정렬
    //sort(vec.begin(), vec.end(), greater<int>()); 다른 방법
    print_vector(vec);

    partial_sort(vec.begin(), vec.begin() + 2, vec.end());
    // 처음부터 세번까지 오름차순 정렬
    print_vector(vec);

    //vec.erase(vec.begin() + 3); // 네번째 자리(0, 1, 2, 3)의 값을 지운다.

    vec.erase(remove(vec.begin(), vec.end(), 3)); // 3을 지운다.
    print_vector(vec);

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);

    //벡터 홀수 제거를 위한 람다 함수
    vec.erase(remove_if(vec.begin(), vec.end(), [](int i) -> bool {return  1%2 == 1;}), vec.end() );
    print_vector(vec);


    return 0;
}
