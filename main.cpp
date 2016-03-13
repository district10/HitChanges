#include "Configs.h"

#include <iostream>
#include <fstream>
#include <string>

int main ( int argc, char **argv )
{
    using namespace std;

    bool writeHits = false;
    string fpath = DATA_DIR "/20150702test.csv";
    if ( argc >= 2 ) {
        fpath = argv[1];
    } else if ( argc >= 3 ) {
        writeHits = true;
    }

    string data( fpath );
    ifstream in( data.c_str() );
    if ( !in.is_open() ) {
        return 1;
    }

    ofstream of;
    ofstream ofIdx;
    of.open( (fpath + ".out.txt").c_str(), ios::out );
    ofIdx.open( (fpath + ".outIdx.txt").c_str(), ios::out );
    if ( !of.is_open() || !ofIdx.is_open() ) {
        return 1;
    }

    string line;
    int cur = -1;
    int lst = -2;

    int curId = -1;
    int lstId = -2;
    bool inited = false;

    int num = 0;
    int hits = 0;
    while ( getline( in, line ) ) {

        ++num;
        if ( false ) {
        } else if ( 0 == strcmp( line.c_str()+line.length()-1, "0" ) ) {
            cur = 0;
        } else if ( 0 == strcmp( line.c_str()+line.length()-1, "1" ) ) {
            cur = 1;
        } else {
            continue;
        }

        sscanf( line.c_str(), "%d", &curId );
        if ( curId == lstId && cur != lst ) {
            ++hits;
            if ( writeHits ) {
                of << line << "\t\t\t" << "hit" << endl;
            }
            ofIdx << num << endl;
        } else {
            if ( writeHits ) {
                of << line << endl;
            }
        }

        lstId = curId;
        lst = cur;
    }

    of.close();
    ofIdx.close();
    cout << "Scanned " << num << " lines of file, #hits: " << hits << endl;

    return 0;
}
