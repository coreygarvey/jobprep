/* Corey Garvey - July 5 */
/* Dynamic Array Headers */

class DynamicArray {
    public:
        DynamicArray();
        DynamicArray(int initSize);
        DynamicArray(const DynamicArray &original);
        ~DynamicArray();

        void insert(int position, int value);
        int get(int position);
        int getSize();
        void resize();
        
        int &operator[](int index);
        bool operator==(DynamicArray);
        bool operator!=(DynamicArray);

    private:
        int *array;
        int size;
};
