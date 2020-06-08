//
// Created by zale on 2020/6/8.
//


// 在c++的函数里面，如果把一个数组作为参数传进去，那么这个数组就会退化为一个指针，因而就不知道这个数组的长度
// 使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
template<class T>
int getArrayLen(T& array){
    return sizeof(array)/ sizeof(array[0]);
}