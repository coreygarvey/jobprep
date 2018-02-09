/* Corey Garvey - July 6
 * Simple String Buffer - headers */
#include <string>
using namespace std;
class SimpleStringBuffer{
    public:
        // Below is for C++11
        //SimpleStringBuffer();
        // Default parameter given
        SimpleStringBuffer(int l = 16);
        ~SimpleStringBuffer();
        void append(string str);
        string toString();
    private:
        char* buffer;
        int capacity;
        int length;
};
