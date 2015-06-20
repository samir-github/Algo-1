class Sorting {
public:

    // Sorts a sequence of integers.
    void sort(int* sequence, int size) {

    int min_element;
    int min_element_index;

    for(int i = 0; i < length-1; ++i){
        min_element = sequence[i];
        min_element_index = i;
        for(int j = i+1; j < length; ++j){
            if(sequence[j] < min_element){
                min_element = sequence[j];
                min_element_index = j;
            }
        }
        swap(sequence[i], sequence[min_element_index]);
    }

};
