#include<iostream>
using namespace std;
class node_buffer
{
	public:
	// 构造函数
	// 参数: max_size 指定缓冲的最大节点数
	node_buffer(int max_size):m_max_size(max_size),m_front(0),m_back(0),m_size(0)
	{
		m_queue = new int[m_max_size];
	};

	// 析构函数
	~node_buffer(){};

	// 从队尾插入一个数据节点
	// 参数：i 待插入节点
	// 返回值：true 插入成功
	//         false 插入失败，表示数据节点个数达到最大值
	bool push_back(int i)
	{
		if(m_back >= m_max_size)
			return false;
		m_queue[m_back] = i;
		m_back += 1; 
		return true;
		
	};

	// 从队首移除一个数据节点
	// 返回值：true 移除成功
	//         false 移除失败，表示数据节点个数为0
	bool pop_front()
	{
		if(m_back == m_front)
			return false;
		m_queue += 1;
		m_back -= 1;
		return true;
	};

	// 获取队首节点值，不移除数据
	int front()
	{
		// if(m_back == m_front)
		// {
		// 	// cout<<"queue is null"<<endl;
		// 	return 0;
		// } 
		return m_queue[m_front];
	};

	// 获取队尾节点值，不移除数据
	int back()
	{
		// if(m_back == m_front)
		// {
		// 	// cout<<"queue is null"<<endl;
		// 	return 0;
		// } 
		return m_queue[m_back - 1];
	};

	// 获取数据节点数量
	// 返回值：数据节点数量
	int size()
	{
		return m_back - m_front; //> 0? m_back - m_front : 0;
	};
	private:
	int* m_queue;
	int  m_max_size;
	int  m_front;
	int  m_back;
	int  m_size;
};
int main()
{
	int T,K,M,N;
	cin>>T;
	while(T>0)
	{
		//指定最大节点数K
		cin>>K;
		if(K <= 0)
		{
			// cout<<"K should lager 0"<<endl;
			return 0;
		}
		node_buffer nodeBuffer(K);
		//插入节点数量
		cin>>M;
		// if(M < 0)
		// {
		// 	cout<<"M should lager or equal 0"<<endl;
		// 	return 0;
		// }
		//插入节点的值
		int *value = new int[M];
		for(int i = 0; i < M; ++i)
		{
			cin>>value[i];
		}
		
		//插入节点
		for(int i = 0; i < M; ++i)
		{
			if(!nodeBuffer.push_back(value[i]))
				break;
		}	
		//移除节点数量
		cin>>N;
		// if(N < 0)
		// {
		// 	cout<<"M should lager or equal 0"<<endl;
		// 	return 0;
		// }
		//移除节点
		for(int i = 0; i < N; ++i)
		{
			if(!nodeBuffer.pop_front())
				break;
		}
		//输出剩余节点
		int now_size = nodeBuffer.size();
		for(int i = 0; i < now_size-1; ++i)
		{
			cout<<nodeBuffer.front()<<" ";
			if(!nodeBuffer.pop_front())
				break;		
		}
		if(now_size > 0)
			cout<<nodeBuffer.front()<<endl;
		T--;
		// delete [] value;
	}
	return 0;
}