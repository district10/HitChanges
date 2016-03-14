#include "Configs.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

int main ( int argc, char **argv )
{
    using namespace std;
    vector<int> indexes;

    bool markingInputFile = false;
    string csvFilePath = DATA_DIR "/20150702test.csv";
    if ( argc == 2 ) {
        csvFilePath = argv[1];
    } else if ( argc == 3 ) {
        csvFilePath = argv[1];
        markingInputFile = true;
    }

    string csvFile( csvFilePath );
    ifstream csv( csvFile.c_str() );
    if ( !csv.is_open() ) {
        return 1;
    }

    ofstream hitsIndex;
    hitsIndex.open( (csvFilePath + ".index.txt").c_str(), ios::out );
    if ( !hitsIndex.is_open() ) {
        return 1;
    }

    ofstream markedInput;
    if ( markingInputFile ) {
        markedInput.open( (csvFilePath + ".marked.txt").c_str(), ios::out );
        if ( !markedInput.is_open() || !hitsIndex.is_open() ) {
            return 1;
        }
    }

    string line;
    int cur = -1;
    int lst = -2;

    int curId = -1;
    int lstId = -2;

    int numLine = 0;
    int numHits = 0;
    while ( getline( csv, line ) ) {

        ++numLine;
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
            ++numHits;
            indexes.push_back( numLine );
            // hitsIndex << numLine << endl;
            if ( markingInputFile ) {
                markedInput << line << "\t\t\t" << "hit" << endl;
            }
        } else {
            if ( markingInputFile ) {
                markedInput << line << endl;
            }
        }

        lstId = curId;
        lst = cur;
    }

    for ( int i = 0; i < indexes.size(); ++i ) {
        hitsIndex << indexes.at(i) << endl;
    }
    hitsIndex.close();
    if ( markingInputFile ) {
        markedInput.close();
    }
    cout << "Scanned " << numLine << " lines of file, #hits: " << numHits << endl;

    return 0;
}