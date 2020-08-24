#include <iostream>
#include <assert.h>
#include "colorcoder.h"

using namespace TelCoColorCoder;

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void ToString(){
    for(int pairno= 1; pairno < 26; pairno++){
        TelCoColorCoder::ColorPair pair = TelCoColorCoder::GetColorFromPairNumber(pairno);
        std::cout<<"Pair number: "<<pairno<<" "<<"Color Pair: "<<TelCoColorCoder::ToString()<<std::endl;
        //std::cout<<"Pair number: "<<pairno<<" "<<"Color Pair: "<<pair.getMajor()<<" "<<pair.getMinor()<<std::endl;
    }
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    
    ToString();
    return 0;
}
