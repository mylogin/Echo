## Example
```cpp
#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <iostream>

#include "echo.hpp"

int main() {
    
    bool _bool = true;
    int _int = 1;
    float _float = 2.2f;
    double _double = 3.3;
    char _char = 'a';
    const char* _carr[] = {"carr"};
    const char* _cstr = "cstr";
    std::string _str{"str"};
    std::tuple _tuple{"tuple"};
    std::vector _vector_bool{true};
    std::vector _vector{"vector"};
    std::array _arr{"arr"};
    std::deque _deque{"deque"};
    std::forward_list _forward_list{"forward_list"};
    std::list _list{"list"};
    std::set _set{"set"};
    std::multiset _multiset{"multiset"};
    std::map<std::string, std::string> _map{{"map", "map"}};
    std::multimap<std::string, std::string> _multimap{{"multimap", "multimap"}};
    std::vector _nested{std::pair{std::tuple{"nested"}, std::tuple{"tuple"}}};

    std::cout << echo::str(
        _bool,
        _int,
        _float,
        _double,
        _char,
        _carr,
        _cstr,
        _str,
        _tuple,
        _vector_bool,
        _vector,
        _arr,
        _deque,
        _forward_list,
        _list,
        _set,
        _multiset,
        _map,
        _multimap,
        _nested
    );

    return 0;
}
```