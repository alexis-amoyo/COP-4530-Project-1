#include <iostream>
#include <string>
#include <vector>
#include "NSequence.h"
#include "FunClassTemp.h"
#include "Cell.h"

using namespace std;

int main( )
{
    NSequence <int>     v1 (0);
    for( int i = 0; i < v1.getSize(); i++ ) {
	    v1[i] = i+11;
    }
    for( int i = 0; i < 15; i++ ) {
	    v1.push_back(4*i+4);
    }
    for( int i = 0; i < v1.getSize(); i+=2 ) {
        
	    v1.remove(i);
    }

    for( int i = 0; i < v1.getSize(); i+=3 ) {
	    v1.insert(i, 6*i + 6);
    }

    cout << "NSequence of <int> has "<< v1.getSize() << " items:";
    v1.printout(0, v1.getSize() - 1);


    int begin = 0;
    int sub = longestSubseq_Cubic<int>(v1, 45, 20, &begin);
    cout << "Cubic func found "<< sub << " items:";
    v1.printout(begin, begin+sub -1 );

    //cout << "kimchi" << endl;

    begin = 0;
    sub = longestSubseq_Quad <int>(v1, 45, 20, &begin);
    cout << "Quadratic func found "<< sub << " items:";
    v1.printout(begin, begin+sub -1 );

    //cout << "udon" << endl;

    begin = 0;
    sub = longestSubseq_Log<int>(v1, 45, 20, &begin);
    cout << "Log func found "<< sub << " items:";
    v1.printout(begin, begin+sub -1 ); 

    //cout << "ramen" << endl;

    return 0;
    
    return 0;
}