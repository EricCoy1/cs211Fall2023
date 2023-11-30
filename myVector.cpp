#include <iostream>
using namespace std;

template <class T>
class myVector{
  //friend void print(const myVector<int> v);
private:
  T* ar;
  int num;
public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T& operator[](int index) const;
  void erase(int index);
  void insert(int index, const T& e);
};

template <class T>
void print(const myVector<T>& v);

int main(){

  myVector<int> v;
  int size;
  v.push_back(34);
  v.push_back(25);
  v.push_back(37);
  v.push_back(60);
  v.push_back(90);
  v.push_back(44);
  size = v.size();
  cout << size << " " << v[4] << endl;
  print(v);
  v.erase(2);
  v.erase(5);
  size = v.size();
  cout << size << " " << v[2] << endl;
  print(v);
  v.insert(2, 77);
  v.insert(7,90);
  size = v.size();
  cout << size << " " << v[1] << endl;
  print(v);

  int newvalue = 17;
  v[0] = newvalue;
  cout << v[0];

  return 0;
}


template <class T>
myVector<T>::myVector(){
  ar = NULL;
  num = 0;
}

template <class T>
myVector<T>::~myVector(){
  if(ar != NULL)
    delete [] ar;
}

template <class T>
void myVector<T>::push_back(const T& e){
  T* arNew = new T[num + 1];
  for(int i = 0; i < num; i++){
    *(arNew + i) = *(ar + i);
  }
  *(arNew + num) = e;
  num++;
  if(ar != NULL)
    delete []ar;
  ar = arNew;
}


template <class T>
int myVector<T>::size() const{
  int size;
  size = num;
  return size;
}

template <class T>
T& myVector<T>::operator[](int index) const{
  return *(ar + index);
}

template <class T>
void print(const myVector<T>& v){
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

template<class T>
void myVector<T>::erase(int index){
  if(index >= 0 && index < num){
    T* arNew = new T [num - 1];
    for(int i = 0; i < index; i++){
      *(arNew + i) = *(ar + i);
    }
    *(arNew + index) = *(ar + index + 1);
    for(int i = num - 1; i > index; i--){
      arNew[i - 1] = ar[i];
    }
    num--;
    if(ar != NULL)
      delete [] ar;
    ar = arNew;
    cout << "element erased\n";
  } else 
    cout << "Illegal index\n";
}

template <class T>
void myVector<T>::insert(int index, const T& e){
  //T*arNew = new T [num + 1];
  if(index >= num + 1)
    cout << "Illegal Index\n";
  else{
    T* arNew = new T [num + 1]; 
    for(int i = 0; i < index; i++){
      *(arNew + i) = *(ar + i);
    }
    *(arNew + index) = e;
    for(int i = num - 1; i > index; i--){
      arNew[index + 1] = ar[i - 1];
    }
    num++;
    if(ar != NULL)
      delete []ar;
    ar = arNew;
    cout << "Element added\n";
  }
}
