#ifndef BOTTOMKLIST_H
#define BOTTOMKLIST_H
template<typename T, int k>
class BottomKList {
private:
    T* arr[k];
public:
    BottomKList()
    {
        for(int i = 0; i <k; i++){
            arr[i]= nullptr;
        }
    }
    ~BottomKList()
    {
        for(int i = 0; i <k; i++){
            delete arr[i];
        }
    }
    void addElement( T* element )
    {
        int instertion=k-1;
        while(instertion >=0 && (arr[instertion]==nullptr || *element<*arr[instertion])){
            instertion--;
        }
        for(int i=k-1;i>instertion+1;i--){
            swap(arr[i],arr[i-1]);
        }
        swap(arr[instertion+1],element);
    }
    T* getBottomXthElement ( int x ) const  
    {
        if(0<=x<k){
            return arr[x];
        }
        else{
            return nullptr;
        }
    }
};
#endif
