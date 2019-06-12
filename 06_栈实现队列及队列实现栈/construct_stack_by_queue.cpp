#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::cin;
using std::endl;


/**
 * 用两个队列实现一个栈
 */

template <typename T>
class CStack{
    public:
        CStack() = default;
        ~CStack() = default;

        //入栈
        void Push(T ele);

        //出栈
        T Pop();

        //获取栈顶元素
        T GetTop();
        
    private:
        queue<T> queue1;
        queue<T> queue2;
};

template <typename T>
void CStack<T>::Push(T ele){
    if(!queue1.empty()){
        queue1.push(ele);
    }else{
        queue2.push(ele);
    }
}

template <typename T>
T CStack<T>::Pop(){
    if(queue1.empty() && queue2.empty()){
        throw "Error: Stack is empty!";
    }
    T ele;
    if(!queue1.empty()){
        while(queue1.size() > 1){
            queue2.push(queue1.front());
            queue1.pop();
        }
        ele = queue1.front();
        queue1.pop();
    }else{
        while(queue2.size() > 1){
            queue1.push(queue2.front());
            queue2.pop();
        }
        ele = queue2.front();
        queue2.pop();
    }
    return ele;
}

template <typename T>
T CStack<T>::GetTop(){
    T ele;
    if(!queue1.empty()){
        ele = queue1.back();
    }else if(!queue2.empty()){
        ele = queue2.back();
    }else{
        throw "Error: Stack is empty!";
    }
    return ele;
}


int main(){
    
    CStack<int> s;

    try{
        while(true){
            cout<<"**********1-入栈  2-出栈  0-退出**********"<<endl;
            int n;
            cin>>n;
            if(n == 1){
                cout<<"请输入入栈的元素：";
                int num;
                cin>>num;
                s.Push(num);
            }else if(n == 2){
                int a = s.Pop();
                cout<<"出栈元素："<<a<<endl;
            }else if(n == 0){
                break;
            }else{
                cout<<"输入错误，请重新输入！"<<endl;
            }
        }
    }catch(const char *msg){
        cout<<msg<<endl;
    }

    return 0;
}
