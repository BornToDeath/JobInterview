#include <iostream>
#include <stdexcept>
#include <stack>

using std::cout;
using std::endl;
using std::cin;
using std::exception;
using std::stack;

/**
 * 使用两个栈构建队列
 */

//模板
template <typename T> 
class CQueue{
    public:
        //注意：构造函数和析构函数必须写大括号或default，否则报“undefined reference错误”
        CQueue(void) = default;
        ~CQueue(void){};
        
        //向队列中添加元素
        void AppendTail(const T &node);

        //删除元素
        T DeleteHead();

    private:
        stack<T> stack1;
        stack<T> stack2;
};


template<typename T> 
void CQueue<T>::AppendTail(const T &node){
    stack1.push(node);
}

template<typename T> 
T CQueue<T>::DeleteHead(){
    if(stack2.empty()){
        while(!stack1.empty()){
            T &temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        } 
    }
    if(stack2.empty()){
        //std::logic_error ex("Error: Queue is empty!");
        //throw exception(ex); 
        throw "Error: Queue is empty!";
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}



int main(){
    CQueue<int> q;
    try{
        while(true){
            cout<<"----------1-插入  2-删除  0-退出---------"<<endl;
            int num;
            cin>>num;
            if(num == 1){
                cout<<"请输入插入的元素的值：";
                int n;
                cin>>n;
                q.AppendTail(n);
            }else if(num == 2){
                int n = q.DeleteHead();
                cout<<"删除元素："<<n<<endl;
            }else if(num == 0){
                break;
            }
        }
    }catch(const char *msg){
        cout<<msg<<endl;
    }
    //catch(const exception &e){
    //    std::cout<<e.what()<<endl;
    //}

    return 0;
}
