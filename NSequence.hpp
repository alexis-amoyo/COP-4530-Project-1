using namespace std;

//default constructor
template<typename T>
NSequence<T>::NSequence( int initSize ){
    if(initSize <= 0){
        numOfItems = 1;
    }
    else{
        numOfItems = initSize;
    }
    totalCapacity = 5;
    items = new T[totalCapacity];
    //cout << totalCapacity << endl << numOfItems << endl;
}

//copy constructor
template<typename T>
NSequence<T>::NSequence( const NSequence<T>& rhs )
    : numOfItems(rhs.numOfItems), totalCapacity(rhs.totalCapacity), items(nullptr){
    items = new T[totalCapacity];
    for(int k = 0; k < numOfItems; k++){
        items[k] = rhs.items[k];
    }
}

//copy assignment op
template<typename T> 
NSequence<T>& NSequence<T>::operator=(const NSequence<T>& rhs){
    if(this != &rhs){
        delete [] items;
        //numOfItems = numOfItems.size;
        //totalCapacity = v.totalCapacity;
        //items = new T[totalCapacity];

        //for(int i = 0; i < size; i++){
        //    items[i] = rhs.items[i];
        //}
        NSequence<T> copy = rhs;
        std::swap(*this, copy);
    }
    return *this;
}

//destructor
template<typename T> 
NSequence<T>::~NSequence(){
    delete [] items;
}

//move constructor
template<typename T> 
NSequence<T>::NSequence( NSequence<T>&& rhs ){
    rhs.items = nullptr;
    //std::swap(capacity, rhs.capactiy);
    //std::swap(numOfItems, rhs.numOfItems);
}

//move assignment op
template<typename T> 
NSequence<T>& NSequence<T>::operator=( NSequence<T>&& rhs ){
    std::swap(totalCapacity, rhs.totalCapacity);
    std::swap(numOfItems, rhs.numOfItems);
    std::swap(items, rhs.items);
    return *this;
}
    
template<typename T> 
bool NSequence<T>::isEmpty( ) const{
    if(numOfItems == 0)
        return true;
    else
        return false;
}

template<typename T> 
int NSequence<T>::getSize( ) const{
    return numOfItems;
}
    
template<typename T> 
int NSequence<T>::getCapacity( ) const{
    return totalCapacity;
}

template<typename T> 
T& NSequence<T>::operator[]( int index ){
    //cout << "yo" << endl;
    //cout << items[index] << endl;
    return items[index];
}

template<typename T>
const T& NSequence<T>::operator[]( int index ) const{
    //cout << "yolo" << endl;
    //cout << items[index] << endl;
    return items[index];
}

template<typename T> 
T& NSequence<T>::getFirst ( ) const{
    return items[0];
}
    
template<typename T> 
T& NSequence<T>::getLast ( ) const{
    return items[numOfItems-1];
}

// insert data element d just before item at pos position
template<typename T> 
void NSequence<T>::insert(const int pos, const T& d){
    if(pos < numOfItems){
        if(numOfItems == totalCapacity){
            growCapacity(2 * totalCapacity);
        }
        if(pos >= 0 && pos < numOfItems && pos < totalCapacity && numOfItems > 0){
            for(int i = numOfItems; i > pos; i--)
            {
                items[i] = items[i-1];
            }
            items[pos] = d;
            numOfItems++;
        }
        else{
            items[numOfItems] = d;
            numOfItems++;
        }
    }
    else{
        push_back(d);
    }
} // copy semantics

template<typename T> 
void NSequence<T>::insert(const int pos, T&& d){
    if(numOfItems == totalCapacity){
        growCapacity(2 * totalCapacity + 1);
    }
    if(pos >= 0 && pos < numOfItems && pos < totalCapacity && numOfItems > 0){
        for(int i = numOfItems; i > pos; i--){
            items[i] = std::move(items[i-1]);
        }
        items[pos] = std::move(d);
        numOfItems++;
   }
   else{
        push_back(d);
    }
    
} // move semantics

template<typename T> 
void NSequence<T>::remove(const int pos){
    if(numOfItems > 0){
        for(int i = pos; i < numOfItems - 1; i++){
            items[i] = items[i+1];
        }
        numOfItems--;
    }
} // remove item at pos position

template<typename T> 
void NSequence<T>::push_back( const T& x ){
    if(numOfItems > 0){
        if(numOfItems == totalCapacity){
            growCapacity(2 * totalCapacity + 1);
        }
        items[numOfItems] = x;
        numOfItems++;
        //cout << "Internal: " << numOfItems << endl;
    }
} //copy semantics, insert at the end

template<typename T> 
void NSequence<T>::push_back( T&& x ){
    if(numOfItems > 0){
        if(numOfItems == totalCapacity){
            growCapacity(2 * totalCapacity + 1);
        }
        items[numOfItems] = std::move(x);
        numOfItems++;
        //cout << "Internal: " << numOfItems << endl;
    }
} // move semantics, insert at the end

template<typename T> 
void NSequence<T>::pop_back( ){
    if(numOfItems > 0){
        --numOfItems;
    }
} // delete the last element

/* Grow the totalCapacity by newCapacity, double if zero input provided) */
template<typename T> 
void NSequence<T>::growCapacity(int newCapacity){
    T* temp = new T[newCapacity];

    for(int i = 0; i < numOfItems && i < newCapacity; i++){
        temp[i] = items[i];
    }

    totalCapacity = newCapacity;

    if(numOfItems > totalCapacity){
        numOfItems = totalCapacity;
    }
    delete [] items;
    items = temp;
}

/* print out the items from begin to end, up to 50 if too many */
template<typename T> 
void NSequence<T>::printout(int begin, int end){
    for(int i = begin; i <= end && i <= 50; i++){
        cout << "\t[" << i << "]=" << items[i];
    }
    cout << endl;
}