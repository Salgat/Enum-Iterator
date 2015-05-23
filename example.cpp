#include <iostream>
#include <string>

#include "enumit.hpp"


enum class SampleId {
    FIRST,
    SECOND,
    THIRD
};

/*
enum SampleId {
    FIRST,
    SECOND,
    THIRD
};*/

int main() {
    for (auto iter = enumit::Begin<SampleId>(); iter != enumit::End<SampleId>(SampleId::THIRD); ++iter) {
        SampleId entry = *iter;
        std::cout << "Current SampleId: " << static_cast<int>(entry) << std::endl;
    }

    for (auto entry : enumit::Iterate<SampleId>(SampleId::THIRD)) {
        std::cout << "Current SampleId: " << static_cast<int>(entry) << std::endl;
    }

    return 0;
}