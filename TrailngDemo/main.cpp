#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
template <class T, class X>
auto add(X a, T b) -> decltype(a+b)  {
    return a + b;
}

auto Foo()-> double {
    return 42.0;
}

int main() {

    auto z = add(1,3.0);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.