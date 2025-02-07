//
// Created by 김석찬 on 2023/04/26.
//

//
// Created by 김석찬 on 2022/06/08.
//
//알고리즘 수행시간은 deleteMax 과정에서 vacant가 변경될 때마다 1초가 소요되는 것으로 계산, 최대 힙 자료구조 생성시간을
// 포함한 다른 연산의 수행시간은 고려 X
// 초기에 root에서 vacant로 변경되는 것도 1초가 소요된다고 가정
// 모든 지원원의 시험점수는 중복이 되지 않는다.

// 각 질의마다 최대힙을 생서, 인덱스 1부터 N까지 모든 원소들의 정보를 공백으로 구분해서 한줄에 출력
// 각 질의별로 알고리즘의 수행시간을 출력한다.
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class MaxHeap{
private:
    vector<int> arr;
    int vacant;
    int height;

    void swap(int idx1, int idx2, bool can){ // 들어오는 index 두개의 값을 서로 swap한다.
        if(can)vacant+=1; // can이 true일때는 swap이 일어날때마다 vacant의 값을 증가한다.
        int temp=arr[idx1];
        arr[idx1]=arr[idx2];
        arr[idx2]=temp;
    }

    void bubbleUpheap(int idx){
        if(idx==1)return;  // root인 경우

        int parent=idx/2;  //부모의 인덱스를 구함
        if(arr[idx]>arr[parent]){ //부모의 값이 자식보다 작으면 바꿔값을 바꿔주고 bubbleupheap을 호출한다.
            swap(idx,parent,ok);
            bubbleUpheap(parent);
        }
    }

    void fixHeap(int idx){ // 기존 maxheap구조를 만들기 위해서 사용

        int left=idx*2;  // 왼쪽 자식
        int right=idx*2+1; // 오른쪽 자식
        int child; // 더 큰값을 가지고 있는 자식

        if(left>size()) // 범위를 초과
            return;
        else if(left==size()) //완쪽자식이 마지막 끝 노드이다.
            child=left;
        else{
            if(arr[left]>=arr[right]){ // 왼쪾자식의 key값이 오른쪽 자식보다 크다.
                child=left;
            }
            else{ // 오른쪽 자식의 key값이 왼쪽 자식보다 크다.
                child=right;
            }
        }
        if(arr[child]>arr[idx]){ // 자식의 key값이 부모의 key값보다 클경우 swap을 해준다.
            swap(child,idx,ok);
            fixHeap(child); // swap을 해주고 다시 한번 밑으로 내려가서 비교를 해준다.
        }
    }

public:
    int ok;
    MaxHeap();
    int size();
    bool empty();
    void insert(int i);
    void pop();
    void print();
    void makeheight();
    void constructheap(int idx);
    int promote(int idx, int h, int hStop);
    void FixHeapFast(int idx,int h);
};

int main(){
    int T;
    cin>>T;
    while(T--){
        MaxHeap v1;
        int N,num;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>num;
            v1.insert(num);
        }
        v1.constructheap(1);
        v1.ok=true;
        v1.makeheight();
        v1.print();
    }
}


MaxHeap::MaxHeap() {
    arr.push_back(0);
    vacant=0;
    ok=false;
}

void MaxHeap::makeheight(){ //,,, 높이에 따른 전체 수를 나누어서 높이를 구해준다.. ㅎㅎ..
    if(size()>524287){
        height=19;
    }
    else if(size()>262143){
        height=18;
    }
    else if(size()>131071){
        height=17;
    }
    else if(size()>65535){
        height=16;
    }
    else if(size()>32767){
        height=15;
    }
    else if(size()>16383){
        height=14;
    }
    else if(size()>8191){
        height=13;
    }
    else if(size()>4095){
        height=12;
    }
    else if(size()>2047){
        height=11;
    }
    else if(size()>1023){
        height=10;
    }
    else if(size()>511){
        height=9;
    }
    else if(size()>255){
        height=8;
    }
    else if(size()>127){
        height=7;
    }
    else if(size()>63){
        height=6;
    }
    else if(size()>31){
        height=5;
    }
    else if(size()>15){
        height=4;
    }
    else if(size()>7){
        height=3;
    }
    else if(size()>3){
        height=2;
    }
    else if(size()>1){
        height=1;
    }
    else{height=0;}
}

int MaxHeap::size() {
    return arr.size()-1;
}

bool MaxHeap::empty() {
    return (size()==0);
}



void MaxHeap::pop() {
    if(empty()){
        return;
    }
    swap(1,size(),ok); // 마지막 노드와 root를 바꾸어준다.vacant값 root로 이동
    arr.pop_back(); // delete를 해줌
    makeheight(); // 전체의 높이를 수정
    FixHeapFast(1,height); // fixHeapfast로 수행시간을 빠르게 해준다.
}

void MaxHeap::insert(int i) {
    arr.push_back(i); // 값을 집어넣어준다.
}

void MaxHeap::print() {

    for(int i=1; i<size()+1; i++){
        cout<<arr[i]<<" "; //Maxheap을 출력해준다.
    }
    cout<<'\n';

    int number=size(); // 전체 크기만큼 delete후 정렬해준다.
    for(int i=0; i<number; i++){
        pop(); // delete max를 해준다.
    }
    cout<<vacant-1<<'\n';
}

void MaxHeap::constructheap(int idx) { // 재귀를 이용해서 heap구조를 만들고 합쳐서 heap구조를 만들어줌다.
    if(idx*2>size()){
        return;
    }else{
        constructheap(idx*2);
        constructheap((idx*2)+1);
        fixHeap(idx);
    }
}

int MaxHeap::promote(int idx, int h, int hStop) { // hstop까지 내려가준다.
    int vacStop;
    if(idx*2>size())return idx; // 만약 idx가 leaf라면 return해준다.
    if(h<=hStop){ // hstop만큼 내려가 주었으면 idx를 반환한다.
        vacStop=idx;
    }
    else if(arr[idx*2]<arr[(idx*2)+1]){ // 오른쪽 자식이 좀더 크면 오른쪽으로 내려간다.
        swap(idx,2*idx+1,ok);
        vacStop= promote(2*idx+1,h-1,hStop);
    }
    else{
        swap(idx,2*idx,ok); // 왼쪽 자식이 더 크면 왼쪽으로 내려간다.
        vacStop= promote(2*idx,h-1,hStop);
    }
    return vacStop;
}

void MaxHeap::FixHeapFast(int idx,int h) { // idx를 받고 h만큼 내려간다.
    if(h==0 || h==1){ // 높이가 0이나 1까지 내려갔으면 남은 것을 heap구조로 만들고 return한다.
        fixHeap(idx);
        return;
    }
    int hStop=h/2; // 다음promote가 멈출 지점을 정해준다.
    int vacStop= promote(idx,h,hStop); // promote로 h/2만큼 내려가서 멈춘 인덱스를 가져와준다.
    int vacParent=vacStop/2; // 멈춘 지점의 부모 index를 구한다.
    if(arr[vacStop]>arr[vacParent]){ // key값을 비교한후 부모의 key값이 높으면 fixheapfast를 호출
        bubbleUpheap(vacStop); // 작으면 bubbleupheap을 해준다.
    }
    else{
        FixHeapFast(vacStop,hStop);
    }
}