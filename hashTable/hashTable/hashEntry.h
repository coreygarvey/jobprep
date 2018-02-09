/* Corey Garvey - July 5
 * Hash Table - Entry Headers */

class HashEntry{
    private:
        int key;
        int value;
    public:
        HashEntry(int key, int value);
        
        int getKey();
        int getValue();
};
